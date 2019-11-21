//
// Created by cyh on 2019/11/21.
//
#include "user_type.h"

namespace parser {
    void MyType::set_val(char *t_name, char *t_sex, int t_age) {
        name = t_name;
        sex = t_sex;
        age = t_age;
    }
//    bool MyType::parser_colume(const char *str) {
//        bool ret = true;
//        if (str == NULL) {
//            ret = false;
//        } else {
//            char *t_name = new char[15];
//            const char *tmp_str = str;
//            if (sscanf(tmp_str, "%s", t_name) != 1) {
//                ret = false;
//                return ret;
//            }
//            while (*tmp_str != ' ') {
//                tmp_str++;
//            }
//            tmp_str++;
//            char *t_sex = new char[10];
//            if (sscanf(tmp_str, "%s", t_sex) != 1) {
//                ret = false;
//                return ret;
//            }
//            while (*tmp_str != ' ') {
//                tmp_str++;
//            }
//            tmp_str++;
//            int t_age;
//            if (sscanf(tmp_str, "%d", &t_age) != 1) {
//                ret = false;
//                return ret;
//            }
//            if (ret) {
//                set_val(t_name, t_sex, t_age);
//            }
//        }
//        return ret;
//    }
}
