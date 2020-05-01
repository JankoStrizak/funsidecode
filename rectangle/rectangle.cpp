#include <iostream>
#include <algorithm>
#include "Rectangle.h"
#include "Point2D.h"
using namespace std;


Rectangle::Rectangle(int n, const Point2D &b_l, float height, float length){
    id = n;
    bottom_left = new Point2D(b_l.x_val(), b_l.y_val());
    float x = b_l.x_val() + length;
    float y = b_l.y_val() + height;
    top_right =  new Point2D(x,y);
}

Rectangle::Rectangle(int n, float height, float length){
    id = n;
    bottom_left = new Point2D(0.0, 0.0);
    top_right =  new Point2D(length,height);
}

Rectangle::Rectangle(int n, const Point2D &b_l, float side_length){
    id = n;
    bottom_left = new Point2D(b_l.x_val(), b_l.y_val());
    float x = b_l.x_val() + side_length;
    float y = b_l.y_val() + side_length;
    top_right =  new Point2D(x,y);
}

Rectangle::Rectangle(int n, Rectangle* r){
    id = n;
    top_right = new Point2D (r->top_right->x_val(), r->top_right->y_val());
    bottom_left = new Point2D(r->bottom_left->x_val(), r->bottom_left->y_val());
}

Rectangle::Rectangle(int n, float side_length){
    id = n;
    bottom_left = new Point2D(0.0, 0.0);
    top_right =  new Point2D(side_length,side_length);
}

Rectangle::~Rectangle(){ //is this the best way to write this???????????
    Point2D* temp = this->top_right;
    delete temp;

    temp = this->bottom_left;
    delete temp;
    temp = nullptr;
}

Rectangle&Rectangle:: operator=(Rectangle* r){

    top_right = r->top_right;

    bottom_left = r->bottom_left;

    return *this;
}

bool Rectangle::point_contained(const Point2D &p){
    bool in = true; // true if point is in rectangle, otherwise false
    if (p.y_val() < bottom_left->y_val() || p.y_val() > top_right->y_val()){
        in = false;
    }
    else if (p.x_val() < bottom_left->x_val() || p.x_val() > top_right->x_val()){
        in = false;
    }
    return in;
}
bool Rectangle::intersect(const Rectangle &r){
    Point2D* r_bottom_right = new Point2D(r.top_right->x_val(), r.bottom_left->y_val());
    Point2D* r_top_left = new Point2D(r.bottom_left->x_val(), r.top_right->y_val());

    bool intersect = false;// true if rectangles intersect, otherwise false

    if(this->point_contained(*r.bottom_left)){
        intersect = true;
    }
    else if(this->point_contained(*r_bottom_right)){
        intersect = true;
    }
    else if (this->point_contained(*r.top_right)){
        intersect = true;
    }
    else if(this->point_contained(*r_top_left)){
        intersect == true;
    }
    return intersect;
}

int Rectangle::id_val(){
    return id;
}