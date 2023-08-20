#ifndef POKEMONGYM_H
#define POKEMONGYM_H
#include <iostream>
using namespace std;
#include "Building.h"
class PokemonGym : public Building 
{
private:
    unsigned int num_battles_remaining;
    unsigned int max_number_of_battles;
    unsigned int health_cost_per_battle;
    double PokeDollar_cost_per_battle;
    unsigned int experience_per_battle;

public:
    PokemonGym();
    PokemonGym(unsigned int, unsigned int, double, unsigned int, int, Point2D);
    double GetPokeDollarCost(unsigned int);
    unsigned int GetHealthCost(unsigned int);
    unsigned int GetNumBattlesRemaining();
    bool IsAbleToBattle(unsigned int, double, unsigned int);
    unsigned int TrainPokemon(unsigned int);
    unsigned int GetExperiencePerBattle();
    //void SetNumBattlesRemaining(unsigned int);
    bool Update();
    bool passed();
    void ShowStatus();
    ~PokemonGym();
};
enum PokemonGymStates
{
    NOT_DEFATED = 0,
    DEFEATED = 1
};
#endif