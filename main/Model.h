#ifndef MODEL_H
#define MODEL_H

#include "GameObject.h"
#include "Trainer.h"
#include "Building.h"
#include "View.h"
#include "Input_Handling.h"
#include <list>
#include "WildPokemon.h"

class Model 
{
    private:
    int time;
    list <GameObject*> object_ptrs;
    list <GameObject*> active_ptrs;
    list <Trainer*> trainer_ptrs;
    list <PokemonCenter*> center_ptrs;
    list <PokemonGym*> gym_ptrs;
    list <WildPokemon*> wild_ptrs; //wild

    public:
    Model();
    ~Model();
    Trainer* GetTrainerPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    WildPokemon* GetWildPokemonPtr(int id); //wild
    bool Update();
    void Display(View& view);
    void ShowStatus();
    //Functions for Object creation
    void NewCommand(char, int, double, double);
};
#endif