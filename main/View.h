#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include "GameObject.h"

class View {

    public:
    static const int view_maxsize = 20;

    View();
    void Clear();
    void Plot(GameObject* ptr);
    void Draw();
    
    private:
    int size;
    double scale;
    Point2D origin;
    char grid[view_maxsize][view_maxsize][2];

    bool GetSubscripts(int&, int&, Point2D);
};

#endif
