//
//  TrafficLight.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#ifndef TrafficLight_h
#define TrafficLight_h
#include "Road.h"
#include "Place.h"
#include <unordered_map>

enum Color {
    red,
    green,
    yellow
};
class TrafficLight {
public:
    
    //initializes north and south as green, west and east as red
    TrafficLight() {
        lightStatus[Direction::west] = Color::red;
        lightStatus[Direction::east] = Color::red;
        lightStatus[Direction::north] = Color::green;
        lightStatus[Direction::south] = Color::green;

                
    }

    //returns the light color of a particular direction
    Color getColor(Direction direction){
        return lightStatus[direction];
    }

    //cycles current green lights to yellow
    void cycleYellow(){
        

    }


private:
    //stores the light status for each direction
    unordered_map<Direction, Color> lightStatus;
    

};

#endif /* TrafficLight_h */
