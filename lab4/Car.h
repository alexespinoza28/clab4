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
    

    Car(string color) {
        this->color = color;
        length = 2;
    }
    
    bool freeToMove() {
        int x = placeList.back()->freeConsecutiveNeighbors();
        if (x >= length/2) {
            return true;
        }
        return false;
    }
    
    void move() {
        if (!freeToMove()){
            return;
        }
        //move one place forward and delete one place back
        placeList.back()->next()->occupy();
        placeList.push_back(placeList.back()->next());
        
        placeList.front()->free();
        placeList.pop_front();
     
    }
   
    
    private:
    
    
 
    static const vector<string> colorMap ;

    string color;
};

#endif /* Car_h */
