/* This is a system function to generate random numbers where I need. */
int RandomInteger(int low, int high) {  
    int k;
    int dif=high-low+1; 
    k = low + rand() % dif; 
    return k;  
} 

// This is the main function for time operations
void wait(int seconds) {
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {/* Nothing to see here */}
}

// Organism creator function:
Organism create_Organism (int digit) {
    NON B;
    if (digit==0) { return B; }   // just a abstract pointer for non-animal cell
    else if (digit==1) { return B; } 
    else if (digit==2) { return B; } 
    else if (digit==3) { return B; } 
    else if (digit==4) { Phytoplankton X; return X; } /*****************************/
    else if (digit==5) { Phytoplankton X; return X; } /*   Phytoplankton creation  */
    else if (digit==6) { Phytoplankton X; return X; } /* The same times as "empty" */
    else if (digit==7) { Phytoplankton X; return X; } /*****************************/
    else if (digit==8) { Zooplankton X; return X; } 
    else if (digit==9) { Zooplankton X; return X; }
    else if (digit==10) { Zooplankton X; return X; }
    else if (digit==11) { Squid X; return X; } 
    else if (digit==12) { Squid X; return X; }
    else if (digit==13) { Mylittus X; return X; } 
    else if (digit==14) { Mylittus X; return X; } 
    else if (digit==15) { Shrimp X; return X; } 
    else if (digit==16) { Shrimp X; return X; } 
    else if (digit==17) { Shrimp X; return X; } 
    else if (digit==18) { Octopus X; return X; } 
    else if (digit==19) { Crab X; return X; } 
    else if (digit==20) { Sprattus X; return X; } 
    else if (digit==21) { Dolphin X; return X; }    // These are for the reproduction and the add option. NO RANDOM.
    else if (digit==22) { Shark X; return X; } 
}
