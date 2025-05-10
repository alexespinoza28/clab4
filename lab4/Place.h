//
//  Place.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#ifndef Place_h
#define Place_h
using namespace std;
class Road;
class Place {

public:
    char identifier = ' ';
    friend class Road;
    Place() {
        isFreeFlag = true;
        neighborsCount = 0;
        
        for (Place* p: adjacent) {
            p = nullptr;
        }
    }
    
    //use this to easily see if an vehicle can move half of its length. ie if front of bus place list Place has < 2 consecutive neighbors, it cannot move forward.
    int freeConsecutiveNeighbors() {
        int count = 0;
        for (int i = 0; i < 4; i++) {
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
    Place* next() {
        return adjacent[0];
    }
    
    
private:
    int neighborsCount; // use to make sure we dont overassign adjecent places
    Place* adjacent[4];
    bool isFreeFlag;
    
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
