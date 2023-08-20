#include "PokemonGym.h"
PokemonGym::PokemonGym() : Building()
{
    display_code = 'G';
    state = NOT_DEFATED;
    max_number_of_battles = 10;
    num_battles_remaining = 10;
    health_cost_per_battle = 1;
    PokeDollar_cost_per_battle = 1.0;
    experience_per_battle = 2;
    cout << "PokemonGym default constructed" << endl;
}
PokemonGym::PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc) : Building()
{
    id_num = in_id;
    location = in_loc;
    display_code = 'G';
    state = NOT_DEFATED;
    max_number_of_battles = max_battle;
    num_battles_remaining = max_number_of_battles;
    health_cost_per_battle = health_loss;
    experience_per_battle = exp_per_battle;
    PokeDollar_cost_per_battle = PokeDollar_cost;
    cout << "PokemonGym constructed" << endl;
}
double PokemonGym::GetPokeDollarCost(unsigned int battle_qty)
{
    return PokeDollar_cost_per_battle * battle_qty;
}
unsigned int PokemonGym::GetHealthCost(unsigned int battle_qty)
{
    return health_cost_per_battle * battle_qty;
}
unsigned int PokemonGym::GetNumBattlesRemaining()
{
    return num_battles_remaining;
}
bool PokemonGym::IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health)
{
    if(budget >= GetPokeDollarCost(battle_qty) && health >= GetHealthCost(battle_qty))
    {
        return true;
    }
    return false;
}
unsigned int PokemonGym::TrainPokemon(unsigned int battle_units)
{
    int x;
    if(num_battles_remaining <= battle_units)
    {
        x = num_battles_remaining;
        num_battles_remaining = 0;
        return x * experience_per_battle;
    }
    else{
        num_battles_remaining -= battle_units;
        return battle_units * experience_per_battle;
    }
}
unsigned int PokemonGym::GetExperiencePerBattle()
{
    return experience_per_battle;
}
bool PokemonGym::Update()
{
    if (state == DEFEATED)
    {
        return false;
    }
    else
    {
        if (num_battles_remaining == 0)
        {
            state = DEFEATED;
            display_code = 'g';
            cout << display_code << id_num << " has been beaten" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool PokemonGym::passed()
{
    if(num_battles_remaining == 0)
    {
        return true;
    }
    return false;
}
void PokemonGym::ShowStatus()
{
    cout << "PokemonGym Status:" << endl;
    Building::ShowStatus();
    cout << "Max number of battles: " << max_number_of_battles << endl;
    cout << "Health cost per battle: " << health_cost_per_battle<< endl;
    cout << "PokeDollar cost per battle: " << PokeDollar_cost_per_battle << endl;
    cout << "Experience per battle: " << experience_per_battle << endl;
    cout << num_battles_remaining  << " battle(s) are remaining for this PokemonGym" << endl;
}
PokemonGym::~PokemonGym()
{
    cout << "PokemonGym destructed" << endl;
}
