//
//  Vehicle.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#ifndef Vehicle_h
#define Vehicle_h
#include "Place.h"
#include <vector>
#include <deque>
using namespace std;

enum Direction {
    north,
    west,
    south,
    east
};

class Vehicle {
protected:
    static const std::vector<std::string> colorMap;
    
    string name;
    int speed;
    int length;
    double weight;
    deque<Place*> placeList;
    bool moveForward;
    Direction direction;
    
    
    
public:
    
    Vehicle() {
        speed = 0;
        weight = 0;
        moveForward = false;
    }
    
    virtual bool freeToMove() const = 0;  // pure virtual, freeToMove depends on vehicle length
    virtual void move() const = 0;
    private:
   
    
};

#endif /* Vehicle_h */
