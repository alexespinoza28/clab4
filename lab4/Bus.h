//
//  Bus.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#ifndef Bus_h
#define Bus_h
#include <random>
#include "map.h"
class Bus: public Vehicle {
public:
    Bus() {
   
        name = genName(); //either school or MBTA

    }
    
    bool canMove() {
        
        return false;
    }
    
    void moveBus() {
        
    }
   
private:
    Place* occupiedSpaces[4];
    int passengers;
    
    string genName() {
        // get random seed from os
        random_device rd;
        // Number generator
        mt19937 gen(rd());
        // Give range for numbers
        uniform_int_distribution<> distr(0, 1);
        // Get number
        int x = distr(gen);
        return (x == 0) ? "school" : "MBTA";
    }
};

#endif /* Bus_h */
