#include "PokemonCenter.h"
PokemonCenter::PokemonCenter():Building()
{
    display_code = 'C';
    potion_capacity = 100;
    num_potions_remaining = potion_capacity;
    pokedollar_cost_per_potion = 5;
    state = POTIONS_AVAILABLE;
}
PokemonCenter::PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc):Building()
{
    display_code = 'C';
    potion_capacity = potion_cap;
    num_potions_remaining = potion_capacity;
    pokedollar_cost_per_potion = potion_cost;
    state = POTIONS_AVAILABLE;
    id_num = in_id;
    location = in_loc;

}
bool PokemonCenter::HasPotions()
{
    return (num_potions_remaining > 0) ? true : false;
}
unsigned int PokemonCenter::GetNumPotionsRemaining()
{
    return num_potions_remaining;
}
bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget)
{
    return (budget > potion*pokedollar_cost_per_potion) ? true : false;
}
double PokemonCenter::GetPokeDollarCost(unsigned int potion)
{
    return pokedollar_cost_per_potion * potion;
}
unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed)
{
    if(num_potions_remaining >= potion_needed)
    {
        num_potions_remaining -= potion_needed;
        return potion_needed;
    }
    else{
        int x = num_potions_remaining;
        num_potions_remaining = 0;
        return x;
    }
}
bool PokemonCenter::Update()
{
    if(state == NO_POTIONS_AVAILABLE)
    {
        return false;
    }
    else
    {
        if (num_potions_remaining == 0)
        {
            state = NO_POTIONS_AVAILABLE;
            display_code = 'c';
            cout << "PokemonCenter " << id_num << " has ran out of potions." << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
}
void PokemonCenter::ShowStatus()
{
    cout << "PokemonCenter Status:" << endl;
    Building::ShowStatus();
    cout << "PokeDollars per potion: " << pokedollar_cost_per_potion << "\nhas " << num_potions_remaining << " potions remaining. " << endl;
}
PokemonCenter::~PokemonCenter()
{
    cout << "PokemonCenter destructed" << endl;
}