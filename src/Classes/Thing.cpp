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
    //mDir.x = 1;
    //mDir.y = 0;
    mVel    = Rand::randFloat();
    mVel    = 1.0f;
    mVel    = 0.0f;
    //mRadius = Rand::randInt( 3, 20 );
    mRadius = 4.0f;
    //mRadius = Rand::randFloat( 1.0f, 5.0f );
    //mRadius = cos( mLoc.y * 0.1f ) + sin( mLoc.x * 0.1f ) + 2.0f;
    //mRadius = ( sin( mLoc.y * mLoc.x * 1000 ) + 1.0f ) * 2.0f;
    //mRadius = sin( mLoc.x );
    //float xyOffset = sin( cos( sin( mLoc.y * 0.3183f ) + cos( mLoc.x * 0.3183f ) ) ) + 1.0f;
    //mRadius = xyOffset * xyOffset * 1.8f;

    
    //mOgon   = Rand::randInt( 10 );
    mOgon   = 0;
    mColor  = Color(Rand::randFloat(1),
                    Rand::randFloat(1)
                    ,Rand::randFloat(1));
    //app::console() << "mColor ="<< mColor <<std::endl;
    
}
void Thing::update( const Channel32f &channel )
{
    //float time = app::getElapsedSeconds();
    //float gray = channel.getValue( mLoc );
    //mColor = Color( gray, gray, gray );
    mRadius = channel.getValue( mLoc ) * 7.0f;
    
    //mLoc += mDir * mVel;
    
    mLoc = mLoc + (mDir * mVel);
    //mLoc.x += cos( app::getElapsedSeconds() ) * 2.0f;
    //mRadius = abs( mLoc.y ) / ( abs( mLoc.x ) + 1 );
    
}

void Thing::draw()
{

    gl::color( mColor );
    gl::drawSolidCircle( mLoc , mRadius, mOgon);

    //gl::drawSolidCircle(mLoc, mRadius);
    
}