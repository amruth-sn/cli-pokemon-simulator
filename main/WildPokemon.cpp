#include "WildPokemon.h"
#include "Trainer.h"
using namespace std;

WildPokemon::WildPokemon(string in_name, double in_attack, double in_health, bool in_variant, int in_id, Point2D in_loc) : GameObject() {
    attack = in_attack;
    display_code = 'W';
    health = in_health;
    variant = in_variant;
    in_combat = false;
    name = in_name;
    id_num = in_id;
    location = in_loc;
    state = IN_ENVIORNMENT;
}

void WildPokemon::follow(Trainer* trainer) {
    if(state != DEAD && (trainer->GetState()==MOVING || trainer->GetState() == MOVING_TO_CENTER || trainer->GetState() == MOVING_TO_GYM)){
    if((abs((int)trainer->GetLocation().x - (int)location.x))<=1 && abs(((int)trainer->GetLocation().y - (int)location.y)) <= 1){
        location = trainer->GetLocation();
        health = health - 1;
        state = IN_TRAINER;
    }else if(abs(((int)trainer->GetLocation().x - (int)location.x))<=2 && abs(((int)trainer->GetLocation().y - (int)location.y)) <=2){
        Point2D destination = trainer->GetLocation();
        location = location + (destination - location)*(2/GetDistanceBetween(destination,location));
        state = IN_TRAINER;
    }else{
        state = IN_ENVIORNMENT;
    }
    }
}


bool WildPokemon::get_variant() {
    return variant;
}

double WildPokemon::get_attack() {
    return attack;
}

double WildPokemon::get_health() {
    return health;
}

bool WildPokemon::get_in_combat() {
    return in_combat;
}

bool WildPokemon::Update() {
    if (health <= 0) {
        state = DEAD;
        return false;
    }

    switch (state) {
        case 0:
            return false;
            break;
        case 2:
            if (!in_combat) {
                in_combat = true;
                follow(current_trainer);
            }
            follow(current_trainer);
            return false;
            break;
        default:
            break;
    }
}

void WildPokemon::ShowStatus() {
    cout << "Wild Pokemon status:" << endl;
    GameObject::ShowStatus();
    cout << "Health: " << health << endl;
    switch (state) {
        case IN_ENVIORNMENT:
            cout << "The wild Pokemon is in the environment." << endl;
            break;
        case DEAD:
            cout << "The wild Pokemon is dead!" << endl;
            break;
        case IN_TRAINER:
            cout << "The wild Pokemon is following " << current_trainer->GetName() << "!" << endl;
            break;
    }
}

bool WildPokemon::IsAlive() {
    if (state == DEAD) {
        return false;
    } else {
        return true;
    }
}

bool WildPokemon::ShouldBeVisible() {
    if (IsAlive() == true)
        return true;
    else
        return false;
}

