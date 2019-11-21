//
// Created by cyh on 2019/11/21.
//

#ifndef PARSER_USER_INTERFACE_H
#define PARSER_USER_INTERFACE_H
namespace parse {
    class UserInterface {
    public:
        virtual bool parse(const char* str) = 0;
        virtual ~UserInterface(){};
    };
}
#endif //PARSER_USER_INTERFACE_H
