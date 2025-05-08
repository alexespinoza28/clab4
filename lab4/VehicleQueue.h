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
using namespace std;
class VehicleQueue {
private:
    queue<Vehicle*> q;
    Direction direction;
    Color lightColor;
    Road* road;
    
public:
    VehicleQueue(Color lightColor, Direction direction, Road* road) {
        this->lightColor = lightColor;
        this->direction = direction;
        this->road = road;
    }
    
    void spawnVehicle() {
        static default_random_engine engine(static_cast<unsigned>(time(0)));
        uniform_int_distribution<int> dist(1, 100);

        int roll = dist(engine);
        
        if (roll <= 50) {
            Car* newCar = new Car(road);
        } else if (roll <= 70) {
           Bus* newBus = new Bus(road);
        } else if (roll <= 90) {
            Truck* newTruck = new Truck(road);
        } else {
            Motorcycle* newMotocyle = new Motorcycle(road);
        }

       
    }
};



#endif /* VehicleQueue_h */
