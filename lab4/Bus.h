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
    Bus(Road* road) : Vehicle(road){
        length = 4;
        name = genName(); //either school or MBTA
        //initialize vehicles place deque with the first however many place objects at the start of each road
        for (int i = 0; i < length; i++) {
            placeList.push_back(road->getPlaceAt(i));
        }
    }
    bool freeToMove() override{
        int x = placeList.back()->freeConsecutiveNeighbors();
        if (x >= length/2) {
            return true;
        }
        return false;
    }
   
    void move() override{
        //move two places forward and delete two places back
        placeList.back()->next()->occupy();
        placeList.push_back(placeList.back()->next());
        placeList.back()->next()->occupy();
        placeList.push_back(placeList.back()->next());
       
        placeList.front()->markFree();
        placeList.pop_front();
        placeList.front()->markFree();
        placeList.pop_front();
    }
   
private:
    
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
