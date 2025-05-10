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

// south i = 9(const),  j = 0 -> 19
 //north i = 11(const), j = 19 -> 0
 //east i = 19 -> 0 , j = 11(const)
 //east i = 0 -> 19 , j = 9(const)
 const char LAYOUT[ROAD_SIZE][ROAD_SIZE+1] = {
     "        | | |       ",
     "        | | |       ",
     "        | | |       ",
     "        | | |       ",
     "        | | |       ",
     "        | | |       ",
     "        | | |       ",
     "_______ | | |_______",
     "                    ",
     "________     _______",
     "                    ",
     "________     _______",
     "        | | |       ",
     "        | | |       ",
     "        | | |       ",
     "        | | |       ",
     "        | | |       ",
     "        | | |       ",
     "        | | |       ",
     "        | | |       ",
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

void printIntersectionCharMap() {
   
   // south i = 9(const),  j = 0 -> 19
    //north i = 10(const), j = 19 -> 0
    //west i = 19 -> 0 , j = 8(const)
    //east i = 0 -> 19 , j = 9(const)
    //top intersecton i = 9 - 10 , j =8
    //bottom intersecton i = 9 - 10 , j =9
    char layout[ROAD_SIZE][ROAD_SIZE+1] = {
        "        |  |        ",
        "        |  |        ",
        "        |  |        ",
        "        |  |        ",
        "        |  |        ",
        "        |  |        ",
        "        |  |        ",
        "________|  |________",
        "                    ",
        "                    ",
        "________    ________",
        "        |  |        ",
        "        |  |        ",
        "        |  |        ",
        "        |  |        ",
        "        |  |        ",
        "        |  |        ",
        "        |  |        ",
        "        |  |        ",
        "        |  |        ",
        
    };

    int height = sizeof(layout) / sizeof(layout[0]);
    for (int i = 0; i < height; i++) {
        cout << layout[i] << endl;
    }
}

int main(int argc, const char * argv[]) {
    char printedRoad[ROAD_SIZE][ROAD_SIZE+1];
    Road* north = new Road();
    Road* east = new Road();
    Road* south = new Road();
    Road* west = new Road();
    
    //create a turn map to initialize which road turns onto which other road
    // we need to make this because if a vehicle can turn , then its road must be replaced with the other road that its mapped to
    
   
    TrafficLight light = TrafficLight(3,1);
    Time timer = Time(2, &light);
    
    printIntersectionCharMap();
    
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
        
        
        //psudo code,
        // each iteration call move vehicles and spawn
        //make sure each iteration passes the light object in
    }
    
    //clear memory for road objects
    Road().clearAllMemory();
    return 0;
}
