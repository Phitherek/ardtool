#include "ConfigFile.h"
#include "Project.h"
#include "Exceptions.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include <unistd.h>
using namespace std;
using namespace ARDTool;

void show_help(int argc, char** argv) {
    cout << "Usage: " << argv[0] << " <project_name|command>" << endl << endl;
    cout << "Available commands:" << endl;
    cout << "help - Shows this message" << endl;
}

int main(int argc, char** argv) {
    cout << "ARDTool v. 0.2 (C) 2014 by Phitherek_" << endl;
    if(argc == 2) {
        string arg1 = "";
        arg1 += argv[1];
        if(arg1 == "help") {
            show_help(argc, argv);
        } else {
            try {
                string home = getenv("HOME");
                string confpath = home;
                confpath += "/.ardtool/config";
                ConfigFile cf(confpath);
                Project p = cf.getProjectByName(argv[1]);
                if(!p.valid()) {
                    cout << "Could not find project " << argv[1] << " in the configuration! Exiting..." << endl;
                    exit(EXIT_FAILURE);
                } else {
                    cout << "Processing " << p.getName() << "..." << endl;
                    cout << "Changing directory to: " << p.getPath() << "..." << endl;
                    chdir(p.getPath().c_str());
                    cout << "Running in environment: " << p.getEnv() << "..." << endl;
                    string bundle_cmd = "bundle";
                    if(p.getRVM() != "") {
                        cout << "Using RVM environment: " << p.getRVM() << "..." << endl;
                        string rvm_path = getenv("rvm_path");
                        bundle_cmd = rvm_path;
                        bundle_cmd += "/wrappers/";
                        bundle_cmd += p.getRVM();
                        bundle_cmd += "/bundle";
                    }
                    while(!p.modulesEnd()) {
                        string modname = p.getNextModule();
                        cout << "Running module: " << modname << endl;
                        if(modname == "bundle") {
                            string cmd = "";
                            cmd += "RAILS_ENV=";
                            cmd += p.getEnv();
                            cmd += " ";
                            cmd += bundle_cmd;
                            cmd += " install";
                            cout << "Executing: " << cmd << endl;
                            system(cmd.c_str());
                        } else if(modname == "db") {
                            string cmd = "";
                            cmd += "RAILS_ENV=";
                            cmd += p.getEnv();
                            cmd += " ";
                            cmd += bundle_cmd;
                            cmd += " exec rake db:migrate";
                            cout << "Executing: " << cmd << endl;
                            system(cmd.c_str());
                        } else if(modname == "assets") {
                            string cmd = "";
                            cmd += "RAILS_ENV=";
                            cmd += p.getEnv();
                            cmd += " ";
                            cmd += bundle_cmd;
                            cmd += " exec rake assets:clean";
                            cout << "Executing: " << cmd << endl;
                            system(cmd.c_str());
                            cmd = "";
                            cmd += "RAILS_ENV=";
                            cmd += p.getEnv();
                            cmd += " ";
                            cmd += bundle_cmd;
                            cmd += " exec rake assets:precompile";
                            cout << "Executing: " << cmd << endl;                  
                            system(cmd.c_str());
                        } else if(modname == "restart") {
                            string cmd = "touch tmp/restart.txt";
                            cout << "Executing: " << cmd << endl;                  
                            system(cmd.c_str());
                        } else if(modname == "custom") {
                            while(!p.customEnd()) {
                                string cmd = p.getNextCustom();
                                cout << "Executing: " << cmd << endl;                  
                                system(cmd.c_str());
                            }
                        }
                    }
                }
            cout << "ARDTool finished!" << endl;
            } catch(exception& e) {
                cout << "Exception caught: " << e.what() << endl;
                exit(EXIT_FAILURE);
            }
        }
    } else {
        show_help(argc, argv);
    }
    return EXIT_SUCCESS;
}
