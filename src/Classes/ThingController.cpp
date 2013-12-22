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

void update()
{
    for (list<Thing>::iterator p = mThings.begin(); p != mThings.end(); ++p) {
		p->update();
    }
    
}

void draw()
{
    for( list<Thing>::iterator p = mThings.begin(); p != mThings.end(); ++p )
    {
		p->draw();
    }

}

void addThings( int amt )
{
    for( int i=0; i<amt; i++ )
    {
		float x = Rand::randFloat( app::getWindowWidth() );
		float y = Rand::randFloat( app::getWindowHeight() );
		mThings.push_back( Thing( Vec2f( x, y ) ) );
    }
}

void removeThings( int amt )
{
    for( int i=0; i<amt; i++ )
    {
        mThings.pop_back();
    }

}
