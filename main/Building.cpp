#include "Building.h"
using namespace std;

Building :: Building()
:GameObject('B')
{
    cout << "Building default constructed" << endl;
}

Building :: Building(char in_code, int in_id, Point2D in_loc)
:GameObject(in_loc,in_id,in_code)
{
    cout << "Building constructed" << endl;
}

Building :: ~Building()
{
    cout << "Bulding destructed" << endl;
}

void Building :: AddOneTrainer()
{
    trainer_count++;
}

void Building :: RemoveOneTrainer()
{
    trainer_count--;
}

void Building::ShowStatus()
{
    GameObject:: ShowStatus();
    if(trainer_count > 1)
    {
        cout << trainer_count << " trainers are in this building" << endl;
    }
    else
    {
        cout << trainer_count << " trainer is in this building" << endl;
    }
}

bool Building :: ShouldBeVisible()
{
    return true;
}





