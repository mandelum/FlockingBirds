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
    //mDir    = Rand::randVec2f();
    //mVel    = Rand::randFloat();
    //mRadius = Rand::randInt( 3, 20 );
    mRadius = 4;
    //mRadius = Rand::randFloat( 1.0f, 5.0f );
    //mRadius = cos( mLoc.y * 0.1f ) + sin( mLoc.x * 0.1f ) + 2.0f;
    //mRadius = ( sin( mLoc.y * mLoc.x * 1000 ) + 1.0f ) * 2.0f;
    //mRadius = sin( mLoc.x );

    
    //mOgon   = Rand::randInt( 10 );
    mOgon   = 10;
    
}
void Thing::update()
{
    
    //mLoc += mDir * mVel;
    //mLoc.x += cos( app::getElapsedSeconds() ) * 2.0f;
    //mRadius = abs( mLoc.y ) / ( abs( mLoc.x ) + 1 );
    
}

void Thing::draw()
{
    gl::drawSolidCircle( mLoc , mRadius, mOgon);

    //gl::drawSolidCircle(mLoc, mRadius);
    
}