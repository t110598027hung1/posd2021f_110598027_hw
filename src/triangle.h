#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"

class Triangle: public Shape {
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2): _vec1(vec1), _vec2(vec2) { }

    double area() const override {
        return std::abs(_vec1.x() * _vec2.y() - _vec2.x() * _vec1.y()) / 2.0;
    }

    double perimeter() const override {
        double length = 0.0;
        length += _vec1.length();
        length += _vec2.length();
        length += _vec1.subtract(_vec2).length();
        return length;
    }

    std::string info() const override {
        std::string format = "Triangle ([%.2f,%.2f] [%.2f,%.2f])";
        int length = std::snprintf(
            nullptr, 0, format.c_str(), _vec1.x(), _vec1.y(), _vec2.x(), _vec2.y()) + 1;
        char* buf = new char[length];
        std::snprintf(
            buf, length, format.c_str(), _vec1.x(), _vec1.y(), _vec2.x(), _vec2.y());
        std::string str(buf);
        delete[] buf;
        return str;
    }

private:
    TwoDimensionalVector _vec1;
    TwoDimensionalVector _vec2;
};

#endif