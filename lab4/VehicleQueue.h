//
//  VehicleQueue.h
//  lab4
//
//  Created by maest on 5/8/25.
//

#ifndef VehicleQueue_h
#define VehicleQueue_h

//
//  VehicleQuene.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#include "TrafficLight.h"
#include "Road.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"
#include "Truck.h"
#include <queue>
#include <random>
#include <ctime>
#include <deque>
using namespace std;
class VehicleQueue {
private:
    deque<Vehicle*> q;
    Direction direction;
    Color lightColor;
    Road* road;
    
public:
    VehicleQueue(Color lightColor, Direction direction, Road* road) {
        this->lightColor = lightColor;
        this->direction = direction;
        this->road = road;
    }
    void moveVehicles() {
        switch(lightColor) {
            case green:
                
                break;
        }
        
        
    }
    void spawnVehicle() {
        static default_random_engine engine(static_cast<unsigned>(time(0)));
        uniform_int_distribution<int> dist(1, 100);

        int roll = dist(engine);
        
        Vehicle* newVehicle = nullptr;
        if (roll <= 50) {
            newVehicle = new Car(road);
            q.push_back(newVehicle);
        } else if (roll <= 70) {
            newVehicle = new Bus(road);
            q.push_back(newVehicle);
        } else if (roll <= 90) {
            newVehicle = new Truck(road);
            q.push_back(newVehicle);
        } else {
            newVehicle = new Motorcycle(road);
            q.push_back(newVehicle);
        }

       
    }
};



#endif /* VehicleQueue_h */
