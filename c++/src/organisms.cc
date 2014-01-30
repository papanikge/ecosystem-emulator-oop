//
// File implementing the required organisms for the ecosystem
// See other files for more info
// TODO: document the use of public almost everywhere...
//

class Organism {
    public:
    int size;
    int id;
    int orgs_eaten;
    int steps_alive;
    int x, y;

    // Initializer
    Organism(x,y)
    {
        this.x  = x;
        this.y  = y;
        this.orgs_eaten  = 5; // you're fat organism!
        this.steps_alive = 0;
    }

    void eat_or_interaction(Organism l)
    {
        // TODO
    }

    void move_random()
    {
        // TODO
    }

    void die()
    {
        // TODO
    }

    void get_coords()
    {
        // TODO
    }

    void get_random_possible()
    {
        // TODO
    }

    //
    // one unit of time
    //
    void tick()
    {
        // TODO
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
