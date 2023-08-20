#include <cmath>
#include <fstream>
#include "Point2D.h"


Point2D::Point2D() {
    x = 0.0;
    y = 0.0;
}

Point2D::Point2D(double in_x, double in_y) {
    x = in_x;
    y = in_y;
}


double GetDistanceBetween(Point2D p1, Point2D p2) {
    return sqrt(pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2));
}

ostream& operator<< (ostream& out, Point2D &p) {
    out << "(" <<  p.x << ", " << p.y << ")";
    return out;
}

Point2D operator+ (Point2D p1, Vector2D v1) {
    Point2D newvec;
    newvec.x = p1.x + v1.x;
    newvec.y = p1.y + v1.y;
    return newvec;
}

Vector2D operator- (Point2D p1, Point2D p2) {
    Vector2D newvec;
    newvec.x = p1.x - p2.x;
    newvec.y = p1.y - p2.y;
    return newvec;
}

bool operator== (Point2D p1, Point2D p2) {
    if (p1.x == p2.x && p1.y == p2.y)
        return true;
    else   
        return false;
}

bool operator!= (Point2D p1, Point2D p2) {
    if (p1.x != p2.x || p1.y != p2.y)
        return true;
    else
        return false;
}