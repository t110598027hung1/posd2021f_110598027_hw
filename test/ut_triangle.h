#include <limits>
#include <cmath>
#include "../src/triangle.h"

class CaseTriangle: public ::testing::Test {
protected:
    double inf = std::numeric_limits<double>::infinity();
    TwoDimensionalVector* vectorRight;
    TwoDimensionalVector* vectorLeft;
    TwoDimensionalVector* vectorUp;
    TwoDimensionalVector* vectorDown;
    TwoDimensionalVector* vectorZero;
    TwoDimensionalVector* vectorInf;
    TwoDimensionalVector* vectorUpperRight;
    TwoDimensionalVector* vectorUpperLeft;
    TwoDimensionalVector* vectorLowerRight;
    TwoDimensionalVector* vectorLowerLeft;
    Triangle* triangle1;
    Triangle* triangle2;
    Triangle* triangle3;
    Triangle* triangleZero1;
    Triangle* triangleZero2;
    Triangle* triangleInf;
    Triangle* triangleParallel1;
    Triangle* triangleParallel2;

    void SetUp() override {
        vectorRight = new TwoDimensionalVector(5.0, 0.0);
        vectorLeft = new TwoDimensionalVector(-5.0, 0.0);
        vectorUp = new TwoDimensionalVector(0.0, 5.0);
        vectorDown = new TwoDimensionalVector(0.0, -5.0);
        vectorZero = new TwoDimensionalVector(0.0, 0.0);
        vectorInf = new TwoDimensionalVector(inf, -inf);
        vectorUpperRight = new TwoDimensionalVector(4.6519, 1.2222);
        vectorUpperLeft = new TwoDimensionalVector(-10.0, 10.0);
        vectorLowerRight = new TwoDimensionalVector(13.0, -7.488);
        vectorLowerLeft = new TwoDimensionalVector(-10.0, -2.5);
        triangle1 = new Triangle(*vectorRight, *vectorUp);
        triangle2 = new Triangle(*vectorUpperLeft, *vectorLowerRight);
        triangle3 = new Triangle(*vectorUpperRight, *vectorLowerRight);
        triangleZero1 = new Triangle(*vectorZero, *vectorZero);
        triangleZero2 = new Triangle(*vectorZero, *vectorLeft);
        triangleInf = new Triangle(*vectorInf, *vectorDown);
        triangleParallel1 = new Triangle(*vectorLowerLeft, *vectorLowerLeft);
        triangleParallel2 = new Triangle(*vectorRight, *vectorLeft);
    }

    void TearDown() override {
        delete vectorRight;
        delete vectorLeft;
        delete vectorUp;
        delete vectorDown;
        delete vectorZero;
        delete vectorInf;
        delete vectorUpperRight;
        delete vectorUpperLeft;
        delete vectorLowerRight;
        delete vectorLowerLeft;
        delete triangle1;
        delete triangle2;
        delete triangle3;
        delete triangleZero1;
        delete triangleZero2;
        delete triangleInf;
        delete triangleParallel1;
        delete triangleParallel2;
    }
};

TEST_F(CaseTriangle, Create) {
    try {
        Triangle normalVector1 = Triangle(
            TwoDimensionalVector(0, 18),
            TwoDimensionalVector(0, 18));
        Triangle normalVector2 = Triangle(
            TwoDimensionalVector(87, -900),
            TwoDimensionalVector(4.6519, 1.2252));
        Triangle normalVector3 = Triangle(
            TwoDimensionalVector(-M_PI, M_PI * 5),
            TwoDimensionalVector(0.0001, M_PI));
    }
    catch (const std::exception &e) {
        FAIL() << "Caught exception.";
    }
}

TEST_F(CaseTriangle, Area) {
    ASSERT_NEAR(12.5, triangle1->area(), 0.001);
    ASSERT_NEAR(27.56, triangle2->area(), 0.001);
    ASSERT_NEAR(25.361, triangle3->area(), 0.001);
    ASSERT_NEAR(0.0, triangleZero1->area(), 0.001);
    ASSERT_NEAR(0.0, triangleZero2->area(), 0.001);
    //ASSERT_EQ(inf, triangleInf->area()); // result is NaN.
    ASSERT_NEAR(0.0, triangleParallel1->area(), 0.001);
    ASSERT_NEAR(0.0, triangleParallel2->area(), 0.001);
    // triangle area calculator:
    // https://onlinemschool.com/math/assistance/vector/triangle_area/
}

TEST_F(CaseTriangle, Perimeter) {
    ASSERT_NEAR(17.071, triangle1->perimeter(), 0.001);
    ASSERT_NEAR(58.038, triangle2->perimeter(), 0.001);
    ASSERT_NEAR(31.877, triangle3->perimeter(), 0.001);
    ASSERT_NEAR(0.0, triangleZero1->perimeter(), 0.001);
    ASSERT_NEAR(10.0, triangleZero2->perimeter(), 0.001);
    ASSERT_EQ(inf, triangleInf->perimeter());
    ASSERT_NEAR(20.616, triangleParallel1->perimeter(), 0.001);
    ASSERT_NEAR(20.0, triangleParallel2->perimeter(), 0.001);
    // triangle perimeter (and area) calculator:
    // https://www.triangle-calculator.com/?what=vc
}

TEST_F(CaseTriangle, Info) {
    ASSERT_EQ("Triangle ([5.00,0.00] [0.00,5.00])", triangle1->info());
    ASSERT_EQ("Triangle ([-10.00,10.00] [13.00,-7.49])", triangle2->info());
    ASSERT_EQ("Triangle ([4.65,1.22] [13.00,-7.49])", triangle3->info());
    ASSERT_EQ("Triangle ([0.00,0.00] [0.00,0.00])", triangleZero1->info());
    ASSERT_EQ("Triangle ([0.00,0.00] [-5.00,0.00])", triangleZero2->info());
    ASSERT_EQ("Triangle ([inf,-inf] [0.00,-5.00])", triangleInf->info());
    ASSERT_EQ("Triangle ([-10.00,-2.50] [-10.00,-2.50])", triangleParallel1->info());
    ASSERT_EQ("Triangle ([5.00,0.00] [-5.00,0.00])", triangleParallel2->info());
}