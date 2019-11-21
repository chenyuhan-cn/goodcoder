//
// Created by cyh on 2019/11/20.
//

#ifndef PARSER_USER_TYPE_H
#define PARSER_USER_TYPE_H

#include <cstdio>
#include <cstring>
#include <iostream>

namespace  parser {
    class MyType {
    public:
        char *get_name() {
            return name;
        }

        char *get_sex() {
            return sex;
        }

        int get_age() {
            return age;
        }

        void set_val(char *t_name, char *t_sex, int t_age);

        bool parser_colume(const char *str);

    private:
        char *name;
        char *sex;
        int age;
    };


}
#endif //PARSER_USER_TYPE_H
