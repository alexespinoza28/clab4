//
//  Motorcycle.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#ifndef Motorcycle_h
#define Motorcycle_h
#include "map.h"
class Motorcycle: public Vehicle {
public:
    
    Motorcycle() {
        length = 1;
    }
    bool freeToMove() {
        int x = placeList.back()->freeConsecutiveNeighbors();
        if (x >= 1) {
            return true;
        }
        return false;
    }
    
private:
    
    
};

#endif /* Motorcycle_h */
