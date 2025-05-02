//
//  Truck.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#ifndef Truck_h
#define Truck_h
class Truck: public Vehicle {
public:
    bool canMove() {
        
        return false;
    }
    
    void moveTruck() {
        
    }
    
private:
    
    double cargoWieght;
    
    Place* destinationLocation;
    
    Place* occupiedSpots[5];
};

#endif /* Truck_h */
