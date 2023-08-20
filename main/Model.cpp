#include "Model.h"

Model :: Model()
{
    time = 0;
    PokemonCenter* C1 = new PokemonCenter(1,1,100,Point2D(1,20));
    PokemonCenter* C2 = new PokemonCenter(2,2,200,Point2D(10,20));
    Trainer* T1 = new Trainer("Ash",1,'T',2,Point2D(5,1));
    Trainer* T2 = new Trainer("Misty",2,'T',1,Point2D(10,1));
    PokemonGym* G1 = new PokemonGym(10,1,2,3,1,Point2D(0,0));
    PokemonGym* G2 = new PokemonGym(20,5,7.5,4,2,Point2D(5,5));
    WildPokemon* W1 = new WildPokemon("Pikachu",5,2,false,1,Point2D(10,12)); //wild
    WildPokemon* W2 = new WildPokemon("Charzard",5,2,false,2,Point2D(15,5)); //wild

    object_ptrs.push_back(C1);
    object_ptrs.push_back(C2);
    object_ptrs.push_back(T1);
    object_ptrs.push_back(T2);
    object_ptrs.push_back(G1);
    object_ptrs.push_back(G2);
    object_ptrs.push_back(W1); //wild
    object_ptrs.push_back(W2); //wild
    active_ptrs.assign(object_ptrs.begin(),object_ptrs.end());

    center_ptrs.push_back(C1);
    center_ptrs.push_back(C2);
    trainer_ptrs.push_back(T1);
    trainer_ptrs.push_back(T2);
    gym_ptrs.push_back(G1);
    gym_ptrs.push_back(G2);
    wild_ptrs.push_back(W1); //wild
    wild_ptrs.push_back(W2); //wild
    cout << "Model default constructed" << endl;
}

Model :: ~Model()
{
    for(list <GameObject*> :: iterator iter1 = object_ptrs.begin(); iter1 != object_ptrs.end(); iter1++)
    {
        delete *iter1;
    }
    cout << "Model destructed" << endl;
}

Trainer* Model :: GetTrainerPtr(int id)
{
    for (list <Trainer*> :: iterator iter1 = trainer_ptrs.begin(); iter1 != trainer_ptrs.end(); iter1++)
    {
        if ((*iter1)->GetId() == id)
            return *iter1;
    }

    return nullptr;
}

PokemonCenter* Model :: GetPokemonCenterPtr(int id)
{
    for(list <PokemonCenter*> :: iterator iter1 =center_ptrs.begin(); iter1 != center_ptrs.end(); iter1++)
    {
        if((*iter1)->GetId() == id)
            return *iter1;
    }
    return nullptr;
}

PokemonGym* Model :: GetPokemonGymPtr(int id)
{
    for(list <PokemonGym*> :: iterator iter1 = gym_ptrs.begin(); iter1 != gym_ptrs.end(); iter1++)
    {
        if((*iter1)->GetId() == id)
            return *iter1; 
    }
    return nullptr;
}

WildPokemon* Model::GetWildPokemonPtr(int id) {
    for(list <WildPokemon*> :: iterator iter1 = wild_ptrs.begin(); iter1 != wild_ptrs.end(); iter1++)
    {
        if((*iter1)->GetId() == id)
            return *iter1; 
    }
    return nullptr;
}



bool Model :: Update()
{
    time++;
    int output = 0;
    int temp1 = 0;
    int temp2 = 0;
    list <GameObject*> :: iterator iter1;
    for(iter1 = active_ptrs.begin(); iter1 != active_ptrs.end(); iter1++)
    {
        if((*iter1)->Update() == true)
        {
            output++;
        }
    }

    for(list <GameObject*> :: iterator iter = active_ptrs.begin(); iter != active_ptrs.end(); iter++)
    {
        if(!(*iter)->ShouldBeVisible())
        {
            active_ptrs.erase(iter);
            break;
        }
    }
    
    list <PokemonGym*> :: iterator iter2;
    for(iter2 = gym_ptrs.begin(); iter2 != gym_ptrs.end(); iter2++)
    {
        if((*iter2)->GetNumBattlesRemaining() == 0)
        {
            temp1++;
        }
    }

    list<Trainer*> :: iterator iter3;
    for(iter3 = trainer_ptrs.begin(); iter3 != trainer_ptrs.end(); iter3++)
    {
        if((*iter3)->HasFainted())
        {
            temp2++;
        }
    }

    if (temp1 == gym_ptrs.size())
    {
        cout << "GAME OVER: You win! All battles done!" << endl;
        exit(0);
    }

    if(temp2 == trainer_ptrs.size())
    {
        cout << "GAME OVER: You lose! All of your Trainers have lost!" << endl;
        exit(0);
    }

    if(output > 0)
    {
        return true;
    }

    return false;
}

void Model :: Display(View& view)
{
    for ( list<GameObject*> :: iterator iter1 = active_ptrs.begin(); iter1 != active_ptrs.end(); iter1++)
    {
        view.Plot(*iter1);
    }
}
void Model :: ShowStatus()
{
    cout << "Time: " << time << endl;
    
    for(list<GameObject*> :: iterator iter1 = active_ptrs.begin(); iter1 != active_ptrs.end(); iter1++ )
    {
        (*iter1)->ShowStatus();
    }
}

void Model :: NewCommand(char type, int in_id, double x, double y)
{
    switch(type)
    {
        case 'c': 
        {
            for(list <PokemonCenter*> :: iterator iter1 = center_ptrs.begin(); iter1 != center_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique Doctor's Office ID");
            }
            PokemonCenter* C = new PokemonCenter(in_id, 100, 2, Point2D(x,y));
            object_ptrs.push_back(C);
            active_ptrs.push_back(C);
            center_ptrs.push_back(C);
            cout << "New PokemonCenter created" << endl;
            break;
        }

        case 'g':
        {    
            for(list <PokemonGym*> :: iterator iter1 = gym_ptrs.begin(); iter1 != gym_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique PokemonGym ID");
            }
            PokemonGym* G = new PokemonGym(25,2,10,5,in_id,Point2D(x,y));
            object_ptrs.push_back(G);
            active_ptrs.push_back(G);
            gym_ptrs.push_back(G);
            cout << "New PokemonGym created" << endl;
            break;
        }

        case 't':
        {
            for(list <Trainer*> :: iterator iter1 = trainer_ptrs.begin(); iter1 != trainer_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique Trainer ID");
            }
            Trainer* T = new Trainer("NewTrainer",in_id,'S',1,Point2D(x,y));
            object_ptrs.push_back(T);
            active_ptrs.push_back(T);
            trainer_ptrs.push_back(T);
            cout << "New Trainer created" << endl;
            break;
        } 
        case 'w':
        {
            for(list <WildPokemon*> :: iterator iter1 = wild_ptrs.begin(); iter1 != wild_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique Trainer ID");
            }
            WildPokemon* W = new WildPokemon("NewWildPokemon",5,2,false,in_id,Point2D(x,y));
            object_ptrs.push_back(W);
            active_ptrs.push_back(W);
            wild_ptrs.push_back(W);
            cout << "New Wild Pokemon created" << endl;
            break;
        }

        default:
        cout << "Unrecognized command code for creating new object" << endl;
    }
}