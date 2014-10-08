#ifndef _PROJECT_H
#define _PROJECT_H
#include <string>
#include <vector>
namespace ARDTool {
    class Project {
        private:
            std::string _name;
            std::string _path;
            std::string _env;
            std::vector<std::string> _modules;
            std::vector<std::string> _custom;
            int _modulesiter;
            int _customiter;
        public:
            Project();
            Project(std::string name);
            void setName(std::string name);
            void setPath(std::string path);
            void setEnv(std::string env);
            void addModule(std::string module);
            void addCustom(std::string cmd);
            std::string getName();
            std::string getPath();
            std::string getEnv();
            std::string getNextModule();
            std::string getNextCustom();
            bool modulesEnd();
            bool customEnd();
            void resetModules();
            void resetCustom();
            bool valid();
    };
}
#endif
