//
//  main.cpp
//  lab4
//
//  Created by maest on 4/3/25.
//

#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"

#include "Bus.h"
#include "Motorcycle.h"
#include "TrafficLight.h"
#include "Road.h"
#include "Place.h"
#include "Time.h"

using namespace std;

const vector<string> Vehicle::colorMap = {
    "Red", "Black", "Blue", "White", "Yellow", "Orange",
    "Magenta", "Dark Blue", "Grey", "Beige", "Brown", "Purple"
};


string temp_func(Color color){
    switch(color){
        case Color::red:
            return "red";
        
        case Color::green:
            return "green";

        case Color::yellow:
            return "yellow";
    }
}

int main(int argc, const char * argv[]) {
   
    
    TrafficLight light = TrafficLight(3,1);
    Time timer = Time(2, &light);

    while(true){
        if(timer.getElapsedTime() == 20){
            break;
        }
        cout<<"elapsed time: "<<timer.getElapsedTime()<<endl;
        cout<<"north color: "<<temp_func(light.getColor(Direction::north))<<endl;
        cout<<"south color: "<<temp_func(light.getColor(Direction::south))<<endl;
        cout<<"west color: "<<temp_func(light.getColor(Direction::west))<<endl;
        cout<<"east color: "<<temp_func(light.getColor(Direction::east))<<endl;
        timer.tick();
    }
    
    return 0;
}
