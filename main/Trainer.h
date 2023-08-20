#ifndef TRAINER_H
#define TRAINER_H
#include "GameObject.h"
#include "PokemonCenter.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "PokemonGym.h"
#include "Building.h"
#include "math.h"
#include "cstdlib"
#include "time.h"


class Trainer : public GameObject
{
    private:
    double speed;
    bool is_at_center = false, is_in_gym = false;
    unsigned int health = 20, experience = 0, battles_to_buy = 0, potions_to_buy = 0;
    double PokeDollars = 0;
    string name;
    PokemonCenter* current_center = NULL;
    PokemonGym* current_gym = NULL;
    Point2D destination;
    Vector2D delta;

    protected:
    bool UpdateLocation();
    void SetupDestination(Point2D);

    public:
    Trainer(); // Default Constructor
    Trainer(char);
    Trainer(string, int, char, unsigned int, Point2D);
    virtual ~Trainer();
    void StartMoving(Point2D);
    void StartMovingToGym(PokemonGym* gym);
    void StartMovingToCenter(PokemonCenter* center);
    void StartBattling(unsigned int);
    void StartRecoveringHealth(unsigned int);
    void Stop();
    bool HasFainted();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    string GetName();

    bool following; // added boolean
    void SetFollowing(bool); // added setter for following
    bool GetFollowing();
    void SetHealth(unsigned int); // health setter
    unsigned int GetHealth(); // health getter
};




enum TrainerStates
{
    STOPPED = 0,
    MOVING = 1,
    FAINTED = 2,
    AT_CENTER = 3,
    IN_GYM = 4,
    MOVING_TO_CENTER = 5,
    MOVING_TO_GYM = 6,
    BATTLING_IN_GYM = 7,
    RECOVERING_HEALTH = 8,
};

double GetRandomAmountOfPokeDollars();

#endif