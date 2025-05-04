//
//  Truck.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#ifndef Truck_h
#define Truck_h
#include "Place.h"
class Truck: public Vehicle {
public:
    Truck() {
        length = 5;
    }
    
    bool freeToMove() {
        int x = placeList.back()->freeConsecutiveNeighbors();
        if (x >= length/2) {
            return true;
        }
        return false;
    }
    
    void move() {
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
    
    double cargoWieght;
    
    Place* destinationLocation;
    
    
};

#endif /* Truck_h */
