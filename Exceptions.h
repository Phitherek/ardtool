#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H
#include <string>
#include <sstream>
#include <exception>
namespace ARDTool {
    class InvalidModuleException: public std::exception {
        private:
            std::string _name;
        public:
            InvalidModuleException(std::string name);
            ~InvalidModuleException() throw();
            const char* what() const throw();
    };
    
    class FileException: public std::exception {
        private:
            std::string _path;
            std::string _error;
        public:
            FileException(std::string path, std::string error);
            ~FileException() throw();
            const char* what() const throw();
    };
    
    class ParseException: public std::exception {
        private:
            int _line;
            std::string _error;
        public:
            ParseException(int line, std::string error);
            ~ParseException() throw();
            const char* what() const throw();
    };
}
#endif
