#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "ThingController.h"
#include "cinder/qtime/MovieWriter.h"
#include "cinder/Utilities.h"

#define TOTAL_PARTICLES 4800
#define RESOLUTION 5

using namespace ci;
using namespace ci::app;
using namespace std;

class FlockingBirdsApp : public AppNative {
  public:
    void prepareSettings(Settings *settings);
	void setup();
    
	void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void mouseMove( MouseEvent event );
    void mouseDrag( MouseEvent event );
    Vec2i mMouseLoc;
    
    void keyDown( KeyEvent event );
    void keyUp( KeyEvent event);
	void update();
	void draw();
    Channel32f mChannel;
    gl::Texture	mTexture;
    
    ThingController mThingController;
    
    bool mDrawThings;
    bool mDrawImage;
    
    qtime::MovieWriter mMovieWriter;
    void initMovieWriter();
    
    
};

void FlockingBirdsApp::prepareSettings(Settings *settings)
{
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 30.0f );
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

void FlockingBirdsApp::update()
{
    if ( ! mChannel ) return;
    
    mThingController.update( mChannel, mMouseLoc );
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
    
    
//    float radius = fabs(sinf(getElapsedSeconds() ) )
//    *
//    200.0f;
//    Vec2f center = getWindowCenter();
//    gl::color( Color(1.0f,1.0f,0.0f));
//    gl::drawSolidCircle( center,  radius);
    
    if( mMovieWriter ){
        mMovieWriter.addFrame( copyWindowSurface());
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

void FlockingBirdsApp::keyUp( KeyEvent event)
{
    if ( event.getChar() == 'm') {
        if (mMovieWriter) {
            mMovieWriter = qtime::MovieWriter();
        }
        else {
            initMovieWriter();
        }
    }
    else
        if( event.getChar() == 'o' )
        {
        try {
            std::string p = getOpenFilePath( "", ImageIo::getLoadExtensions() ).string();
            if( ! p.empty() ) { // an empty string means the user canceled
                
                mChannel = Channel32f( loadImage( p ) );
                mTexture = mChannel;
            }
        }
        catch( ... ) {
            console() << "Unable to load the image." << std::endl;
        }
        }
}

void FlockingBirdsApp::mouseDown( MouseEvent event ) {
    
    mThingController.addVelocity();
    
}
void FlockingBirdsApp::mouseUp( MouseEvent event ) {
    
    mThingController.removeVelocity();
    
}

void FlockingBirdsApp::mouseMove( MouseEvent event ) {
    
    mMouseLoc = event.getPos();
    
}

void FlockingBirdsApp::mouseDrag( MouseEvent event ) {
    
    mouseMove( event );
    
}

void FlockingBirdsApp::initMovieWriter()
{
    fs::path path = getSaveFilePath();

    if( path.empty() == false)
      {
        //console() << path;
        qtime::MovieWriter::Format format;
        format.setCodec( qtime::MovieWriter::CODEC_H264);
      //format.setQuality(0.5f);
      format.setDefaultDuration( 1.0f / 30.0f);
        
        mMovieWriter = qtime::MovieWriter( path, getWindowWidth(),getWindowHeight(), format );


        }
}

CINDER_APP_NATIVE( FlockingBirdsApp, RendererGl )
