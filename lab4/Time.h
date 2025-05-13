//
//  Time.h
//  lab4
//
//  Created by maest on 5/4/25.
//

#ifndef Time_h
#define Time_h
#include <chrono>
#include <thread>
#include "TrafficLight.h"
#include "Enums.h"
using namespace std;


class Time {
    public:

    //pause is how long after each tick the system pausues
    Time(int pause, TrafficLight* light){
        this->light = light;
        this->pause = pause;
        duration = 0;
        cycleTimer = 0;
    }

    void tick(){
        //during green cycle
        if(!light->yellowCycle){

            cycleTimer += 1;
            //when the timer reaches the duration
            if(cycleTimer == light->greenDuration){
                light->toggleSlow();
                cycleTimer = 0;
                light->yellowCycle = true;
            }
        }
        //during yellow cycle
        else if(light->yellowCycle){
            cycleTimer += 1;
            //when the timer reaches the duration
            if(cycleTimer == light->yellowDuration){
                light->toggleSwitch();
                cycleTimer = 0;
                light->yellowCycle = false;
            }

        }
        //this_thread::sleep_for(chrono::seconds(pause));
        duration += 1;
    }

    int getElapsedTime(){
        return duration;
    }
    
    private:
    TrafficLight *light;
    int duration; //how long the simulation has been running (start is 0 seconds)
    int pause;
    //temporary timer for keeping track of green and yellow durations
    int cycleTimer;


};

#endif
 /* Time_h */
