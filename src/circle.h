#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string>
#include <cmath>
#include "shape.h"

class Circle : public Shape {
public:
    Circle(double radius) {
        if (radius < 0) {
            throw std::invalid_argument("Radius cannot be negative value.");
        } else {
            _radius = radius;
        }
    }

    double area() const override {
        return _radius * _radius * M_PI;
    }

    double perimeter() const override {
        return _radius * 2 * M_PI;
    }

    std::string info() const override {
        int length = std::snprintf(nullptr, 0, "Circle (%.2f)", _radius) + 1;
        char* buf = new char[length];
        std::snprintf(buf, length, "Circle (%.2f)", _radius);
        std::string str(buf);
        delete[] buf;
        return str;
    }

private:
    double _radius;
};

#endif