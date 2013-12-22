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
    mRadius = Rand::randInt( 3, 20 );
    
    mOgon   = Rand::randInt( 10 );
    
}
void Thing::update()
{
    
    mLoc += mDir * mVel;
    //mLoc.x += cos( app::getElapsedSeconds() ) * 2.0f;
    //mRadius = abs( mLoc.y ) / ( abs( mLoc.x ) + 1 );
    
}

void Thing::draw()
{
    gl::drawSolidCircle( mLoc , mRadius, mOgon);
    //gl::drawSolidCircle(mLoc, mRadius);
    
}