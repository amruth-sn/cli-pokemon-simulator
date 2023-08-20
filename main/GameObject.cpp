#include "GameObject.h"
using namespace std;

GameObject::GameObject() {
    cout << "GameObject Constructed" << endl;
}

GameObject :: GameObject(char in_code)
:display_code(in_code), id_num (1), state('0')
{
    cout << "GameObject Constructed" << endl;
}

GameObject :: GameObject(Point2D in_loc, int in_id, char in_code)
:display_code(in_code), id_num(in_id), location(in_loc), state ('0')
{
    cout << "GameObject Constructed" << endl;
}

GameObject :: ~GameObject()
{
    cout << "GameObject destructed" << endl;
}
Point2D GameObject :: GetLocation() 
{
    Point2D position;
    position.x = location.x;
    position.y = location.y;
    return position;
}

int GameObject :: GetId()
{
    return id_num;
}

char GameObject :: GetState()
{
    return state;
}

void GameObject :: ShowStatus()
{
    cout << display_code << " " << id_num << " at " << location << endl;
}

void GameObject :: DrawSelf(char* ptr)
{
    *ptr = display_code;
    *(ptr+1) = '0' + id_num; //Meant to convert id_num to character
}