//
//  Place.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#ifndef Place_h
#define Place_h
#include "Enums.h"

using namespace std;
class Road;
class Place {

public:
    
    //locations on the road char array
    friend class Road;
    Place(int x, int y) {
        this->x = x;
        this->y = y;
        isFreeFlag = true;
        neighborsCount = 0;
        
        for (Place* p: adjacent) {
            p = nullptr;
        }
    }
    
    //use this to easily see if an vehicle can move half of its length. ie if front of bus place list Place has < 2 consecutive neighbors, it cannot move forward.
    int freeConsecutiveNeighbors() {
        int count = 0;
        for (int i = 0; i < neighborsCount; i++) {
            if (((x + i) >=19) || ((y + i) >=19) ) {
                break;
            }
            if (!adjacent[i]->isFree()) {
                break;
            }
            count++;
        }
        return count;
    }
    
    bool isFree() {
        return isFreeFlag;
    }
    void occupy(char identifier) {
        isFreeFlag = false;
        this->identifier = identifier;
    }
    void markFree() {
        isFreeFlag = true;
        identifier = ' ';
    }
    Place* next(bool isOnIntersection, Direction direction) {
        if (!isOnIntersection) {
            return adjacent[0];
        } else {
            return adjacent[1];
        }
    }
    
    
    char getIdentifier() {
        return identifier;
    }
    void setLocation(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    
    void reassignNeighbor(Place* adj, int index) {
        if (index < 0 || index> 4) {
            return;
        }
        adjacent[index] = adj;
        
    }
private:
    int neighborsCount; // use to make sure we dont overassign adjecent places
    Place* adjacent[4];
    char identifier = ' ';
    bool isFreeFlag;
    int x;
    int y;
    void assignAdjecent(Place* adj) {
        if (neighborsCount == 4) {
            //cout << "Place object already has 4 neighbors" << endl;
            return;
        }
        adjacent[neighborsCount] = adj;
        neighborsCount++;
    }
};

#endif /* Place_h */
