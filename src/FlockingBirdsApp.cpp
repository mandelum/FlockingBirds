#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "ThingController.h"

#define TOTAL_PARTICLES 4800
#define RESOLUTION 10

using namespace ci;
using namespace ci::app;
using namespace std;

class FlockingBirdsApp : public AppNative {
  public:
    void prepareSettings(Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );
    void keyDown( KeyEvent event );
	void update();
	void draw();
    Channel32f mChannel;
    gl::Texture	mTexture;
    
    ThingController mThingController;
    
    bool mDrawThings;
    bool mDrawImage;
    
};

void FlockingBirdsApp::prepareSettings(Settings *settings)
{
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
   }

void FlockingBirdsApp::setup()
{
	Url url( "http://libcinder.org/media/tutorial/paris.jpg" );
    
    mChannel = Channel32f( loadImage( loadUrl( url ) ) );
    mTexture = mChannel;
    
    mThingController = ThingController( RESOLUTION );
    //mThingController.addThings( 50 );
    
    mDrawThings = true;
    mDrawImage  = false;

}

void FlockingBirdsApp::mouseDown( MouseEvent event )
{
    
}

void FlockingBirdsApp::update()
{
    if ( ! mChannel ) return;
    
    mThingController.update( mChannel );
}

void FlockingBirdsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ), true );

    if( mDrawImage ){
		mTexture.enableAndBind();
		gl::draw( mTexture, getWindowBounds() );
	}
	
	if( mDrawThings ){
		glDisable( GL_TEXTURE_2D );
        glColor3f( 1, 1, 1 );

		mThingController.draw();
	}
	
 
}

void FlockingBirdsApp::keyDown( KeyEvent event )
{
	if( event.getChar() == '1' ){
		mDrawImage = ! mDrawImage;
	} else if( event.getChar() == '2' ){
		mDrawThings = ! mDrawThings;
	}
}

CINDER_APP_NATIVE( FlockingBirdsApp, RendererGl )
