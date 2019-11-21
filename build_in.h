//
// Created by cyh on 2019/11/20.
//

#ifndef PARSER_BUILD_IN_H
#define PARSER_BUILD_IN_H
#include "user_interface.h"
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
namespace parser {
    bool parser_colume(const char *str, int *result);

    bool parser_colume(const char *str, char *result);

    bool parser_colume(const char *str, float *result);

    bool parser_colume(const char *str, std::string *result);

    template<class T>
    bool parser_colume(const char *str, std::vector<T> *result) {
        bool ret = true;
        if (str == NULL) {
            ret = false;
        } else {

            const char *tmp_str = str;
            int element_num = 0;
            while (*tmp_str != '\0'
                   && *tmp_str != '\t'
                   && *tmp_str != '\n') {
                if (element_num == 0) {
                    parser_colume(tmp_str, &element_num);
                    //if(sscanf(tmp_str, "%d", &element_num) != 1) {
                    //    ret = false;
                    //}
                } else if (*tmp_str == ':' || *tmp_str == ',') {
                    T tmp;
                    parser_colume(tmp_str + 1, &tmp);
                    //std::cout << tmp << std::endl;
                    result->push_back(tmp);
                }
                tmp_str++;
            }
            //std::cout << element_num << result->size() << std::endl;
            if (element_num != result->size()) {
                ret = false;
            }
        }
        return ret;
    }
}
#endif //PARSER_BUILD_IN_H
