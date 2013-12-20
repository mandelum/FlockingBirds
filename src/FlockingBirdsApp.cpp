#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class FlockingBirdsApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void FlockingBirdsApp::setup()
{
}

void FlockingBirdsApp::mouseDown( MouseEvent event )
{
}

void FlockingBirdsApp::update()
{
}

void FlockingBirdsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( FlockingBirdsApp, RendererGl )
