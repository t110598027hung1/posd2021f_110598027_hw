#include <limits>
#include <cmath>
#include "../src/circle.h"

class CaseCircle: public ::testing::Test {
protected:
    double inf = std::numeric_limits<double>::infinity();
    Circle* circle1;
    Circle* circle2;
    Circle* circle3;
    Circle* circle4;

    void SetUp() override {
        circle1 = new Circle(1.1);
        circle2 = new Circle(100.0);
        circle3 = new Circle(M_PI);
        circle4 = new Circle(inf);
    }
    void TearDown() override {
        delete circle1;
        delete circle2;
        delete circle3;
        delete circle4;
    }
};

TEST_F(CaseCircle, Create) {
    try {
        Circle normalCircle1 = Circle(0);
        Circle normalCircle2 = Circle(10.8888);
        Circle normalCircle3 = Circle(26.321);
    }
    catch (const std::exception &e) {
        FAIL() << "Caught exception.";
    }
    try {
        Circle invalidCircle = Circle(-30);
        ADD_FAILURE() << "Didn't throw exception as expected.";
    }
    catch (const std::invalid_argument &e) {
        SUCCEED();
        return;
    }
}

TEST_F(CaseCircle, Area) {
    ASSERT_NEAR(3.801, circle1->area(), 0.001);
    ASSERT_NEAR(31415.926, circle2->area(), 0.001);
    ASSERT_NEAR(31.006, circle3->area(), 0.001);
    ASSERT_EQ(inf, circle4->area());
}

TEST_F(CaseCircle, Perimeter) {
    ASSERT_NEAR(6.911, circle1->perimeter(), 0.001);
    ASSERT_NEAR(628.318, circle2->perimeter(), 0.001);
    ASSERT_NEAR(19.739, circle3->perimeter(), 0.001);
    ASSERT_EQ(inf, circle4->perimeter());
}

TEST_F(CaseCircle, Info) {
    ASSERT_EQ("Circle (1.10)", circle1->info());
    ASSERT_EQ("Circle (100.00)", circle2->info());
    ASSERT_EQ("Circle (3.14)", circle3->info());
    ASSERT_EQ("Circle (inf)", circle4->info());
}