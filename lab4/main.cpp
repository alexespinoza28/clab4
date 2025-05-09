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
#include "VehicleQueue.h"
#include "Bus.h"
#include "Motorcycle.h"
#include "TrafficLight.h"
#include "Road.h"
#include "Place.h"
#include "Time.h"
#include <unordered_map>

using namespace std;

const vector<string> Vehicle::colorMap = {
    "Red", "Black", "Blue", "White", "Yellow", "Orange",
    "Magenta", "Dark Blue", "Grey", "Beige", "Brown", "Purple"
};
static const int ROAD_SIZE = 20;

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
    Road* north = new Road();
    Road* east = new Road();
    Road* south = new Road();
    Road* west = new Road();
    
    //create a turn map to initialize which road turns onto which other road
    // we need to make this because if a vehicle can turn , then its road must be replaced with the other road that its mapped to
    
   
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
    
    //clear memory for road objects
    delete north;
    delete east;
    delete south;
    delete west;
    for (Place* p : Road().sharedIntersectionPlaces) {
        delete p;
    }
    Road().sharedIntersectionPlaces.clear(); 
    return 0;
}
