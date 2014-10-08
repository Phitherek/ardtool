#include "../ConfigFile.h"
#include "../Exceptions.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    try {
        ARDTool::ConfigFile cf("config.test");
        ARDTool::Project p = cf.getProjectByName("rails_project");
        if(!p.valid()) {
            cout << "No project of this name!" << endl;
        } else {
            cout << "Got project: " << endl;
            cout << "p.getName(): "  << p.getName() << endl << "p.getPath(): " << p.getPath()  << endl << "p.getEnv(): " << p.getEnv() << endl << "p.modulesEnd(): " << p.modulesEnd() << endl << "p.customEnd(): " << p.customEnd() << endl << "p.valid(): " << p.valid() << endl;
            cout << "Modules for p:" << endl;
            while(!p.modulesEnd()) {
                cout << p.getNextModule() << endl;
            }
            cout << "Custom commands for p:" << endl;
            while(!p.customEnd()) {
                cout << p.getNextCustom() << endl;
            }
        }
    } catch(exception& e) {
        cout << "Caught exception: " << e.what() << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
