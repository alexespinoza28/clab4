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
        
    }
    
private:
    
    Place* occupiedSpot;
};

#endif /* Motorcycle_h */
