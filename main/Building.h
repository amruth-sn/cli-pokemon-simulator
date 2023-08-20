#ifndef BUILDING_H
#define BUILDING_H
#include "GameObject.h"
#include <iostream>

class Building : public GameObject {
    private:
    unsigned int trainer_count;

    public:
    Building();
    Building(char, int, Point2D);
    virtual ~Building();
    void AddOneTrainer();
    void RemoveOneTrainer();
    void ShowStatus();
    bool ShouldBeVisible();
};

#endif