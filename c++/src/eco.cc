//=============================================================================
// C++ simple Ecosystem emulator to illustate C++ OOP abilites
// © George Papanikolaou 2011-2014
// See LICENSE at the root of the repo
//=============================================================================

// TODO: hey stupid old me.! Do you really need all of these shit???
#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
#include <cstdlib>
#include "organisms.cc"

using namespace std;

// Metadata of all available organisms
// TODO: wow... such c++ much idiomatisms
vector<string> orgs = {"Phytoplankton" "Zooplankton" "Squid" "Milittus"
                    "Octopus" "Shrimp" "Crab" "Sprattus" "Shark" "Dolphin"};

//
// Generate a random digit between arguments
//
int random(int low, int high)
{  
    int diff = high - low + 1;

    return(low + rand() % diff);
} 

//
// Generate a random organism
//
Organism gen_random_org(int digit)
{
    int randomIndex = rand() % orgs.size();

    switch (orgs[randomIndex]) {
    case "Phytoplankton": // I don't think that's C++...
        a = new Phytoplankton();
        break;
    case "Zooplankton":
        a = new Zooplankton();
        break;
    case "Squid":
        a = new Squid();
        break;
    case "Milittus":
        a = new Milittus();
        break;
    case "Octopus":
        a = new Octopus();
        break;
    case "Shrimp":
        a = new Shrimp();
        break;
    case "Crab":
        a = new Crab();
        break;
    case "Sprattus":
        a = new Sprattus();
        break;
    case "Dolphin":
        a = new Dolphin();
        break;
    case "Shark":
        a = new Shark();
        break;
    default:
        fatal("well implement a fatal function first");
    }
    return a;
}

class World {
public:
    int dim_x;
    int dim_y;
    int org_count;
    Organism* map; // TODO

    //
    // Initializers
    //
    World()
    {
        // TODO
    }

    traverse_map()
    {
        // TODO
    }

    init_world()
    {
        // TODO
    }

    step()
    {
        // TODO
    }

    add()
    {
        // TODO
    }

    infect()
    {
        // TODO
    }

private:
    // TODO: add data here
};

int main(void)
{
    cout << "Welcome to this (hardly) funny little game. :)" << endl;
    cout << "Generating the map..." << endl;
    world = new World();
    cout << "Done. The map will be " << world.dim_x << "x" << world.dim_y << endl;
    // Google suggests using prinf normally and streams like cout for logging, so... TODO
    printf("Options:\tS: step\n\tA: add\n\tV: infect\n\tI: info\n\tR: restart\n\tQ: quit\n");
    while(1) {
        printf(">>> Main menu <<<\n");
        // get user input here.... in 'input' var
        switch(input) {
        case 's': case 'S':
            world.step();
            break;
        case 'a': case 'A':
            user_add(); // <-- TODO
            break;
        case 'v': case 'V':
            user_infect(); // <-- TODO
            break;
        case 'i': case 'I':
            world.info();
            break;
        case 'r': case 'R':
            world.init_world();
            break;
        case 'q': case 'Q': default:
            exit(EXIT_SUCCESS);
        }
    }
}
