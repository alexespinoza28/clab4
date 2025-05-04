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
using namespace std;
class Car: public Vehicle {
    public:
    

    Car(string color) {
        this->color = color;
    }
    
    bool canMove() {
        
        return false;
    }
    
    void moveCar() {
        
    }
    
   
    
    private:
    
    
 
    static const vector<string> colorMap ;

    string color;
};

#endif /* Car_h */
