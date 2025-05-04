//
//  Vehicle.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#ifndef Vehicle_h
#define Vehicle_h
#include "map.h"
#include <vector>
using namespace std;
class Vehicle {
protected:
    static const std::vector<std::string> colorMap;
    enum Direction {
        north,
        west,
        south,
        east
    };
    string name;
    int speed;
    double weight;
    vector<Place*> placeList;
    bool moveForward;
    Direction direction;
    
    
    
public:
    
    Vehicle() {
        speed = 0;
        weight = 0;
        moveForward = false;
    }
    
    private:
   
    
};

#endif /* Vehicle_h */
