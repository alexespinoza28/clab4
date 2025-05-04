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
    friend class Road;
    Place() {
        free = true;
        neighborsCount = 0;
        
        for (Place* p: adjacent) {
            p = nullptr;
        }
    }
    
    bool freeToMove() {
        
        return false;
    }
    
    Place* next() {
        return nullptr;
    }
    
    
private:
    int neighborsCount; // use to make sure we dont overassign adjecent places
    Place* adjacent[4];
    bool free;
    
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
