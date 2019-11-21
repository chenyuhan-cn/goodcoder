//
// Created by cyh on 2019/11/20.
//

#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include "build_in.h"
namespace parser {
    class Parser {
    public:
        Parser();

        bool parser_line(const char *str, int colume_num);

        template<class T>
        bool get_colume(const int index, T *result) {
            bool ret = true;
            if (index < 0 || index >= colume_number) {
                ret = false;
            } else {
                //std::cout<<colume[index]<<std::endl;
                ret = parser_colume(colume[index], result);
            }
            return ret;
        }

        static const int MAX_COLUMN = 1024;
        const char *colume[MAX_COLUMN]{};
        int colume_number{};
    };
}
#endif //PARSER_PARSER_H
