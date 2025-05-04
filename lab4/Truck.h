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
    
    void moveTruck() {
        
    }
    
private:
    
    double cargoWieght;
    
    Place* destinationLocation;
    
    
};

#endif /* Truck_h */
