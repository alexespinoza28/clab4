//
//  Road.h
//  lab4
//
//  Created by maest on 4/3/25.
//

#ifndef Road_h
#define Road_h
#include <list>
#include "Place.h"
#include "Enums.h"
using namespace std;


class Road {
   
public:
    static inline int northI = 19;
    static inline int northJ = 10;
    static inline int southI = 0;
    static inline int southJ = 9;
    static inline int westI = 9;
    static inline int westJ = 19;
    static inline int eastI = 10;
    static inline int eastJ = 0;
    static inline vector<Place*> sharedIntersectionPlaces;
    static inline void clearAllMemory() {
        for (Place* p : sharedIntersectionPlaces) {
            if (p) {
                delete p;
            }
        }
        sharedIntersectionPlaces.clear();
    }
    static inline void reIndexIntersection(Road* north, Road* south, Road* east, Road* west) {
        
        Place* one = sharedIntersectionPlaces[0];
        Place* two = sharedIntersectionPlaces[1];
        Place* three = sharedIntersectionPlaces[2];
        Place* four = sharedIntersectionPlaces[3];
        
        one->reassignNeighbor(two, 0);
        one->reassignNeighbor(east->getPlaceAt(27), 1);
        one->reassignNeighbor(three, 2);
        one->reassignNeighbor(north->getPlaceAt(24), 3);
        
        two->reassignNeighbor(north->getPlaceAt(27), 0);
        two->reassignNeighbor(west->getPlaceAt(24), 1);
        two->reassignNeighbor(four, 2);
        two->reassignNeighbor(one, 3);
        
        three->reassignNeighbor(four, 0);
        three->reassignNeighbor(one, 1);
        three->reassignNeighbor(east->getPlaceAt(24), 2);
        three->reassignNeighbor(south->getPlaceAt(27), 3);
        
        four->reassignNeighbor(south->getPlaceAt(24), 0);
        four->reassignNeighbor(two, 1);
        four->reassignNeighbor(west->getPlaceAt(27), 2);
        four->reassignNeighbor(three, 3);
    }
    Road() {
        if (roadCount == 0) {
            this->direction = Direction::north;
        } else if (roadCount == 1) {
            this->direction = Direction::east;
        } else if (roadCount == 2) {
            this->direction = Direction::south;
        } else {
            this->direction = Direction::west;
        }
        
        //now we need to initialize our places which link to each other
        for (int i = 0; i < numPlaces; i++) {
            //  ROAD 0, North
            if (roadCount == 0) {
                Place* p = new Place(northI,northJ);
                northI--;
                placeList.push_back(p);
                // num places/2 is 25 and + 1 is 26
                if (i == numPlaces/2 || i == (numPlaces/2) + 1) {
                    sharedIntersectionPlaces.push_back(p);  // 0 = 25, 1 = 26
                }

            // ROAD 1
            } else if (roadCount == 1) {
                if (i == (numPlaces/2) + 1) {
                    placeList.push_back(sharedIntersectionPlaces[0]);  // want road 0 25
                } else {
                    placeList.push_back(new Place(eastI,eastJ));
                    eastJ++;
                    if (i == numPlaces/2) {
                        sharedIntersectionPlaces.push_back(placeList.back()); //vec2 = road 1 25
                    }
                }

            // ROAD 2
            } else if (roadCount == 2) {
                if (i == (numPlaces/2) + 1) {
                    placeList.push_back(sharedIntersectionPlaces[2]);  // index 25 of road 1
                } else {
                    Place* p = new Place(southI,southJ);
                    southI++;
                    placeList.push_back(p);
                    if (i == numPlaces/2) {
                        sharedIntersectionPlaces.push_back(p);  // 3 = Road 2 index 25
                    }
                }
                

            //  ROAD 3
            // so now 25 of south  i = 3 and 25 of north i = 0 go to east 25 and 26
            } else if (roadCount == 3) {
                if (i == numPlaces/2) {
                    placeList.push_back(sharedIntersectionPlaces[1]);
                } else if (i == (numPlaces/2) + 1) {
                    placeList.push_back(sharedIntersectionPlaces[3]);
                } else {
                    placeList.push_back(new Place(westI, westJ));
                    westJ--;
                }
                
            }
        }


        
        //now to initialize links
        for (int i = 0; i < numPlaces; i++) {
            if ((i + 1) < numPlaces) {
                getPlaceAt(i)->assignAdjecent(getPlaceAt(i + 1));
            }
            if ((i + 2) < numPlaces) {
                getPlaceAt(i)->assignAdjecent(getPlaceAt(i + 2));
            }
            if ((i + 3) < numPlaces) {
                getPlaceAt(i)->assignAdjecent(getPlaceAt(i + 3));
            }
            if ((i + 4) < numPlaces) {
                getPlaceAt(i)->assignAdjecent(getPlaceAt(i + 4));
            }
        }
        roadCount++;
    }
    
    ~Road() {
        int index = 0;
        for (Place* p : placeList) {
            // Skip shared intersections (25 and 26)
            if (index != numPlaces/2 && index != (numPlaces/2) + 1) {
                delete p;
            }
            index++;
        }
        placeList.clear();
    }
    Direction getDirection() {
        return direction;
    }
    int getNumPlaces() {
        return numPlaces;
    }
    Place* getPlaceAt(int index) {
        if (index >= numPlaces || index < 0) {
            return nullptr;
        }
        return placeList[index];
    }
    
    void populateRoad(char (&board)[20][21]) {
        for (Place* p: placeList) {
            int x = p->getX();
            int y = p->getY();
            board[x][y] = p->getIdentifier();
        }
    }
    
    private:
    //need static variables in order to correctly assign shared place objects between roads
    static inline int roadCount = 0;
    const int numPlaces = 20;
    Direction direction;
    vector<Place*> placeList; //default for now each road will contain 20 place objects
    
   
    
};

#endif /* Road_h */
