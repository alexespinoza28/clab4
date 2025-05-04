//
//  Time.h
//  lab4
//
//  Created by maest on 5/4/25.
//

#ifndef Time_h
#define Time_h


class Time {
    public:
    //pause is how long after each tick the system pausues
    Time(int pause){
        this->pause = pause;
    }
    
    private:
    int duration; //how long the simulation has been running (start is 0 seconds)
    int pause;

};

#endif
 /* Time_h */
