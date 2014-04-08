#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <time.h>
#include <stdio.h>
#include "cinder/Timeline.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class AnalogClockApp : public AppBasic
{
public:
	// setting up and shutting down
	void prepareSettings( Settings *settings );
	void setup();
	
	// game loop
	void update();
	void draw();
	
	// application events
	void keyDown( KeyEvent event );
protected:
//	float getSecondsSinceMidnight();
protected:
	// your class members go here
};

// construction and destruction

void AnalogClockApp::prepareSettings( Settings *settings )
{
	settings->setTitle("Analog Clock");
	settings->setWindowSize(1000, 1000);
}

void AnalogClockApp::setup()
{
	// we don't need to load or setup any stuff in this application
}

// game loop

void AnalogClockApp::update()
{
	// instead of in the update method, we will do all 'animation' in the draw method
}

void AnalogClockApp::draw()
{
	// clear the window with a black background
	gl::clear( Color::white() );
    
	// get the center of the window
	Vec2f center = 0.5f * Vec2f( getWindowSize() );
    
	// set current drawing color to white
	gl::color( Color::black() );
    
    // Create a raw time_t variable and a tm structure
    time_t rawtime;
    struct tm * timeinfo2;
    
    // Get the current time and place it in time_t
    time ( &rawtime );
    
    // Get the locatime from the time_t and put it into our structure timeinfo
    timeinfo2 = localtime ( &rawtime );
    
    // Now we have access to hours, minutes, seconds etc as member variables of all type int
    double hour = timeinfo2->tm_hour;
    double min = timeinfo2->tm_min;
    double sec = timeinfo2->tm_sec;
    double day = timeinfo2->tm_wday;
    
    // Just print out the hours and minutes to show you
    cout << "day " << day << " hour " << hour << " min "<< min << " sec " << sec << endl;
    //cout << sec/60 * Math_PI*2;

    
	// draw the 12 hour digits
	for(int h=0;h<12;++h)
	{
		// store the current transformation,
		// so we can 'undo' the translation and rotation
		// to get ready for the next digit
		gl::pushModelView();
        
		// draw a rectangle, rotated around the clock's center
		gl::translate( center );
		gl::rotate( h * 30.0f ); // 30 degrees per hour
		gl::drawSolidRect( Rectf(-3, -350, 3, -370) );
        
		// restore the transformations
		gl::popModelView();
	}
    
	// get the number of seconds since midnight
    //	float seconds = getSecondsSinceMidnight();
    
    // enable transparency
    gl::enableAlphaBlending();

    // draw the short hand for the day
	gl::pushModelView();
    gl::translate( center );
    gl::rotate( day ); // 30 degrees per 3600 seconds
    //  gl::drawSolidRect( Rectf(-2, -60, 2, 15) );
    glColor4f(.92f, .21f, .49f, .8f); //red
    gl::drawSolidCircle( Vec2f(0,0), 40, 100 );
	gl::popModelView();

    
	// draw the short hand for the hours
	gl::pushModelView();
    gl::translate( center );
    gl::rotate( hour /12*360+min/60/12*360 ); // 30 degrees per 3600 seconds
    //  gl::drawSolidRect( Rectf(-2, -60, 2, 15) );
    glColor4f(.75, .71f, .36f, .8f); //yellow
    gl::drawSolidCircle( Vec2f(0,-250), 40, 200 );
	gl::popModelView();
    
	// draw the long hand for the minutes
	gl::pushModelView();
    gl::translate( center );
    gl::rotate( min /60*360 +sec/60/60*360 ); // 360 degrees per 3600 seconds
    glColor4f(.33f, .32f, .33f, .8f); //grey
   // gl::drawSolidRect( Rectf(-2, -100, 2, 15) );
    gl::drawSolidCircle( Vec2f(0,-265), 40, 0 );
	gl::popModelView();
    
	// set the current drawing color to red
//	gl::color( Color(1, 0, 0) );
    
	// draw the hand for the seconds
	gl::pushModelView();
    gl::translate( center );
    gl::rotate( sec /60*360 ); // 360 degrees per 60 seconds
    //gl::drawSolidRect( Rectf(-1, -100, 1, 15) );
    glColor4f(.35f, .96f, .72f, .8f); //aqua
    gl::drawSolidCircle( Vec2f(0,-280), 40, 50 );
	gl::popModelView();

    // draw the hand for the milliseconds
//	gl::pushModelView();
//    gl::translate( center );
//    gl::rotate( sec * 1000/ 360 ); // 360 degrees per 60 seconds
//    //gl::drawSolidRect( Rectf(-1, -100, 1, 15) );
//    glColor4f(0, 0, 0, .8f); //aqua
//    gl::drawSolidCircle( Vec2f(0,-300), 40, 50 );
//	gl::popModelView();

}



// key events

void AnalogClockApp::keyDown( KeyEvent event )
{
	switch( event.getCode() )
	{
        case KeyEvent::KEY_ESCAPE:
            quit();
            break;
	}
}

CINDER_APP_NATIVE( AnalogClockApp, RendererGl )
