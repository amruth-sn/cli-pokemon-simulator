#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Point2D.h"
#include "Vector2D.h"
#include <iostream>

class GameObject {
    protected:
    Point2D location;
    int id_num;
    char display_code;
    char state;

    public:
    GameObject();
    GameObject(char);
    GameObject(Point2D, int, char);
    virtual ~GameObject(); // destructor
    Point2D GetLocation();
    void SetLocation(Point2D); // added setter
    int GetId();
    char GetState();
    virtual void ShowStatus();
    virtual bool Update() = 0;
    virtual bool ShouldBeVisible() = 0;
    void DrawSelf(char*);
};

#endif