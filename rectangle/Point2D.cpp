//
// Created by User on 2020-03-25.
//

#include "Point2D.h"

float Point2D::x_val() const{
    return x;
}

float Point2D::y_val() const{
    return y;
}

Point2D::Point2D(float a, float b) {
    x = a;
    y = b;
}

Point2D&Point2D::operator=(Point2D *p) {
    x = p->x_val();
    y = p->y_val();

    return *this;
}
