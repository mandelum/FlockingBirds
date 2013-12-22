//
//  ThingController.h
//  FlockingBirds
//
//  Created by Robin Brandt on 2013-12-22.
//
//
#pragma once
//#include <iostream>
#include "Thing.h"
#include <list>

class ThingController {
public:
    ThingController();
    void update();
    void draw();
    void addThings( int amt );
    void removeThings( int amt );
    
    std::list<Thing> mThings;
};