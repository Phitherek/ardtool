#ifndef _CONFIGFILE_H
#define _CONFIGFILE_H
#include "Project.h"
#include <string>
#include <vector>
namespace ARDTool {
    class ConfigFile {
        private:
            std::string _path;
            std::vector<Project> _projects;
        public:
            ConfigFile(std::string path);
            Project getProjectByName(std::string name);
            std::string getPath();
    };
}
#endif
