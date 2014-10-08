#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H
#include <string>
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
}
#endif
