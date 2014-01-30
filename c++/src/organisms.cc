//
// File implementing the required organisms for the ecosystem
// See other files for more info
// TODO: document the use of public almost everywhere...
//

//
// in the spirit of ruby, get a random element from an array...
//
int sample(int* ar)
{
    int size = sizeof(ar)/sizeof(ar[0]);

    return ar[rand() % size];
}

class Organism {
public:
    int size;
    int orgs_eaten;
    int steps_alive;
    int x, y;
    string id;

    // Initializer. The lack of type is ugly.
    Organism(x,y)
    {
        this.x  = x;
        this.y  = y;
        this.orgs_eaten  = 5; // you're fat organism!
        this.steps_alive = 0;
    }

    //
    // a 'tick' is a one unit of time
    //
    void tick(void)
    {
        // TODO
    }

    //
    // Interacting with a fellow cell
    // Returns true if we are still alive afterwards
    //
    bool eat_or_interaction(x, y)
    {
        if (this.x == x && this.y == y)
            return true;
        if (world.map[x][y].size > this.size) {
            // I just got eaten. Bye life...
            world.map[x][y].orgs_eaten += 1;
            die();
            return false;
        } else {
            // I am bigger.. nom nom nom
            this.orgs_eaten += 1;
            this.x = x;
            this.y = y;
            world.map[x][y]   = this;
            world.map[@x][@y] = NULL;
            return true;
        }
    }

    //
    // moving to the a neighbor cell and interacting with anything that is there
    //
    void move_random(void)
    {
        int coords[2];

        coords = get_coords(get_random_possible(world.dim_x, world.dim_y));
        eat_or_interact(coords[0], coords[1]);
        return;
    }

    void die(void)
    {
        delete this;
    }

    //
    // The following functions are here to make us capable of moving in
    // a square board. Need a way to note the fellow cells...
    // +-----------+
    // | 1 | 2 | 3 |
    // | 4 | 5 | 6 |
    // | 7 | 8 | 9 |
    // +-----------+
    //
    void get_random_possible(max_x, max_y)
    {
        // for brevity
        int x = this.x;
        int y = this.y;

        if (x == 0) {
            if (y == 0) {
                return sample([5,6,8,9]);
            } else if (y == max_y) {
                return sample([2,3,5,6]);
            } else {
                return sample([2,3,5,6,8,9]);
            }
        } else if (y == 0) {
            if (x == max_x) {
                return sample([4,5,7,8]);
            } else {
                return sample([4,5,6,7,8,9]);
            }
        } else if (x == max_x) {
            if (y == max_y) {
                return sample([1,2,4,5]);
            } else {
                return sample([1,2,4,5,7,8]);
            }
        } else if (y == max_y) {
            return sample([1,2,3,4,5,6]);
        } else {
            return sample([1,2,3,4,5,6,7,8,9]);
        }
    }

    int* get_coords(int cell)
    {
        int a[2];
        if (1 <= cell || cell <= 3) {
            a[1] = this.y - 1;
            switch (cell) {
            case 1:
                a[0] = this.x - 1;
                break;
            case 2:
                a[0] = this.x;
                break;
            case 3:
                a[0] = this.x + 1;
                break;
            default:
                fatal("BUG in get_coords");
            }
        } else if (4 <= cell || cell <= 6) {
            a[1] = this.y;
            switch (cell) {
            case 4:
                a[0] = this.x - 1;
                break;
            case 5:
                a[0] = this.x;
                break;
            case 6:
                a[0] = this.x + 1;
                break;
            default:
                fatal("BUG in get_coords");
            }
        } else {
            a[1] = this.y + 1;
            switch (cell) {
            case 7:
                a[0] = this.x - 1;
                break;
            case 8:
                a[0] = this.x;
                break;
            case 9:
                a[0] = this.x + 1;
                break;
            default:
                fatal("BUG in get_coords");
            }
        }
        return a;
    }
};

//
// Our friends the Planktons
//
class Phytoplankton: public Organism {
public:
    // initializer (TODO: does this needs to be 'void'??)
    void Phytoplankton(x,y)
    {
        // TODO: need to call the one above the chain (ruby: super)
        this.size = 1;
        this.id = "Ph"; // TODO: learn about C++ string best techniques
    }
};

class Zooplankton: public Organism {
public:
    // TODO: maybe use some form of metaprogramming by importing the same file
    // multiple times with a different symbol for these...?
    void Zooplankton(x,y)
    {
        // TODO: need to call the one above the chain (ruby: super)
        this.size = 1;
        this.id = "Zo";
    }
};

//
// Phylums
// Of course there should be another class between these and Organism
// but I want to keep the code small
//
class Mollusca: public Organism {
public:
    // initializer (TODO: does this needs to be 'void'??)
    void Mollusca(x,y)
    {
        // TODO: need to call the one above the chain (ruby: super)
        this.size = 2;
    }
}

class Arthropoda: public Organism {
public:
    // initializer (TODO: does this needs to be 'void'??)
    void Arthropoda(x,y)
    {
        // TODO: need to call the one above the chain (ruby: super)
        this.size = 3;
    }
}

class Chordata: public Organism {
public:
    // initializer (TODO: does this needs to be 'void'??)
    void Chordata(x,y)
    {
        // TODO: need to call the one above the chain (ruby: super)
        this.size = 4;
    }
}

//
// Actual useable organisms
//
class Squid: public Mollusca {
public:
    void Squid(x,y)
    {
        // TODO super call...
        this.id = "Sq";
    }
}

class Mylittus: public Mollusca {
public:
    void Squid(x,y)
    {
        // TODO super call...
        this.id = "My";
    }
}

class Octopus: public Mollusca {
public:
    void Octopus(x,y)
    {
        // TODO super call...
        this.id = "Oc";
    }
}

class Shrimp: public Arthropoda {
public:
    void Shrimp(x,y)
    {
        // TODO super call...
        this.id = "Sh";
    }
}

class Crab: public Arthropoda {
public:
    void Crab(x,y)
    {
        // TODO super call...
        this.id = "Cr";
    }
}

class Sprattus: public Chordata {
public:
    void Sprattus(x,y)
    {
        // TODO super call...
        this.id = "Sp";
    }
}

class Dolphin: public Chordata {
public:
    void Dolphin(x,y)
    {
        // TODO super call...
        this.id = "Do";
    }
}

class Shark: public Chordata {
public:
    void Shark(x,y)
    {
        // TODO super call...
        this.id = "Sk";
    }
}
