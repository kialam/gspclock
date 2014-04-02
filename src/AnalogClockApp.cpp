#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class AnalogClockApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void AnalogClockApp::setup()
{
}

void AnalogClockApp::mouseDown( MouseEvent event )
{
}

void AnalogClockApp::update()
{
}

void AnalogClockApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( AnalogClockApp, RendererGl )
