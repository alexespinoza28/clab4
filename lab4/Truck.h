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
    Truck(Road* road) : Vehicle(road) {
        length = 5;
        //initialize vehicles place deque with the first however many place objects at the start of each road
        for (int i = 0; i < length; i++) {
            placeList.push_back(road->getPlaceAt(i));
        }
        road_index = {road->getDirection(), 0};
        identifier = 't';
    }
    
    bool freeToMove() override{
        int x = placeList.back()->freeConsecutiveNeighbors();
        if (x >= length/2) {
            return true;
        }
        return false;
    }
    
    void move() override{
        if (!freeToMove()){
            return;
        }
        //move two places forward and delete two places back
        placeList.back()->next(isOnIntersection(), direction)->occupy(identifier);
        placeList.push_back(placeList.back()->next(isOnIntersection(), direction));
        placeList.back()->next(isOnIntersection(), direction)->occupy(identifier);
        placeList.push_back(placeList.back()->next(isOnIntersection(), direction));
       
        placeList.front()->markFree();
        placeList.pop_front();
        placeList.front()->markFree();
        placeList.pop_front();

        get<1>(road_index) += 2;
    }
    
private:
    
    double cargoWieght;
    
    Place* destinationLocation;
    
    
};

#endif /* Truck_h */
