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
#include <unordered_map>
using namespace std;
class VehicleQueue {
private:
    
    Direction direction;
    Road* road;
    
public:
    deque<Vehicle*> q;
    static unordered_map<Direction, VehicleQueue*> qMap;
    VehicleQueue(Direction direction, Road* road) {
        
        this->direction = direction;
        this->road = road;
        qMap[direction] = this;
    }
    
    void moveVehicles(Color lightColor) {
        switch(lightColor) {
            case green:
                for (auto it = q.begin(); it != q.end(); ) {
                    Vehicle* v = *it;
                    if (v->atEndOfRoad()) {
                        it = q.erase(it);
                        delete v;
                    } else {
                        v->move();
                        
                        //logic here to take vehicle out of this quene and put it on other road quene
                        
                        ++it;
                    }
                }
                break;

            case yellow:
                for (auto it = q.begin(); it != q.end(); ) {
                    Vehicle* v = *it;
                    if (v->atEndOfRoad()) {
                        it = q.erase(it);
                        delete v;
                    } else if (v->isOnIntersection()) {
                        v->move();
                        ++it;
                    } else {
                        ++it;
                    }
                }
                break;

            case red:
                for (auto it = q.begin(); it != q.end(); ) {
                    Vehicle* v = *it;
                    if (v->atEndOfRoad()) {
                        it = q.erase(it);
                        delete v;
                    } else if (!v->isBeforeIntersection()) {
                        v->move();
                        ++it;
                    } else {
                        ++it;
                    }
                }
                break;
        }
    }
    
    void insertVehicleAfterTurn(Vehicle* v, VehicleQueue* vq) {
        Vehicle* target = vq->closestToIntersection();
        auto it = vq->q.begin();
        while (it != vq->q.end()) {
            if ((*it) == target) {
                break;
            }
            ++it;
        }
        vq->q.insert(it, v);
        
        for (auto it = q.begin(); it != q.end(); ++it) {
            if (*it == v) {
                q.erase(it);
                break;  // Only erase one occurrence
            }
        }
    }
    
    Vehicle* closestToIntersection() {
        int min = 1000;
        Vehicle* bruh = nullptr;
        for (Vehicle* v: q) {
            if (v->intersectionRadius() < 0) {
                break;
            }
            if (v->intersectionRadius() < min) {
                bruh = v;
                break;
            }
        }
        return bruh;
        
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
