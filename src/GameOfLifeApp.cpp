#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Area.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class GameOfLifeApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void GameOfLifeApp::setup()
{
}

void GameOfLifeApp::mouseDown( MouseEvent event )
{
}

void GameOfLifeApp::update()
{
}

void GameOfLifeApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
	ci::RectT<float>* rect = new ci::RectT<float>(0,-0,100,100);
	gl::drawSolidRect(*rect,vec2(0,0),vec2(100,-100));
}

CINDER_APP( GameOfLifeApp, RendererGl )
