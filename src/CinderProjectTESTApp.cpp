#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <Math.h>
//#define M_PI           3.14159265358979323846
#include "boost/date_time/posix_time/posix_time.hpp"


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
    gl::clear( Color( 1, 1, 1), true);
    // turn on blending
    gl::enableAlphaBlending();
    
    // Get current time from the clock, using microseconds resolution
    boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
    
    // Get the time offset in current day
    boost::posix_time::time_duration td = now.time_of_day();
    
    // break apart for millisecond conversion
    long day = td.days();
    long hours = td.hours();
    long minutes = td.minutes();
    double seconds = td.seconds();
    double milliseconds = td.total_milliseconds() - ((hours * 3600 + minutes * 60 + seconds) * 1000);
    
    cout << " day " << day << " hour " << hours << " min "<< minutes << " sec " << seconds << endl;
    // do some math to get correct radians
    double secs_millisecs = seconds + (milliseconds/1000); //add seconds and milliseonds for smoother drawing
    double percent = secs_millisecs / 60; // return 0-1 as double (eg: 0.25)
    double degrees = (percent * 360) - 90; //return degrees for radian math and subtract 90 as -90 is 0 on a clocks face
    double radians = cinder::toRadians(degrees); //converts degrees to radians
    
    double mins_secs = minutes + (seconds/60);
    double mpercent = mins_secs/ 60;
    double mdegrees = (mpercent * 360) - 90;
    double mradians = cinder::toRadians(mdegrees);
    
    double hour_mins = hours + (minutes/60);
    double hpercent = hour_mins/ 60;
    double hdegrees = (hpercent * 360) -90;
    double hradians = cinder::toRadians(hdegrees);
    
    // draw the hand for the seconds
    float secX = cos( radians ) * 400.0f;
    float secY = sin( radians ) * 400.0f;
    glColor4f(.35f, .96f, .72f, .8f); //aqua
    gl::drawSolidCircle( Vec2f( secX, secY ) + getWindowSize() /2, abs(seconds+(milliseconds/1000)));
    
    // draw the hand for the minutes
    float minX = cos( mradians ) * 300.0f;
    float minY = sin( mradians ) * 300.0f;
    glColor4f(.33f, .32f, .33f, .8f); //grey
    gl::drawSolidCircle( Vec2f( minX, minY ) + getWindowSize() /2, 40.0f);
    
    // draw the hand for the hours
    float hrX = cos( hradians ) * 200.0f;
    float hrY = sin( hradians ) * 200.0f;
    glColor4f(.75, .71f, .36f, .8f); //yellow
    gl::drawSolidCircle( Vec2f( hrX, hrY ) + getWindowSize() /2, 40.0f);
    
    // draw the hand for the days
    float dayX = cos( getElapsedSeconds()/86400 ) * 100.0f;
    float dayY = sin( getElapsedSeconds() )/86400 * 100.0f;
    glColor4f(.92f, .21f, .49f, .8f); //red
    gl::drawSolidCircle( Vec2f( dayX, dayY ) + getWindowSize() /2, 40.0f);
    
    
    
}

CINDER_APP_NATIVE( CinderProjectTESTApp, RendererGl )
