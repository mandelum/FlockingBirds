//
//  Thing.cpp
//  FlockingBirds
//
//  Created by Robin Brandt on 2013-12-22.
//
//

#include "Thing.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppNative.h"

using namespace ci;
Thing::Thing()
{
}

Thing::Thing( Vec2f loc )
{
    
    mLoc    = loc;
    mDir    = Rand::randVec2f();
    mVel    = Rand::randFloat();
    mRadius = 5.0f;
    
}
void Thing::update()
{
    
    mLoc += mDir * mVel;
    
}

void Thing::draw()
{
    
    gl::drawSolidCircle(mLoc, mRadius);
    
}