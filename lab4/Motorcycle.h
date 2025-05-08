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
    
    Motorcycle(Road* road) : Vehicle(road) {
        length = 1;
        
        //initialize vehicles place deque with the first however many place objects at the start of each road
        for (int i = 0; i < length; i++) {
            placeList.push_back(road->getPlaceAt(i));
        }

    }
    bool freeToMove() override{
        int x = placeList.back()->freeConsecutiveNeighbors();
        if (x >= 1) {
            return true;
        }
        return false;
    }
    
    void move() override{
        if (!freeToMove()){
            return;
        }
        placeList.back()->next()->occupy();
        placeList.push_back(placeList.back()->next());
        placeList.front()->markFree();
        placeList.pop_front();
    }
private:
    
    
};

#endif /* Motorcycle_h */
