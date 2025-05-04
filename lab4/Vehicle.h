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
#include "Road.h"
#include "TrafficLight.h"
using namespace std;



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
    
    Road* road;
    
    
public:
    
    Vehicle(Road* road) {
        if (!road) throw std::invalid_argument("Road pointer cannot be null");
        this->road = road;
        this->direction = road->getDirection();
        speed = 0;
        weight = 0;
        moveForward = false;
    }
    bool atEndOfRoad() const {
        return placeList.back() == road->getPlaceAt(road->getNumPlaces() - 1);
    }

    virtual bool freeToMove() const = 0;  // pure virtual, freeToMove depends on vehicle length
    virtual void move() const = 0;
    private:
   
    
};

#endif /* Vehicle_h */
