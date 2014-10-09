#include "ConfigFile.h"
#include "Exceptions.h"
#include <fstream>
#include <iostream>
using namespace ARDTool;

ConfigFile::ConfigFile(std::string path) {
    std::ifstream confin(path.c_str());
    if(!confin) {
        throw FileException(path, "Could not open file");
    }
    _path = path;
    std::string parsestatus = "projectstart";
    Project* p = NULL;
    int linecount = 0;
    while(!confin.eof()) {
        linecount++;
        char c = ' ';
        std::string line = "";
        while(c != '\n' && confin) {
            c = confin.get();
            if(c != '\n') {
                line += c;
            }
        }
        if(confin) {
            if(parsestatus == "projectstart") {
                if(line[0] == '{' && line != "{end}") {
                    std::string parsedname = "";
                    for(int i = 1; i < line.length()-1; i++) {
                        parsedname += line[i];
                    }
                    p = new Project(parsedname);
                    parsestatus = "projectparse";
                } else {
                    std::cout << "CONFIG PARSER: Error in line " << linecount << ": Project definition start expected, got: " << line << "!" << std::endl;
                }
            } else if(parsestatus == "projectparse") {
                if(line[0] == '[') {
                    std::string parsedoption = "";
                    for(int i = 1; i < line.length()-1; i++) {
                        parsedoption += line[i];
                    }
                    if(parsedoption == "path" || parsedoption == "env" || parsedoption == "rvm" || parsedoption == "modules" || parsedoption == "custom") {
                        parsestatus = parsedoption;
                    } else {
                        std::cout << "CONFIG PARSER: Error in line " << linecount << ": Unknown project option: " << parsedoption << "! Skipping project..." << std::endl;
                        delete(p);
                        p = NULL;
                        parsestatus = "projectstart";
                    }
                } else if(line == "{end}") {
                    if(p->valid()) {
                        _projects.push_back(*p);
                        std::cout << "CONFIG PARSER: Adding project: " << p->getName() << std::endl;
                        delete(p);
                        p = NULL;
                    } else {
                        std::cout << "CONFIG PARSER: Got invalid project!" << std::endl;
                        delete(p);
                        p = NULL;
                    }
                    parsestatus = "projectstart";
                } else {
                    std::cout << "CONFIG PARSER: Error in line " << linecount << ": Project option expected, got: " << line << "! Skipping project..." << std::endl;
                    delete(p);
                    p = NULL;
                    parsestatus = "projectstart";
                }
            } else if(parsestatus == "path") {
                p->setPath(line);
                parsestatus = "projectparse";
            } else if(parsestatus == "env") {
                p->setEnv(line);
                parsestatus = "projectparse";
            } else if(parsestatus == "rvm") {
                p->setRVM(line);
                parsestatus = "projectparse";
            } else if(parsestatus == "modules") {
                if(line[0] != '[') {
                    try {
                        p->addModule(line);
                    } catch(InvalidModuleException& e) {
                        std::cout << "CONFIG PARSER: Error in line " << linecount << ": " << e.what() << std::endl;
                    }
                } else {
                    std::string parsedoption = "";
                    for(int i = 1; i < line.length()-1; i++) {
                        parsedoption += line[i];
                    }
                    if(parsedoption == "endmodules") {
                        parsestatus = "projectparse";
                    } else {
                        std::cout << "CONFIG PARSER: Error in line " << linecount << ": Endmodules expeted, got: " << parsedoption << "! Skipping project..." << std::endl;
                        delete(p);
                        p = NULL;
                        parsestatus = "projectstart";
                    }
                }
            } else if(parsestatus == "custom") {
                if(line[0] != '[') {
                    p->addCustom(line);
                } else {
                    std::string parsedoption = "";
                    for(int i = 1; i < line.length()-1; i++) {
                        parsedoption += line[i];
                    }
                    if(parsedoption == "endcustom") {
                        parsestatus = "projectparse";
                    } else {
                        std::cout << "CONFIG PARSER: Error in line " << linecount << ": Endcustom expeted, got: " << parsedoption << "! Skipping project..." << std::endl;
                        delete(p);
                        p = NULL;
                        parsestatus = "projectstart";
                    }
                }
            } else {
                std::cout << "CONFIG PARSER: Error in line " << linecount << ": Got unknown parse status: " << parsestatus << "!" << std::endl;
            }
        }
    }
    confin.close();
}

Project ConfigFile::getProjectByName(std::string name) {
    for(int i = 0; i < _projects.size(); i++) {
        if(_projects[i].getName() == name) {
            return _projects[i];
        }
    }
    Project p;
    return p;
}

std::string ConfigFile::getPath() {
    return _path;
}
