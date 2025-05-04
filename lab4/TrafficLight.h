//
//  TrafficLight.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#ifndef TrafficLight_h
#define TrafficLight_h
#include "map.h"
class TrafficLight {
public:
    
    //inputs are the duration of north/south green light and east/west green light
    TrafficLight(int nsGreen, int ewGreen) {
        
    }
private:
   
    enum Color {
        red,
        green,
        yellow
    };
    
    Place* blockedRoads[4];
    Color lightColor;
    
};

#endif /* TrafficLight_h */
