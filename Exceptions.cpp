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

FileException::FileException(std::string path, std::string error) {
    _path = path;
    _error = error;
}

FileException::~FileException() throw() {}

const char* FileException::what() const throw() {
    std::string msg = "";
    msg += "There was a problem with ";
    msg += _path;
    msg += " file: ";
    msg += _error;
    msg += "!";
    return msg.c_str();
}

ParseException::ParseException(int line, std::string error) {
    _line = line;
    _error = error;
}

ParseException::~ParseException() throw() {}

const char* ParseException::what() const throw() {
    std::stringstream msgss;
    msgss.str("");
    msgss << "Config parse error in line ";
    msgss << _line;
    msgss << ": ";
    msgss << _error;
    msgss << "!";
    return msgss.str().c_str();
}
