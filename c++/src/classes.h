//===================================================
// This is the header file for the Ecosystem project
// See other files for more info
//===================================================

class Organism {
	public:
		int size;       // This can be 0,1,2,3,4 - 0=DEAD
		int age;        // Number of steps they take
		int food;       // Ammount of food they need. This is 0,1,2 and when 0 their size is reducing.
		char alias;     // This is the alias for the map
		int org_eaten;  // The counter for the organisms eaten by this one
		int where_x, where_y;  // Their place in the map
		void interaction(Organism l) {
			// Plankton interaction
			if (  alias==l.alias ) {   
				if ( alias=='P') {
					Organism L = create_Organism(5);                // Creating a "child" organism
					if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
						map[  where_x-1 ][  where_y-1 ] = L;
					map[  where_x+1 ][  where_y+1 ] = L;
				}
				else if ( alias=='Z') {
					Organism L = create_Organism(8);                // Creating a "child" organism
					if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
						map[  where_x-1 ][  where_y-1 ] = L;
					map[  where_x+1 ][  where_y+1 ] = L;
				}
			}
		}
		void move () {
			int movement;
			if ( where_x == 0 ) {
				if (where_y == 0 || where_y == y) {
					movement = RandomInteger(4,6);
				}
				else {
					movement = RandomInteger(4,8);
				}
			}
			else if (where_y == 0 || where_y == y) {
				movement = RandomInteger(2,6);
			}
			else if ( where_x == x ) {
				if (where_y == 0 || where_y == y) {
					movement = RandomInteger(2,4);
				}
				else {
					movement = RandomInteger(1,4);
				}
			}
			else {
				movement = RandomInteger(1,8);
			}
			// The move now:
			if (movement == 1) { interaction( map[where_x-1][where_y-1]); }
			else if (movement == 2) { interaction( map[where_x-1][where_y]); }
			else if (movement == 3) { interaction( map[where_x-1][where_y+1]); }
			else if (movement == 4) { interaction( map[where_x][where_y+1]); }
			else if (movement == 5) { interaction( map[where_x+1][where_y+1]); }
			else if (movement == 6) { interaction( map[where_x+1][where_y]); }
			else if (movement == 7) { interaction( map[where_x+1][where_y-1]); }
			else { interaction( map[where_x][where_y-1]); }
			// NO FOOD OR SIZE CHECK. The Plankton cannot die from age/size so it can provide food to the supreme organisms.
			age++;
		}
};

class NON: public Organism {  // A subclass for cells without organisms
	public:
		NON () {
			char alias = 'O';
			int size = 0;
		}
		void interaction(Organism* l) {}
		void move () {}
};

class Plankton: public Organism {
	public:
};

class Zooplankton: public Plankton {
	public:
		Zooplankton() {
			char alias = 'Z';
			int size = 1;
		}
};

class Phytoplankton: public Plankton {
	public:
		Phytoplankton() {
			char alias = 'P';
			int size = 1;
		}
};

class NPlankton: public Organism {
	public:
		void interaction(Organism l) {
			// This is the main interaction function for stuff like eating and reproduction
			if (  alias==l.alias ) {   
				if ( alias=='P') {
					Organism L = create_Organism(5);                // Creating a "child" organism
					if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
						map[  where_x-1 ][  where_y-1 ] = L;
					map[  where_x+1 ][  where_y+1 ] = L;
				}
				else if ( alias=='Z') {
					Organism L = create_Organism(8);                // Creating a "child" organism
					if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
						map[  where_x-1 ][  where_y-1 ] = L;
					map[  where_x+1 ][  where_y+1 ] = L;
				}
				else if ( alias=='K') {
					Organism L = create_Organism(11);                // Creating a "child" organism
					if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
						map[  where_x-1 ][  where_y-1 ] = L;
					map[  where_x+1 ][  where_y+1 ] = L;
				}       
				else if ( alias=='M') {
					Organism L = create_Organism(13);                // Creating a "child" organism
					if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
						map[  where_x-1 ][  where_y-1 ] = L;
					map[  where_x+1 ][  where_y+1 ] = L;
				}
				else if ( alias=='G') {
					Organism L = create_Organism(15);                // Creating a "child" organism
					if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
						map[  where_x-1 ][  where_y-1 ] = L;
					map[  where_x+1 ][  where_y+1 ] = L;
				}
				else if ( alias=='T') {
					Organism L = create_Organism(18);                // Creating a "child" organism
					if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
						map[  where_x-1 ][  where_y-1 ] = L;
					map[  where_x+1 ][  where_y+1 ] = L;
				}
				else if ( alias=='C') {
					Organism L = create_Organism(19);                // Creating a "child" organism
					if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
						map[  where_x-1 ][  where_y-1 ] = L;
					map[  where_x+1 ][  where_y+1 ] = L;
				}
				else if ( alias=='A') {
					Organism L = create_Organism(20);                // Creating a "child" organism
					if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
						map[  where_x-1 ][  where_y-1 ] = L;
					map[  where_x+1 ][  where_y+1 ] = L;
				}
				else if ( alias=='S') {
					Organism L = create_Organism(22);                // Creating a "child" organism
					if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
						map[  where_x-1 ][  where_y-1 ] = L;
					map[  where_x+1 ][  where_y+1 ] = L;
				}
				else if ( alias=='D') {
					Organism L = create_Organism(21);                // Creating a "child" organism
					if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
						map[  where_x-1 ][  where_y-1 ] = L;
					map[  where_x+1 ][  where_y+1 ] = L;
				}
			}
			else {
				// The Eating Option: (Only to N-Plankton)
				if (  size > l.size ) {
					map[l.where_x][l.where_y] = this  // This Object
						map[ where_x][ where_y] = E;      // The l organism is no more.
					// Food code:
					if ( size-1==l.size ) {
						food = 3;                     // Size-depended growth and food. 
						size++;
					}
					else {
						food = 2;
					}
					org_eaten++;
				}
				else {
					map[ where_x][ where_y] = l;
					map[l.where_x][l.where_y] = E;      // The organism is no more.
					if (l.size-1 == size) {
						l.food = 3;
						l.size++;
					}
					else {
						l.food=2;
					}
					l.org_eaten++;
				}
			}
		}
		void move () {                  // The move function for NPlankton organisms with the ability to die.
			int movement;
			if ( where_x == 0 ) {
				if (where_y == 0 || where_y == y) {
					movement = RandomInteger(4,6);
				}
				else {
					movement = RandomInteger(4,8);
				}
			}
			else if (where_y == 0 || where_y == y) {
				movement = RandomInteger(2,6);
			}
			else if ( where_x == x ) {
				if (where_y == 0 || where_y == y) {
					movement = RandomInteger(2,4);
				}
				else {
					movement = RandomInteger(1,4);
				}
			}
			else {
				movement = RandomInteger(1,8);
			}
			// The move now:
			if (movement == 1) { interaction( map[where_x-1][where_y-1]); }
			else if (movement == 2) { interaction( map[where_x-1][where_y]); }
			else if (movement == 3) { interaction( map[where_x-1][where_y+1]); }
			else if (movement == 4) { interaction( map[where_x][where_y+1]); }
			else if (movement == 5) { interaction( map[where_x+1][where_y+1]); }
			else if (movement == 6) { interaction( map[where_x+1][where_y]); }
			else if (movement == 7) { interaction( map[where_x+1][where_y-1]); }
			else { interaction( map[where_x][where_y-1]); }
			// Food size check now:
			if (food=0) size--;       // Size reduced due to no food for 2 steps
			else food--;
			// Size check:
			if (size==0) {
				map[where_x][where_y] = E;      // Death.
				dead_org++;
			}
			age++;
		}
}

class Invertebrate: public NPlankton {
	public:
}

class Vertebrate: public NPlankton {
	public:
}

class Mollusca: public Invertebrate {
	public:
}

class Arthropoda: public Invertebrate {
	public:
}
// This are the real organism classes:
class Squid: public Mollusca {
	public:
		Squid() {
			char alias = 'K';
			int age = 1;
			int size = 2;
		}
}

class Octopus: public Mollusca {
	public:
		Octopus() {
			char alias = 'T';
			int age = 1;
			int size = 3;
		}
}

class Mylittus: public Mollusca {
	public:
		Mylittus() {
			char alias = 'M';
			int age = 1;
			int size = 2;
		}
}

class Crab: public Arthropoda {
	public:
		Crab() {
			char alias = 'C';
			int age = 1;
			int size = 3;
		}
}

class Shrimp: public Arthropoda {
	public:
		Shrimp() {
			char alias = 'G';
			int age = 1;
			int size = 2;
		}
}
// Higher Fish -----------------------
class Chordata: public Vertebrate {
	public:
}

class Sprattus: public Chordata {
	public:
		Sprattus() {
			char alias = 'A';
			int age = 1;
			int size = 3;
		}
}

class Dolphin: public Chordata {
	public:
		Dolphin() {
			char alias = 'D';
			int age = 1;
			int size = 4;
		}
}

class Shark: public Chordata {
	public:
		Shark() {
			char alias = 'S';
			int age = 1;
			int size = 4;
		}
}
