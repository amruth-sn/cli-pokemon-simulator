#include "Vector2D.h"
#include <fstream>


Vector2D::Vector2D() {
    x = 0.0;
    y = 0.0;
}

Vector2D::Vector2D(double in_x, double in_y) {
    x = in_x;
    y = in_y;
}

Vector2D operator* (Vector2D v1, double d) {
    Vector2D newvec;
    newvec.x = v1.x*d;
    newvec.y = v1.y*d;
    return newvec; 
}

Vector2D operator/ (Vector2D v1, double d) {
    Vector2D newvec;
    newvec.x = v1.x/d;
    newvec.y = v1.y/d;
    return newvec;
}

ostream& operator<< (ostream& out, Vector2D &v) {
    out << "<" <<  v.x << ", " << v.y << ">";
    return out;
}

