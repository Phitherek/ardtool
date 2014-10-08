#include "../Project.h"
#include "../Exceptions.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    cout << "ARDTool Tests: ARDTool::Project" << endl;
    ARDTool::Project p1;
    ARDTool::Project p2("test");
    cout << "After construction..." << endl;
    cout << "p1.getName(): "  << p1.getName() << endl << "p1.getPath(): " << p1.getPath() << endl << "p1.getEnv(): " << p1.getEnv() << endl << "p1.modulesEnd(): " << p1.modulesEnd() << endl << "p1.customEnd(): " << p1.customEnd() << endl << "p1.valid(): " << p1.valid() << endl;
    cout << "p2.getName(): "  << p2.getName() << endl << "p2.getPath(): " << p2.getPath() << endl << "p2.getEnv(): " << p2.getEnv() << endl << "p2.modulesEnd(): " << p2.modulesEnd() << endl << "p2.customEnd(): " << p2.customEnd() << endl << "p2.valid(): " << p2.valid() << endl;
    p1.setName("testpre");
    p1.setEnv("production");
    p1.setPath("/some/path1");
    p2.setEnv("staging");
    p2.setPath("/some/path2");
    cout << "After name, path & env setup..." << endl;
    cout << "p1.getName(): "  << p1.getName() << endl << "p1.getPath(): " << p1.getPath()  << endl << "p1.getEnv(): " << p1.getEnv() << endl << "p1.modulesEnd(): " << p1.modulesEnd() << endl << "p1.customEnd(): " << p1.customEnd() << endl << "p1.valid(): " << p1.valid() << endl;
    cout << "p2.getName(): "  << p2.getName() << endl << "p2.getPath(): " << p2.getPath() << endl << "p2.getEnv(): " << p2.getEnv() << endl << "p2.modulesEnd(): " << p2.modulesEnd() << endl << "p2.customEnd(): " << p2.customEnd() << endl << "p2.valid(): " << p2.valid() << endl;
    p1.addModule("bundle");
    p1.addModule("db");
    p1.addModule("-assets");
    p1.addModule("restart");
    p1.addCustom("service sidekiq restart");
    cout << "After module & custom adding to p1..." << endl;
    cout << "p1.getName(): "  << p1.getName() << endl << "p1.getPath(): " << p1.getPath()  << endl << "p1.getEnv(): " << p1.getEnv() << endl << "p1.modulesEnd(): " << p1.modulesEnd() << endl << "p1.customEnd(): " << p1.customEnd() << endl << "p1.valid(): " << p1.valid() << endl;
    try {
        p2.addModule("test");
        cout << "Failure: No InvalidModuleException!" << endl;
    } catch(ARDTool::InvalidModuleException& e) {
        cout << "Caught InvalidModuleException: " << e.what() << " - that is OK!" << endl;
    }
    cout << "After exception testing with p2..." << endl;
    cout << "p2.getName(): "  << p2.getName() << endl << "p2.getPath(): " << p2.getPath()  << endl << "p2.getEnv(): " << p2.getEnv() << endl << "p2.modulesEnd(): " << p2.modulesEnd() << endl << "p2.customEnd(): " << p2.customEnd() << endl << "p2.valid(): " << p2.valid() << endl;
    cout << "Modules for p1:" << endl;
    while(!p1.modulesEnd()) {
        cout << p1.getNextModule() << endl;
    }
    cout << "Custom commands for p1:" << endl;
    while(!p1.customEnd()) {
        cout << p1.getNextCustom() << endl;
    }
    cout << "Modules for p2:" << endl;
    while(!p2.modulesEnd()) {
        cout << p2.getNextModule() << endl;
    }
    cout << "Custom commands for p2:" << endl;
    while(!p2.customEnd()) {
        cout << p2.getNextCustom() << endl;
    }
    cout << "After listing..." << endl;
    cout << "p1.getName(): "  << p1.getName() << endl << "p1.getPath(): " << p1.getPath()  << endl << "p1.getEnv(): " << p1.getEnv() << endl << "p1.modulesEnd(): " << p1.modulesEnd() << endl << "p1.customEnd(): " << p1.customEnd() << endl << "p1.valid(): " << p1.valid() << endl;
    p1.resetModules();
    p1.resetCustom();
    cout << "After reset..." << endl;
    cout << "p1.getName(): "  << p1.getName() << endl << "p1.getPath(): " << p1.getPath()  << endl << "p1.getEnv(): " << p1.getEnv() << endl << "p1.modulesEnd(): " << p1.modulesEnd() << endl << "p1.customEnd(): " << p1.customEnd() << endl << "p1.valid(): " << p1.valid() << endl;
    cout << "Modules for p1:" << endl;
    while(!p1.modulesEnd()) {
        cout << p1.getNextModule() << endl;
    }
    cout << "Custom commands for p1:" << endl;
    while(!p1.customEnd()) {
        cout << p1.getNextCustom() << endl;
    }
    cout << "After another listing..." << endl;
    cout << "p1.getName(): "  << p1.getName() << endl << "p1.getPath(): " << p1.getPath()  << endl << "p1.getEnv(): " << p1.getEnv() << endl << "p1.modulesEnd(): " << p1.modulesEnd() << endl << "p1.customEnd(): " << p1.customEnd() << endl << "p1.valid(): " << p1.valid() << endl;
    return EXIT_SUCCESS;
}
