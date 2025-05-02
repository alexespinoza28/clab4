//
//  main.cpp
//  lab4
//
//  Created by maest on 4/3/25.
//

#include <iostream>
#include "Vehicle.h"
#include "Road.h"
#include "Car.h"
#include "Truck.h"
#include "Place.h"
#include "Bus.h"
#include "Motorcycle.h"
#include "TrafficLight.h"
using namespace std;

const vector<string> Vehicle::colorMap = {
    "Red", "Black", "Blue", "White", "Yellow", "Orange",
    "Magenta", "Dark Blue", "Grey", "Beige", "Brown", "Purple"
};

int main(int argc, const char * argv[]) {
    Road north = Road();
    Road east = Road();
    Road south = Road();
    Road west = Road();
    
    //making an assumption that if i delete one road, all roads are beign deleted so no need to micromanage which ghsraed road pieces stay and go when one road gets deleted. they just all go
    for (Place* p : Road::sharedIntersectionPlaces) {
        delete p;
    }
    Road::sharedIntersectionPlaces.clear();
    return 0;
}
