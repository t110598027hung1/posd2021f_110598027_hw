#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>
#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double length, double width) {
        /*
        if (length < width) {
            throw std::invalid_argument("The length must be greater than the width.");
        }
        */
        if (length < 0 || width < 0) {
            throw std::invalid_argument("Length and width cannot be negative value.");
        } else {
            _length = length;
            _width = width;
        }
    }

    double area() const override {
        return _length * _width;
    }

    double perimeter() const override {
        return (_length + _width) * 2;
    }
    
    std::string info() const override {
        std::string format = "Rectangle (%.2f %.2f)";
        int length = std::snprintf(
            nullptr, 0, format.c_str(), _length, _width) + 1;
        char* buf = new char[length];
        std::snprintf(
            buf, length, format.c_str(), _length, _width);
        std::string str(buf);
        delete[] buf;
        return str;
    }

private:
    double _length;
    double _width;
};

#endif