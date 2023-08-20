#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H

#include <string>
#include <iostream>
#include "Trainer.h"
#include "Point2D.h"
#include "GameObject.h"

class WildPokemon : public GameObject {
    protected:
    double attack;
    double health;
    bool variant;
    bool in_combat;
    string name;
    Trainer* current_trainer;
    
    public:
    WildPokemon(string, double, double, bool, int, Point2D);
    void follow(Trainer*);
    bool get_variant();
    double get_attack();
    double get_health();
    bool get_in_combat();
    bool Update();
    void ShowStatus();
    bool IsAlive();
    virtual bool ShouldBeVisible();


};

enum WildPokemonStates
{
    IN_ENVIORNMENT = 0,
    DEAD = 1,
    IN_TRAINER = 2,
};

#endif