//
//  ThingController.cpp
//  FlockingBirds
//
//  Created by Robin Brandt on 2013-12-22.
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"
#include "ThingController.h"

using namespace ci;
using std::list;

ThingController::ThingController()
{
    
}

ThingController::ThingController( int res )
{
    mXRes = app::getWindowWidth()/res;
	mYRes = app::getWindowHeight()/res;
    
    for( int y=0; y<mYRes; y++ ) {
        for ( int x=0; x<mXRes; x++ ) {
            addThings( ( x + 0.5f ) * 10.0f, ( y + 0.5f ) * 10.0f );
        }
    }
}

void ThingController::update()
{
    
    for (list<Thing>::iterator p = mThings.begin(); p != mThings.end(); ++p) {
		p->update();
    }
    
}

void ThingController::draw()
{
    for( list<Thing>::iterator p = mThings.begin(); p != mThings.end(); ++p )
    {
		p->draw();
    }

}

void ThingController::addThings( int amt )
{
    for( int i=0; i<amt; i++ )
    {
		float x = Rand::randFloat( app::getWindowWidth() );
		float y = Rand::randFloat( app::getWindowHeight() );
		mThings.push_back( Thing( Vec2f( x, y ) ) );

    }
}

void ThingController::addThings( int xi, int yi)
{
    //float x = ( xi + 0.5f ) * 10.0f; //move this to funtion call to make more general
    //float y = ( yi + 0.5f ) * 10.0f;
    mThings.push_back( Thing( Vec2f( xi, yi ) ) );

}

void ThingController::removeThings( int amt )
{
    for( int i=0; i<amt; i++ )
    {
        mThings.pop_back();
    }

}
