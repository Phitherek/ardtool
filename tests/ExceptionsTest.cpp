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
}
