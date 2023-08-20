#include "Trainer.h"

Trainer :: Trainer()
: GameObject('S'),speed(5)
{
    cout << "Trainer default constructed" << endl;
}

Trainer :: Trainer(char in_code)
:GameObject(in_code),speed(5)
{
    state = STOPPED;
    cout << "Trainer constructed" << endl;
}

Trainer :: Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
: name(in_name), speed(in_speed), GameObject(in_code)
{
    id_num = in_id;
    location = in_loc;
    state = STOPPED;
    cout << "Trainer constructed" << endl;

}

Trainer :: ~Trainer()
{
    cout << "Trainer destructed" << endl;
}

bool Trainer :: HasFainted()
{
    if (health == 0)
        return true;
    else
        return false;
}

bool Trainer :: ShouldBeVisible()
{
    if (!(this->HasFainted()))
        return true;
    else
        return false;

}        

void Trainer :: StartBattling(unsigned int num_battles)
{
    if(current_gym == NULL || GetDistanceBetween(this->location,current_gym->GetLocation()) != 0) //Check to see if Trainer is in gym
    {
        cout << display_code << " " << id_num << " : I can only battle trainers in a gym" << endl;
    }
    else if (this->HasFainted())
    {
        cout << display_code << " " << id_num << " : My pokemon have fainted so no more battles for me..." << endl;
    }
    else if (PokeDollars < current_gym->GetPokeDollarCost(num_battles))
    {
        cout << display_code << " " << id_num << " : Not enough money for battling" << endl;
    }
    else
    {
        state = BATTLING_IN_GYM;
        battles_to_buy = (current_gym->TrainPokemon(num_battles));
        battles_to_buy = battles_to_buy/(current_gym->GetExperiencePerBattle());
        cout << display_code << " " << id_num << " : Started to battle at the Gym " << current_gym->GetId() << " with " << num_battles << " battles" << endl;
        health -= (current_gym->GetHealthCost(battles_to_buy));
        PokeDollars -= (current_gym->GetPokeDollarCost((battles_to_buy)));
        experience += (battles_to_buy*(current_gym->GetExperiencePerBattle()));
    }
}

void Trainer :: StartRecoveringHealth(unsigned int num_potions)
{   
    if(current_center == NULL || GetDistanceBetween(this->location,current_center->GetLocation()) != 0) //Check to see if Trainer is in center
    {
        cout << display_code << " " << id_num << " : I can only recover health at a Pokemon Center" << endl;
    }
    else if ((current_center->GetNumPotionsRemaining()) < 1)
    {
        cout << display_code << " " << id_num << " : Cannot recover! No potions remaining in this Pokemon Center" << endl;
    }
    else if(!(current_center->CanAffordPotion(num_potions,PokeDollars)))
    {
        cout << display_code << " " << id_num << " : Not enough money to recover health." << endl;
    }
    else
    {
        state = RECOVERING_HEALTH;
        potions_to_buy = current_center->DistributePotion(num_potions);
        PokeDollars -=  current_center->GetPokeDollarCost(potions_to_buy);
        unsigned int health_gained = 5*potions_to_buy;
        health += health_gained;
        cout << display_code << " " << id_num << " : Started recovering " << potions_to_buy << " potions at Pokemon Center " << (current_center->GetId()) << endl;
    }

}

void Trainer :: Stop()
{
    state = STOPPED;
    cout << display_code << " " << id_num << " : Stopping.." << endl;
}

void Trainer :: SetupDestination(Point2D dest)
{
    destination = dest;
    delta = (destination - location)*(speed/GetDistanceBetween(destination,location));
}

void Trainer :: StartMoving(Point2D dest)
{
    SetupDestination(dest);
    if(state == IN_GYM && GetDistanceBetween(destination, current_gym->GetLocation()))
    {
        current_gym->RemoveOneTrainer();
    }
    if(state == AT_CENTER && GetDistanceBetween(destination,current_center->GetLocation()))
    {
        current_center -> RemoveOneTrainer();
    } 
    if (GetDistanceBetween(destination,location) == 0)
    {
        cout << display_code << " " << id_num << " : I'm already there. See?" << endl;
    }
    else if (this->HasFainted())
    {
        cout <<  display_code << " " << id_num << " : All my Pokemon have fainted. I may move but you cannot see me." << endl;
    }
    else
    {
        cout <<  display_code << " " << id_num << " : On my way" << endl;
        state = MOVING;
        if (following == true) {
            cout << display_code << " " << id_num << " : There is a wild Pokemon following me!" << endl;
        }
    }
}

void Trainer :: StartMovingToGym(PokemonGym* gym)
{
    SetupDestination(gym ->GetLocation());

    if(state == IN_GYM && GetDistanceBetween(destination, current_gym->GetLocation())) //Check to see if we need to remove a Trainer
    {
        current_gym->RemoveOneTrainer();
    }
    if(state == AT_CENTER && GetDistanceBetween(destination,current_center->GetLocation())) //Check to see if we need to remove a Trainer
    {
        current_center -> RemoveOneTrainer();
    }
    if(this->HasFainted())
    {
        cout << display_code << " " << id_num << " : All my Pokemon have fainted so I can't move to gym... " << endl;
    }
    else if (GetDistanceBetween(this->location,gym->GetLocation()) == 0)
    {
        cout << display_code << " " << id_num << " : I am already at the PokemonGym!" << endl;
    }
    else
    {
        state = MOVING_TO_GYM;
        current_gym = gym;
        cout << display_code << " " << id_num << " : on my way to the gym " << gym->GetId() << endl;
        if (following == true) {
            cout << display_code << " " << id_num << " : There is a wild Pokemon following me!" << endl;
        }
    }

}

void Trainer :: StartMovingToCenter(PokemonCenter* center)
{
    SetupDestination(center->GetLocation());

     if(state == IN_GYM && GetDistanceBetween(destination, current_gym->GetLocation())) //Check to see if we need to remove a Trainer
    {
        current_gym->RemoveOneTrainer();
    }
    if(state == AT_CENTER && GetDistanceBetween(destination,current_center->GetLocation())) //Check to see if we need to remove a Trainer
    {
        current_center -> RemoveOneTrainer();
    }
    if(this->HasFainted())
    {
        cout << display_code << " " << id_num << " : All my Pokemon have fainted so I should have gone to the center.." << endl;
    }
    else if(GetDistanceBetween(this->location,center->GetLocation()) == 0)
    {
        cout << display_code << " " << id_num << " : I am already at the Pokemon Center!" << endl;
    }
    else
    {
        state = MOVING_TO_CENTER;
        current_center = center;
        cout << display_code << " " << id_num << " : On my way to the Pokemon Center " << center->GetId() << endl;
        if (following == true) {
            cout << display_code << " " << id_num << " : There is a wild Pokemon following me!" << endl;
        }
    }
}

bool Trainer :: UpdateLocation()
{
    Vector2D difference = destination - location;

    if ((fabs(difference.x) <= fabs(delta.x)) && (fabs(difference.y) <= fabs(delta.y)))
    {
        location = destination;
        cout << display_code << " " << id_num << " : I'm there!" << endl;
    }
    else
    {
        location = location+delta;
        cout << display_code << " " << id_num << " : step..." << endl;
        return false;
    }
}

void Trainer :: ShowStatus()
{
    
    cout << name << " status: " << endl;
    GameObject :: ShowStatus();
    switch(state)
    {
        case STOPPED : cout << " stopped" << endl;
            break;
        case MOVING : cout << "moving at a speed of " << this->speed << " to destination " << this->destination << " at each step of " << this->delta << endl;
            break;
        case MOVING_TO_GYM: cout << "heading to PokemonGym " << current_gym->GetId() << " located at " << this->destination << " at a speed of " << this->speed << " at each step of " << this->delta << endl;
            break;
        case MOVING_TO_CENTER: cout << "heading to PokemonCenter " << current_center->GetId() << " at a speed of " << this->speed  << " at each step of " << this->delta << endl;
            break;
        case IN_GYM: cout << "inside PokemonGym " << current_gym->GetId() << endl;
            break;
        case AT_CENTER: cout << "inside PokemonCenter " << current_center->GetId() << endl;
            break;
        case BATTLING_IN_GYM: cout << "battling in PokemonGym " << current_gym->GetId() << endl; 
            break;
        case RECOVERING_HEALTH: cout << "recovering health in Pokemon Center " << current_center->GetId() << endl;
            break;
        case FAINTED: cout << "This trainer's Pokemon have fainted" << endl;
            break;
    }
}


bool Trainer :: Update()
{  
    if (this->HasFainted())
    {
        this->Stop();
        if(state != FAINTED){
            state = FAINTED;
            cout << this->name << " just ran out of health and can't move" << endl;
            return true;
        }
        cout << this->name << " is out of health and can't move" << endl;
        return false;
    }
        
    else if(state == STOPPED)
    {
        cout << this->name << " status: " << endl;
        cout << "Health: " << health << endl;
        cout << "PokeDollars: " << PokeDollars << endl;
        cout << "Experience: " << experience << endl;
        return false;

    }
    else if (state == MOVING)
    {
        health -= 1;
        PokeDollars += GetRandomAmountOfPokeDollars();
        cout << this->name << " status: " << endl;
        cout << "Health: " << health << endl;
        cout << "PokeDollars: " << PokeDollars << endl;
        cout << "Experience: " << experience << endl;
        
        
        if(UpdateLocation())
        {
            state = STOPPED;
            return true;
        }
        else
        {
            return false;
        }
    }

    else if (state == MOVING_TO_GYM)
    {
        health -= 1;
        PokeDollars += GetRandomAmountOfPokeDollars();
        cout << this->name << " status: " << endl;
        cout << "Health: " << health << endl;
        cout << "PokeDollars: " << PokeDollars << endl;
        cout << "Experience: " << experience << endl;
        
        if(UpdateLocation())
        {
            state = IN_GYM;
            current_gym->AddOneTrainer();
            return true;
        }
        else
        {
            return false;
        }
    }

    else if (state == MOVING_TO_CENTER)
    {
        health -= 1;
        PokeDollars += GetRandomAmountOfPokeDollars();
        cout << this->name << " status: " << endl;
        cout << "Health: " << health << endl;
        cout << "PokeDollars: " << PokeDollars << endl;
        cout << "Experience: " << experience << endl;
        
        if(UpdateLocation())
        {
            state = AT_CENTER;
            current_center->AddOneTrainer();
            return true;
        }
        else
        {
            return false;
        }
    }

    else if (state == IN_GYM)
    {
        cout << this->name << " status: " << endl;
        cout << "Health: " << health << endl;
        cout << "PokeDollars: " << PokeDollars << endl;
        cout << "Experience: " << experience << endl;
        return false;
    }

    else if (state == AT_CENTER)
    {
        cout << this->name << " status: " << endl;
        cout << "Health: " << health << endl;
        cout << "PokeDollars: " << PokeDollars << endl;
        cout << "Experience: " << experience << endl;
        return false;
    }

    else if (state == BATTLING_IN_GYM)
    {   
        state = IN_GYM;
        cout << name << " completed " << battles_to_buy << " battle(s)!" << endl;
        cout << name << " gained " << (battles_to_buy*(current_gym->GetExperiencePerBattle())) << " experience" << endl;
        cout << this->name << " status: " << endl;
        cout << "Health: " << health << endl;
        cout << "PokeDollars: " << PokeDollars << endl;
        cout << "Experience: " << experience << endl;
        return true;
    }

    else if (state == RECOVERING_HEALTH)
    {
        unsigned int health_gained = 5*potions_to_buy;
        health += health_gained;
        cout << "** " << name << " recovered " << health_gained << " health!**" << endl;
        cout << "** " << name << " bought " << potions_to_buy << " potion(s)!**" << endl;
        cout << this->name << " status: " << endl;
        cout << "Health: " << health << endl;
        cout << "PokeDollars: " << PokeDollars << endl;
        cout << "Experience: " << experience << endl;
        state = AT_CENTER;
        return true;
    }
    return false;
}



double GetRandomAmountOfPokeDollars()
{
    srand(time(NULL));
    double pokedollar_amount = (double)rand()/RAND_MAX;
    return pokedollar_amount*(2.0-0.0);
}

//Function added to make it possible to access Trainer name
string Trainer :: GetName()
{
    return name;
}


//added following setter
void Trainer::SetFollowing(bool in_follow) {
    following = in_follow;
}

//getter for following
bool Trainer::GetFollowing() {
    return following;
}

//health setter
void Trainer::SetHealth(unsigned int in_health) {
    health = in_health;
}

//health getter
unsigned int Trainer::GetHealth() {
    return health;
}