//
// Created by cyh on 2019/11/20.
//
#include "parser.h"
namespace parser {
    Parser::Parser() {
        memset(this, '\0', sizeof(*this));
    }

    bool Parser::parser_line(const char *str, int colume_num) {
        int ret = true;
        if (str == NULL || colume_num <= 0) {
            ret = false;
        } else {
            colume_number = colume_num;
            const char *tmp_str = str;
            int index = 0;
            for (int i = 0; str[i] != '\n'; i++) {
                if (i == 0) {
                    colume[index++] = &str[i];
                } else if (str[i] == '\t') {
                    colume[index++] = &str[i + 1];
                }
            }
            if (index != colume_num) {
                ret = false;
            }
        }
        return ret;
    }

//    template<class T>
//    bool Parser::get_colume(const int index, T *result) {
//        bool ret = true;
//        if (index < 0 || index >= colume_number) {
//            ret = false;
//        } else {
//            //std::cout<<colume[index]<<std::endl;
//            ret = parser_colume(colume[index], result);
//        }
//        return ret;
//    }
}