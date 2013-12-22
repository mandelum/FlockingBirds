#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "ThingController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class FlockingBirdsApp : public AppNative {
  public:
    void prepareSettings(Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    gl::Texture myImage;
    
    ThingController mThingController;
    
};

void FlockingBirdsApp::prepareSettings(Settings *settings)
{
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
   }

void FlockingBirdsApp::setup()
{
	Url url( "http://libcinder.org/media/tutorial/paris.jpg" );
    myImage = gl::Texture( loadImage( loadUrl( url ) ) );
    
    mThingController.addThings(20);

}

void FlockingBirdsApp::mouseDown( MouseEvent event )
{
    
}

void FlockingBirdsApp::update()
{
    mThingController.update();
}

void FlockingBirdsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ), true );

    if( myImage )
    gl::draw( myImage, getWindowBounds() );
    
    float x = cos( getElapsedSeconds() ) * 100.0f;
    float y = sin( getElapsedSeconds() ) * 100.0f;
    gl::drawSolidCircle( Vec2f( x, y ) + getWindowSize() / 2, abs( y ) , 5);
    
    mThingController.draw();
}

CINDER_APP_NATIVE( FlockingBirdsApp, RendererGl )
