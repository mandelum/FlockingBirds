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
#include "cinder/Color.h"

#include <vector>

class Thing {
public:
    Thing();
    Thing(ci::Vec2f);
    
    void update( const ci::Channel32f &channel, const ci::Vec2i &mouseLoc );
    void draw();
    
    void addVelocity();
    void removeVelocity();
    
    ci::Vec2f   mLoc;
    ci::Vec2f   mDir;
    float       mVel;
    
    ci::Vec2f   mDirToCursor;
    
    float       mRadius;
    float       mScale;
    
    int         mOgon;
    ci::Color   mColor;
    
};