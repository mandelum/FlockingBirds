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
#include "cinder/app/AppNative.h"
#include <list>

class ThingController {
public:
    ThingController();
    ThingController( int res );
    void update( const ci::Channel32f &channel, const ci::Vec2i &mouseLoc );
    void draw();
    void addThings( int amt );
    void addThings( int xi, int yi);
    void removeThings( int amt );
    void addVelocity();
    void removeVelocity();
    
    std::list<Thing> mThings;
    
    int mXRes, mYRes;
    
};