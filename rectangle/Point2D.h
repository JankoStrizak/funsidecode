//
// Created by User on 2020-03-25.
//

//holds a coordinate
class Point2D {
private:
    float x;
    float y;
public:
    float x_val() const;
    float y_val() const;
    Point2D(float a, float b);
    Point2D& operator=(Point2D* p);
};

