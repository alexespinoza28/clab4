//
//  Car.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#ifndef Car_h
#define Car_h
#include <string>
#include <unordered_map>
#include "map.h"
#include <vector>
using namespace std;
class Car: public Vehicle {
    public:
    

    Car(Road* road) : Vehicle(road) {
        
        length = 2;
        
        //initialize vehicles place deque with the first however many place objects at the start of each road
        for (int i = 0; i < length; i++) {
            placeList.push_back(road->getPlaceAt(i));
            road->getPlaceAt(i)->occupy(identifier);
        }
        road_index = {road->getDirection(), 0};
        identifier = 'c';

    }
    
    
    bool freeToMove() override {
        int x = placeList.back()->freeConsecutiveNeighbors();
        if (x >= length/2) {
            return true;
        }
        return false;
    }
    
    void move() override {
        if (!freeToMove()) return;

        Place* nextPlace = placeList.back()->next();
        nextPlace->occupy(identifier);
        placeList.push_back(nextPlace);

        placeList.front()->markFree();
        placeList.pop_front();  // correct for deque

        get<1>(road_index) += 1;
    }
   
    
    private:
    
    
 
    static const vector<string> colorMap ;

    string color;
};

#endif /* Car_h */
