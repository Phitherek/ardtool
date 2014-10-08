#include "Project.h"
#include "Exceptions.h"
using namespace ARDTool;

Project::Project() {
    _name = "";
    _path = "";
    _env = "";
    _modulesiter = -1;
    _customiter = -1;
}

Project::Project(std::string name) {
    _name = name;
    _env = "";
    _modulesiter = -1;
    _customiter = -1;
}

void Project::setName(std::string name) {
    _name = name;
}

void Project::setPath(std::string path) {
    _path = path;
}

void Project::setEnv(std::string env) {
    _env = env;
}

void Project::addModule(std::string module) {
    if(module[0] == '-') {
        return;
    }
    if(module == "bundle" || module == "db" || module == "assets" || module == "restart" || module == "custom") {
        _modules.push_back(module);
    } else {
        throw InvalidModuleException(module);
    }
}

void Project::addCustom(std::string cmd) {
    _custom.push_back(cmd);
}

std::string Project::getName() {
    return _name;
}

std::string Project::getPath() {
    return _path;
}

std::string Project::getEnv() {
    return _env;
}

std::string Project::getNextModule() {
    int modsize = _modules.size();
    if(modsize > 0 && _modulesiter < modsize-1) {
        _modulesiter++;
        return _modules[_modulesiter];
    } else {
        return "";
    }
}

std::string Project::getNextCustom() {
    int custsize = _custom.size();
    if(custsize > 0 && _customiter < custsize-1) {
        _customiter++;
        return _custom[_customiter];
    } else {
        return "";
    }
}

bool Project::modulesEnd() {
    int modsize = _modules.size();
    if(modsize > 0 && _modulesiter < modsize-1) {
        return false;
    }
    return true;
}

bool Project::customEnd() {
    int custsize = _custom.size();
    if(custsize > 0 && _customiter < custsize-1) {
        return false;
    }
    return true;
}

void Project::resetModules() {
    _modulesiter = -1;
}

void Project::resetCustom() {
    _customiter = -1;
}

bool Project::valid() {
    if(_name != "" && _env != "" && _path != "") {
        return true;
    }
    return false;
}
