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
#include <thread>
#include <chrono>

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

void printIntersectionCharMap(Road* north, Road* south, Road* east, Road* west) {
   
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
    north->populateRoad(layout);
    south->populateRoad(layout);
    east->populateRoad(layout);
    west->populateRoad(layout); 
    for (int i = 0; i < ROAD_SIZE; i++) {
        for (int j = 0; j < ROAD_SIZE; j++) {
            cout << layout[i][j];
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    Road* north = new Road();
    Road* east = new Road();
    Road* south = new Road();
    Road* west = new Road();
    
    VehicleQueue* northVq = new VehicleQueue(Direction::north, north);
    VehicleQueue* eastVq = new VehicleQueue(Direction::east, east);
    VehicleQueue* southVq = new VehicleQueue(Direction::south, south);
    VehicleQueue* westVq = new VehicleQueue(Direction::west, west);
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
        northVq->moveVehicles(light.getColor(Direction::north));
        eastVq->moveVehicles(light.getColor(Direction::east));
        southVq->moveVehicles(light.getColor(Direction::south));
        westVq->moveVehicles(light.getColor(Direction::west));
        
        northVq->spawnVehicle();
        eastVq->spawnVehicle();
        westVq->spawnVehicle();
        southVq->spawnVehicle();
        
        
        printIntersectionCharMap(north,east,south,west);
        cout << " " << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        //psudo code,
        // each iteration call move vehicles and spawn
        //make sure each iteration passes the light object in
        
    }
    
    //clear memory for road objects
    Road().clearAllMemory();
    return 0;
}
