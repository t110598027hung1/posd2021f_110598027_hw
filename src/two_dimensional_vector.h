#ifndef TWODIMENSIONALVECTOR_H
#define TWODIMENSIONALVECTOR_H

#include <iostream>
#include <string>
#include <cmath>

class TwoDimensionalVector {
public:
    TwoDimensionalVector(double x, double y): _x(x), _y(y) {}

    double x() const {
        return _x;
    }

    double y() const {
        return _y;
    }

    double length() const {
        return sqrt(pow(x(), 2) + pow(y(), 2));
    }

    double dot(TwoDimensionalVector vec) const {
        return x() * vec.x() + y() * vec.y();
    }

    double cross(TwoDimensionalVector vec) const {
        return x() * vec.y() - y() * vec.x();
    }

    TwoDimensionalVector subtract(TwoDimensionalVector vec) const {
        return TwoDimensionalVector(x() - vec.x(), y() - vec.y());
    }

    std::string info() const {
        int length = std::snprintf(nullptr, 0, "[%.2f,%.2f]", x(), y()) + 1;
        char* buf = new char[length];
        std::snprintf(buf, length, "[%.2f,%.2f]", x(), y());
        std::string str(buf);
        delete[] buf;
        return str;
    }

private:
    double _x;
    double _y;
};
// 向量計算公式參考：
// https://hackmd.io/@wiwiho/BkHi4COKS?print-pdf#/

#endif