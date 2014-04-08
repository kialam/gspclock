#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <CinderMath.h>
#define M_PI           3.14159265358979323846


using namespace ci;
using namespace ci::app;
using namespace std;

class CinderProjectTESTApp : public AppNative {
  public:
    void prepareSettings( Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void CinderProjectTESTApp::prepareSettings( Settings *settings ){
    settings->setWindowSize( 800, 800);
    settings->setFrameRate(60.0f);
}

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
	// clear out the window with white
//	gl::clear( Color( .35, .96, .72 ), true );
    gl::clear( Color( 1, 1, 1), true);
//    float gray = sin( getElapsedSeconds() ) * 0.5f + 0.5f;
//    gl::clear( Color( .35, gray, .72 ), true );
//    gl::drawSolidCircle( Vec2f( 50.0f, 50.0f ), 50.0f );
//    gl::drawSolidCircle( Vec2f( 770.0f, 30.0f ), 30.0f );
//    gl::drawSolidCircle( Vec2f( 90.0f, 510.0f ), 90.0f );
//    gl::drawSolidCircle( Vec2f( 760.0f, 560.0f ), 40.0f );
    
    gl::enableAlphaBlending();
    
    float secX = cos( getElapsedSeconds()/60.0f *6.6 ) * 400.0f;
    float secY = sin( getElapsedSeconds()/60.0f *6.6) * 400.0f;
    glColor4f(.35f, .96f, .72f, .8f);
    gl::drawSolidCircle( Vec2f( secX, secY ) + getWindowSize() /2, 30.0f);
    
    float minX = cos( getElapsedSeconds()/3600 * 2.4 ) * 300.0f;
    float minY = sin( getElapsedSeconds()/3600 * 2.4 ) * 300.0f;
    glColor4f(.33f, .32f, .33f, .8f);
    gl::drawSolidCircle( Vec2f( minX, minY ) + getWindowSize() /2, 40.0f);
    
    float hrX = cos( getElapsedSeconds()/43200 ) * 200.0f;
    float hrY = sin( getElapsedSeconds()/43200 ) * 200.0f;
    glColor4f(.75, .71f, .36f, .8f);
    gl::drawSolidCircle( Vec2f( hrX, hrY ) + getWindowSize() /2, 60.0f);
    
    float dayX = cos( getElapsedSeconds()/86400 ) * 100.0f;
    float dayY = sin( getElapsedSeconds() )/86400 * 100.0f;
    glColor4f(.92f, .21f, .49f, .8f);
    gl::drawSolidCircle( Vec2f( dayX, dayY ) + getWindowSize() /2, 50.0f);
    
    
    
}

CINDER_APP_NATIVE( CinderProjectTESTApp, RendererGl )
