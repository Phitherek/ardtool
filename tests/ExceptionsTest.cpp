#include "../Exceptions.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    cout << "ARDTool Tests: Exceptions" << endl;
    cout << "ARDTool::InvalidModuleException: ";
    try {
        throw(ARDTool::InvalidModuleException("test"));
    } catch(ARDTool::InvalidModuleException& e) {
        std::string msg(e.what());
        if(msg == "Invalid module name: test!") {
            cout << "success!" << endl;
        } else {
            cout << "failure(" << e.what() << ")!" << endl;
        }
    }
    cout  << "ARDTool::FileException: ";
    try {
        throw(ARDTool::FileException("/some/path", "Only testing"));
    } catch(ARDTool::FileException& e) {
        std::string msg(e.what());
        if(msg == "There was a problem with /some/path file: Only testing!") {
            cout << "success!" << endl;
        } else {
            cout << "failure(" << e.what() << ")!" << endl;
        }
    }
    cout  << "ARDTool::ParseException: ";
    try {
        throw(ARDTool::ParseException(7, "Only testing"));
    } catch(ARDTool::ParseException& e) {
        std::string msg(e.what());
        if(msg == "Config parse error in line 7: Only testing!") {
            cout << "success!" << endl;
        } else {
            cout << "failure(" << e.what() << ")!" << endl;
        }
    }
}
