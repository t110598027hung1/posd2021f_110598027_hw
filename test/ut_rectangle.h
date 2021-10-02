#include <limits>
#include "../src/rectangle.h"

class CaseRectangle: public ::testing::Test {
protected:
    double inf = std::numeric_limits<double>::infinity();
    Rectangle* rectangle1;
    Rectangle* rectangle2;
    Rectangle* rectangle3;
    Rectangle* rectangle4;

    void SetUp() override {
        rectangle1 = new Rectangle(50.0, 10.0);
        rectangle2 = new Rectangle(100.0, 0.0);
        rectangle3 = new Rectangle(12.4567, 8.8888);
        rectangle4 = new Rectangle(inf, 12.4544);
    }
    void TearDown() override {
        delete rectangle1;
        delete rectangle2;
        delete rectangle3;
        delete rectangle4;
    }
};

TEST_F(CaseRectangle, Create) {
    try {
        Rectangle normalRectangle1 = Rectangle(0, 0);
        Rectangle normalRectangle2 = Rectangle(10, 0);
        Rectangle normalRectangle3 = Rectangle(600, 19);
    }
    catch (const std::exception &e) {
        FAIL() << "Caught exception.";
    }
    try {
        Rectangle invalidRectangle = Rectangle(-30, -80);
        ADD_FAILURE() << "Didn't throw exception as expected.";
    }
    catch (const std::invalid_argument &e) {
        SUCCEED();
        return;
    }
    // length 小於 width 的檢查(不需要)
    /*
    try {
        Rectangle invalidRectangle = Rectangle(19, 600);
        ADD_FAILURE() << "Didn't throw exception as expected.";
    }
    catch (const std::invalid_argument &e) {
        SUCCEED();
        return;
    }
    */
    // gtest
    // http://library.isr.ist.utl.pt/docs/roswiki/gtest.html
}

TEST_F(CaseRectangle, Area) {
    ASSERT_NEAR(500.0, rectangle1->area(), 0.001);
    ASSERT_NEAR(0.0, rectangle2->area(), 0.001);
    ASSERT_NEAR(110.725, rectangle3->area(), 0.001);
    ASSERT_EQ(inf, rectangle4->area());
}

TEST_F(CaseRectangle, Perimeter) {
    ASSERT_NEAR(120.0, rectangle1->perimeter(), 0.001);
    ASSERT_NEAR(200.0, rectangle2->perimeter(), 0.001);
    ASSERT_NEAR(42.691, rectangle3->perimeter(), 0.001);
    ASSERT_EQ(inf, rectangle4->perimeter());
}

TEST_F(CaseRectangle, Info) {
    ASSERT_EQ("Rectangle (50.00 10.00)", rectangle1->info());
    ASSERT_EQ("Rectangle (100.00 0.00)", rectangle2->info());
    ASSERT_EQ("Rectangle (12.46 8.89)", rectangle3->info());
    ASSERT_EQ("Rectangle (inf 12.45)", rectangle4->info());
}