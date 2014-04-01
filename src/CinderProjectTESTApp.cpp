#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderProjectTESTApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void CinderProjectTESTApp::setup()
{
}

void CinderProjectTESTApp::mouseDown( MouseEvent event )
{
}

void CinderProjectTESTApp::update()
{
}

void CinderProjectTESTApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( CinderProjectTESTApp, RendererGl )
