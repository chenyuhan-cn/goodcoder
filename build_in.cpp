//
// Created by cyh on 2019/11/20.
//
#include "build_in.h"
#include <iostream>
namespace parser {
    bool parser_colume(const char *str, int *result) {
        bool ret = true;
        if (str == NULL) {
            ret = false;
        } else {
            const char *tmp_str = str;
            int num1 = 0;//　数字的数量
            int num2 = 0;//　'-' 的数量
            int num3 = 0;//　其他字符的数量
            while (*tmp_str != '\0'
                   && *tmp_str != '\n'
                   && *tmp_str != '\t'
                   && *tmp_str != ','
                   && *tmp_str != ':') {
                if (*tmp_str >= '0' && *tmp_str <= '9') {
                    num1++;
                } else if (*tmp_str == '-') {
                    num2++;
                } else {
                    num3++;
                }
                tmp_str++;
            }
            if (num2 > 1 || num3 > 0) {
                ret = false;
                return ret;
            }
            if (num2 == 1 && *str != '-') {
                ret = false;
                return ret;
            }
            if (sscanf(str, "%d", result) != 1) {
                ret = false;
            }
        }
        return ret;
    }

    bool parser_colume(const char *str, char *result) {
        bool ret = true;
        if (str == NULL) {
            ret = false;
        } else {
            char *tmp_result = result;
            const char *tmp_str = str;
            while (*tmp_str != '\0'
                   && *tmp_str != '\n'
                   && *tmp_str != '\t') {
                *tmp_result++ = *tmp_str++;
            }
            *tmp_result = '\0';
        }
        return ret;
    }

    bool parser_colume(const char *str, float *result) {
        bool ret = true;
        if (str == NULL) {
            ret = false;
        } else {
            const char *tmp_str = str;
            int num1 = 0;//　数字的数量
            int num2 = 0;//　'-' 的数量
            int num3 = 0;//　'.'的数量
            int num4 = 0;//　其他字符的数量
            char final_char = '!';
            while (*tmp_str != '\0'
                   && *tmp_str != '\n'
                   && *tmp_str != '\t'
                   && *tmp_str != ','
                   && *tmp_str != ':') {
                if (*tmp_str >= '0' && *tmp_str <= '9') {
                    num1++;
                } else if (*tmp_str == '-') {
                    num2++;
                } else if (*tmp_str == '.') {
                    num3++;
                } else {
                    num4++;
                }
                final_char = *tmp_str;
                tmp_str++;
            }
            if (num2 > 1 || num4 > 0 || num3 > 1) {
                ret = false;
                return ret;
            }
            if (num2 == 1 && *str != '-') {
                ret = false;
                return ret;
            }
            if (num3 == 1 && (*str == '.' || final_char == '.')) {
                ret = false;
                return ret;
            }
            if (sscanf(str, "%f", result) != 1) {
                ret = false;
            }
        }
        return ret;
    }

    bool parser_colume(const char *str, std::string *result) {
        bool ret = true;
        if (str == NULL) {
            ret = false;
        } else {
            const char *tmp_str = str;
            int index = 0;
            std::string tmp_result;
            while (*tmp_str != '\0'
                   && *tmp_str != '\n'
                   && *tmp_str != '\t') {
                //char ch = *tmp_str;
                tmp_result += *tmp_str;
                //std::cout<<tmp_result<<' '<<*tmp_str<<std::endl;
                tmp_str++;
            }
            *result = tmp_result;
        }
        return ret;
    }
}
