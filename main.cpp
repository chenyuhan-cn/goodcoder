#include "parser.h"
#include "user_type.h"
#include "gtest/gtest.h"
class TestParser : public testing::Test {
public:
    static void SetUpTestCase() {
        std::cout<< "SetUpTestCase" <<std::endl;
    }
    static void TearDownTestCase() {
        std::cout<< "TearDownTestCase" <<std::endl;
    }
    virtual void SetUp() {
        std::cout<< "SetUp" <<std::endl;
        strcpy(test1, "abcdef\t123\t3.9\t4:12,5,888,666\tahhhhh\t3:1.1,2,3.14159\tcyh man 21\n");
        flag = parser_test->parser_line(test1,7);
    }
    virtual void TearDown() {
        std::cout<< "TearDown" <<std::endl;
    }
    char test1[100];
    parser::Parser *parser_test = new parser::Parser();
    bool flag;
};
TEST_F(TestParser, test_init) {
    EXPECT_TRUE(flag);
    EXPECT_EQ(parser_test->colume_number, 7) ;
}
TEST_F(TestParser, test_int) {
    int x = 0;
    EXPECT_FALSE(parser_test->get_colume(0, &x));
    EXPECT_TRUE(parser_test->get_colume(1, &x));
}
TEST_F(TestParser, test_float) {
    float f = 0.0;
    EXPECT_FALSE(parser_test->get_colume(0, &f));
    EXPECT_TRUE(parser_test->get_colume(1, &f));
    EXPECT_TRUE(parser_test->get_colume(2, &f));
}
TEST_F(TestParser, test_char_s) {
    char* str = new char[10];
    EXPECT_TRUE(parser_test->get_colume(0, str));
    EXPECT_TRUE(parser_test->get_colume(1, str));
    EXPECT_TRUE(parser_test->get_colume(2, str));
    EXPECT_TRUE(parser_test->get_colume(3, str));
    EXPECT_TRUE(parser_test->get_colume(4, str));
    EXPECT_TRUE(parser_test->get_colume(5, str));
}
TEST_F(TestParser, test_int_vector) {
    std::vector<int> vec;
    EXPECT_FALSE(parser_test->get_colume(1, &vec));
    EXPECT_TRUE(parser_test->get_colume(3, &vec));
}
TEST_F(TestParser, test_float_vector) {
    std::vector<float> fvec;
    EXPECT_TRUE(parser_test->get_colume(3, &fvec));
    fvec.clear();
    EXPECT_TRUE(parser_test->get_colume(5, &fvec));
}
TEST_F(TestParser, test_final){
    std::string s;
    EXPECT_EQ(parser_test->get_colume(0, &s),true);

    int x = 0;
    EXPECT_EQ(parser_test->get_colume(1, &x),true);

    float y = 0.0;
    EXPECT_EQ(parser_test->get_colume(2, &y),true);

    std::vector<int> vec;
    EXPECT_EQ(parser_test->get_colume(3, &vec),true);

    char* z = new char[10];
    EXPECT_EQ(parser_test->get_colume(4, z),true);

    std::vector<float> fvec;
    EXPECT_EQ(parser_test->get_colume(5, &fvec),true);

    parser::MyType my_type{};
    EXPECT_EQ(my_type.parser_colume(parser_test->colume[6]), true);

    printf("string类型：\n");
    std::cout<<s<<std::endl<<std::endl;

    printf("int类型：\n");
    printf("%d\n\n", x);

    printf("float类型：\n");
    printf("%f\n\n", y);

    printf("int array类型：\n");
    int vec_size = vec.size();
    printf("vec_size = %d:\n", vec_size);
    for(int i = 0; i < vec.size(); i++) {
        printf("%d ", vec[i]);
    }
    printf("\n\n");

    printf("char*类型：\n");
    printf("%s\n\n",z);

    printf("float array类型：\n");
    int fvec_size = fvec.size();
    printf("vec_size = %d:\n", fvec_size);
    for(int i = 0; i < fvec_size; i++) {
        printf("%f ", fvec[i]);
    }
    printf("\n\n");

    printf("自定义类型:\n");
    printf("name = %s\n", my_type.get_name());
    printf("sex = %s\n", my_type.get_sex());
    printf("age = %d\n", my_type.get_age());
}

int main(int argc, char**argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}