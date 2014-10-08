#include "Exceptions.h"
using namespace ARDTool;

InvalidModuleException::InvalidModuleException(std::string name) {
    _name = name;
}

InvalidModuleException::~InvalidModuleException() throw() {}

const char* InvalidModuleException::what() const throw() {
    std::string msg = "";
    msg += "Invalid module name: ";
    msg += _name;
    msg += "!";
    return msg.c_str();
}
