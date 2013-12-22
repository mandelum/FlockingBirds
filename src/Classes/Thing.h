//
//  Thing.h
//  FlockingBirds
//
//  Created by Robin Brandt on 2013-12-22.
//
//
#pragma once
//#include <iostream>
#include "cinder/Channel.h"
#include "cinder/Vector.h"

#include <vector>

class Thing {
public:
    Thing();
    Thing(ci::Vec2f);
    
    void update();
    void draw();
    
    ci::Vec2f   mLoc;
    ci::Vec2f   mDir;
    float       mVel;
    
    float       mRadius;
    
    int         mOgon;
    
};