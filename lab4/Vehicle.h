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
#include <tuple>
#include "Road.h"
#include "TrafficLight.h"
using namespace std;



class Vehicle {
protected:
    static const std::vector<std::string> colorMap;
    tuple<Direction, int> road_index;
    string name;
    int speed;
    int length;
    double weight;
    deque<Place*> placeList;
    bool moveForward;
    Direction direction;
    Road* road;
    char identifier = ' ';
    
    
public:


    //assign first places of road to vehicle
    Vehicle(Road* road) {
        if (!road) throw std::invalid_argument("Road pointer cannot be null");
        this->road = road;
        this->direction = road->getDirection();
        speed = 0;
        weight = 0;
        moveForward = false;
        for (int i = 0; i < length; i++) {
            placeList.push_back(road->getPlaceAt(i));
            road->getPlaceAt(i)->markFree();
        }
    }
    bool atEndOfRoad() const {
        return placeList.back() == road->getPlaceAt(road->getNumPlaces() - 1);
    }
    
    //need to replace road is vehicle turns onto another road, may make this private since only the turn method will actually replace the road but well see
    void replaceRoad(Road* road) {
        this->road = road;
    }

    //returns negative if in front of the intersection, returns positive if before the intersection, returns 0 if at the intersection
    int intersectionRadius(){
        if(get<1>(road_index)+1 == road->getNumPlaces()/2 || get<1>(road_index)+1 == (road->getNumPlaces()/2) + 1){
            return 0;
        }
        else if(get<1>(road_index)+1 < road->getNumPlaces()/2){
            return ((road->getNumPlaces()/2) - get<1>(road_index)+1);
        }
        else if(get<1>(road_index)+1 > (road->getNumPlaces()/2) + 1){
            return ((road->getNumPlaces()/2) + 1 - get<1>(road_index)+1);
        }
        return -999;
    }
    
    bool isOnIntersection() {
        for (Place* p: placeList) {
            for (Place* x: Road::sharedIntersectionPlaces) {
                if (p == x) {
                    return true;
                }
            }
        }
        return false;
    }
    
    //want to use this method if the vehicle is about to hit the intersection, in order to figure otu wheter to turn or go straight
    bool isBeforeIntersection() {
        for (Place* x : Road::sharedIntersectionPlaces) {
            if (placeList.back()->next() == x) {
                return true;
            }
        }
        return false;
    }
    
    Road* getRoad() {
        return this->road;
    }
    

    Direction rightTurn(Direction direction){
        switch(direction){
            case north:
                return east;

            case south:
                return west;

            case west:
                return north;

            case east:
                return south;

        }
    }



    virtual bool freeToMove()  = 0;  // pure virtual, freeToMove depends on vehicle length
    //virtual void turn();
    virtual void move()  = 0;
    virtual ~Vehicle() = default;
    private:
   
    

    
};

#endif /* Vehicle_h */
