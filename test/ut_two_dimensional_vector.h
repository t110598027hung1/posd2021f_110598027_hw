#include <limits>
#include <cmath>
#include "../src/two_dimensional_vector.h"

class CaseTwoDimensionalVector: public ::testing::Test {
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
    }
};

TEST_F(CaseTwoDimensionalVector, Create) {
    try {
        TwoDimensionalVector normalVector1 = TwoDimensionalVector(0, 0);
        TwoDimensionalVector normalVector2 = TwoDimensionalVector(-80.3, 256.4897);
        TwoDimensionalVector normalVector3 = TwoDimensionalVector(19, M_PI);
    }
    catch (const std::exception &e) {
        FAIL() << "Caught exception.";
    }
}

TEST_F(CaseTwoDimensionalVector, X) {
    ASSERT_NEAR(5.0, vectorRight->x(), 0.001);
    ASSERT_NEAR(-5.0, vectorLeft->x(), 0.001);
    ASSERT_NEAR(0.0, vectorUp->x(), 0.001);
    ASSERT_NEAR(0.0, vectorDown->x(), 0.001);
    ASSERT_NEAR(0.0, vectorZero->x(), 0.001);
    ASSERT_EQ(inf, vectorInf->x());
    ASSERT_NEAR(4.651, vectorUpperRight->x(), 0.001);
    ASSERT_NEAR(-10.0, vectorUpperLeft->x(), 0.001);
    ASSERT_NEAR(13.0, vectorLowerRight->x(), 0.001);
    ASSERT_NEAR(-10.0, vectorLowerLeft->x(), 0.001);
}

TEST_F(CaseTwoDimensionalVector, Y) {
    ASSERT_NEAR(0.0, vectorRight->y(), 0.001);
    ASSERT_NEAR(0.0, vectorLeft->y(), 0.001);
    ASSERT_NEAR(5.0, vectorUp->y(), 0.001);
    ASSERT_NEAR(-5.0, vectorDown->y(), 0.001);
    ASSERT_NEAR(0.0, vectorZero->y(), 0.001);
    ASSERT_EQ(-inf, vectorInf->y());
    ASSERT_NEAR(1.222, vectorUpperRight->y(), 0.001);
    ASSERT_NEAR(10.0, vectorUpperLeft->y(), 0.001);
    ASSERT_NEAR(-7.488, vectorLowerRight->y(), 0.001);
    ASSERT_NEAR(-2.5, vectorLowerLeft->y(), 0.001);
}

TEST_F(CaseTwoDimensionalVector, Length) {
    ASSERT_NEAR(5.0, vectorRight->length(), 0.001);
    ASSERT_NEAR(5.0, vectorLeft->length(), 0.001);
    ASSERT_NEAR(5.0, vectorUp->length(), 0.001);
    ASSERT_NEAR(5.0, vectorDown->length(), 0.001);
    ASSERT_NEAR(0.0, vectorZero->length(), 0.001);
    ASSERT_EQ(inf, vectorInf->length());
    ASSERT_NEAR(4.809, vectorUpperRight->length(), 0.001);
    ASSERT_NEAR(14.142, vectorUpperLeft->length(), 0.001);
    ASSERT_NEAR(15.002, vectorLowerRight->length(), 0.001);
    ASSERT_NEAR(10.307, vectorLowerLeft->length(), 0.001);
}

TEST_F(CaseTwoDimensionalVector, Dot) {
    ASSERT_NEAR(-25.0, vectorRight->dot(*vectorLeft), 0.001);
    ASSERT_NEAR(0.0, vectorRight->dot(*vectorUp), 0.001);
    ASSERT_NEAR(0.0, vectorLeft->dot(*vectorDown), 0.001);
    ASSERT_NEAR(0.0, vectorLeft->dot(*vectorZero), 0.001);
    ASSERT_NEAR(50.0, vectorUp->dot(*vectorUpperLeft), 0.001);
    ASSERT_NEAR(-6.111, vectorDown->dot(*vectorUpperRight), 0.001);
    ASSERT_NEAR(0.0, vectorZero->dot(*vectorZero), 0.001);
    ASSERT_EQ(inf, vectorInf->dot(*vectorInf));
    ASSERT_NEAR(0.0, vectorUpperRight->dot(*vectorZero), 0.001);
    ASSERT_NEAR(-34.297, vectorUpperRight->dot(*vectorUpperLeft), 0.001);
    ASSERT_NEAR(23.133, vectorUpperRight->dot(*vectorUpperRight), 0.001);
    ASSERT_NEAR(50.0, vectorUpperLeft->dot(*vectorLeft), 0.001);
    ASSERT_EQ(inf, vectorLowerRight->dot(*vectorInf));
    ASSERT_NEAR(75.0, vectorLowerLeft->dot(*vectorUpperLeft), 0.001);
    // dot product calculator:
    // https://www.mathepower.com/en/dotproduct.php
}

TEST_F(CaseTwoDimensionalVector, Cross) {
    ASSERT_NEAR(0.0, vectorRight->cross(*vectorLeft), 0.001);
    ASSERT_NEAR(25.0, vectorRight->cross(*vectorUp), 0.001);
    ASSERT_NEAR(25.0, vectorLeft->cross(*vectorDown), 0.001);
    ASSERT_NEAR(0.0, vectorLeft->cross(*vectorZero), 0.001);
    ASSERT_NEAR(50.0, vectorUp->cross(*vectorUpperLeft), 0.001);
    ASSERT_NEAR(23.259, vectorDown->cross(*vectorUpperRight), 0.001);
    ASSERT_NEAR(0.0, vectorZero->cross(*vectorZero), 0.001);
    ASSERT_NEAR(0.0, vectorUpperRight->cross(*vectorZero), 0.001);
    ASSERT_NEAR(58.741, vectorUpperRight->cross(*vectorUpperLeft), 0.001);
    ASSERT_NEAR(0.0, vectorUpperRight->cross(*vectorUpperRight), 0.001);
    ASSERT_NEAR(50.0, vectorUpperLeft->cross(*vectorLeft), 0.001);
    ASSERT_NEAR(-125.0, vectorLowerLeft->cross(*vectorUpperLeft), 0.001);
    SUCCEED();
}

TEST_F(CaseTwoDimensionalVector, Substract) {
    ASSERT_NEAR(10.0, vectorRight->subtract(*vectorLeft).x(), 0.001);
    ASSERT_NEAR(0.0, vectorRight->subtract(*vectorLeft).y(), 0.001);
    ASSERT_NEAR(5.0, vectorRight->subtract(*vectorUp).x(), 0.001);
    ASSERT_NEAR(-5.0, vectorRight->subtract(*vectorUp).y(), 0.001);
    ASSERT_NEAR(-5.0, vectorLeft->subtract(*vectorDown).x(), 0.001);
    ASSERT_NEAR(5.0, vectorLeft->subtract(*vectorDown).y(), 0.001);
    ASSERT_NEAR(-5.0, vectorLeft->subtract(*vectorZero).x(), 0.001);
    ASSERT_NEAR(0.0, vectorLeft->subtract(*vectorZero).y(), 0.001);
    ASSERT_NEAR(10.0, vectorUp->subtract(*vectorUpperLeft).x(), 0.001);
    ASSERT_NEAR(-5.0, vectorUp->subtract(*vectorUpperLeft).y(), 0.001);
    ASSERT_NEAR(-4.651, vectorDown->subtract(*vectorUpperRight).x(), 0.001);
    ASSERT_NEAR(-6.222, vectorDown->subtract(*vectorUpperRight).y(), 0.001);
    ASSERT_NEAR(0.0, vectorZero->subtract(*vectorZero).x(), 0.001);
    ASSERT_NEAR(0.0, vectorZero->subtract(*vectorZero).y(), 0.001);
    ASSERT_NEAR(4.651, vectorUpperRight->subtract(*vectorZero).x(), 0.001);
    ASSERT_NEAR(1.222, vectorUpperRight->subtract(*vectorZero).y(), 0.001);
    ASSERT_NEAR(14.651, vectorUpperRight->subtract(*vectorUpperLeft).x(), 0.001);
    ASSERT_NEAR(-8.777, vectorUpperRight->subtract(*vectorUpperLeft).y(), 0.001);
    ASSERT_NEAR(0.0, vectorUpperRight->subtract(*vectorUpperRight).x(), 0.001);
    ASSERT_NEAR(0.0, vectorUpperRight->subtract(*vectorUpperRight).y(), 0.001);
    ASSERT_NEAR(-5.0, vectorUpperLeft->subtract(*vectorLeft).x(), 0.001);
    ASSERT_NEAR(10.0, vectorUpperLeft->subtract(*vectorLeft).y(), 0.001);
    ASSERT_EQ(-inf, vectorLowerRight->subtract(*vectorInf).x());
    ASSERT_EQ(inf, vectorLowerRight->subtract(*vectorInf).y());
    ASSERT_NEAR(0.0, vectorLowerLeft->subtract(*vectorUpperLeft).x(), 0.001);
    ASSERT_NEAR(-12.5, vectorLowerLeft->subtract(*vectorUpperLeft).y(), 0.001);
}

TEST_F(CaseTwoDimensionalVector, Info) {
    ASSERT_EQ("[5.00,0.00]", vectorRight->info());
    ASSERT_EQ("[-5.00,0.00]", vectorLeft->info());
    ASSERT_EQ("[0.00,5.00]", vectorUp->info());
    ASSERT_EQ("[0.00,-5.00]", vectorDown->info());
    ASSERT_EQ("[0.00,0.00]", vectorZero->info());
    ASSERT_EQ("[inf,-inf]", vectorInf->info());
    ASSERT_EQ("[4.65,1.22]", vectorUpperRight->info());
    ASSERT_EQ("[-10.00,10.00]", vectorUpperLeft->info());
    ASSERT_EQ("[13.00,-7.49]", vectorLowerRight->info());
    ASSERT_EQ("[-10.00,-2.50]", vectorLowerLeft->info());
    //SUCCEED();
}