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
#include "Enums.h"

class TrafficLight {
    friend class Time;
public:
    
    //initializes north and south as green, west and east as red
    TrafficLight(int greenDuration, int yellowDuration) {
        this->greenDuration = greenDuration;
        this->yellowDuration  = yellowDuration;
        lightStatus[Direction::west] = Color::red;
        lightStatus[Direction::east] = Color::red;
        lightStatus[Direction::north] = Color::green;
        lightStatus[Direction::south] = Color::green;
        yellowCycle = false;

                
    }

    //returns the light color of a particular direction
    Color getColor(Direction direction){
        return lightStatus[direction];
    }



private:
    //duration green light is active for
    int greenDuration;
    //duration for how long yellow is active for
    int yellowDuration;
    //stores the light status for each direction
    unordered_map<Direction, Color> lightStatus;
    bool yellowCycle;


    //assumes cycle is false, turns green lights to yellow
    void toggleSlow(){
        //if north and south are green
        if(lightStatus[Direction::north] == Color::green && lightStatus[Direction::south] == Color::green){
            lightStatus[Direction::north] = Color::yellow;
            lightStatus[Direction::south] = Color::yellow;
        }
        //if west and east are green
        else if(lightStatus[Direction::west] == Color::green && lightStatus[Direction::east] == Color::green){
            lightStatus[Direction::west] = Color::yellow;
            lightStatus[Direction::east] = Color::yellow;
        }
    }

    //assumes cycle is true, turns yellow to red and red to green
    void toggleSwitch(){
       //if north and south are green
       if(lightStatus[Direction::north] == Color::yellow && lightStatus[Direction::south] == Color::yellow){
        lightStatus[Direction::north] = Color::red;
        lightStatus[Direction::south] = Color::red;
        lightStatus[Direction::east] = Color::green;
        lightStatus[Direction::west] = Color::green;
    }
    //if west and east are green
    else if(lightStatus[Direction::west] == Color::yellow && lightStatus[Direction::east] == Color::yellow){
        lightStatus[Direction::west] = Color::red;
        lightStatus[Direction::east] = Color::red;
        lightStatus[Direction::north] = Color::green;
        lightStatus[Direction::south] = Color::green;

        } 
    }
    

};

#endif /* TrafficLight_h */
