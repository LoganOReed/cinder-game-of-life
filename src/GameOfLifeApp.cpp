#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Area.h"
#include "D:\Coding\CPP\Cinder\GameOfLife\vc2015\Engine.hpp"
#include <stdio.h>

using namespace ci;
using namespace ci::app;
using namespace std;

class GameOfLifeApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void keyDown(KeyEvent event) override;
	void update() override;
	void draw() override;
private:
    Engine engine{ 1000,1000 };
    float rate = 10.0f;
    int totalTime = 5;
    int framesRendered = 0;
    //start ffmpeg
    const char* cmd = "ffmpeg -r 10 -f rawvideo -pix_fmt rgba -s 1000x1000 -i - "
        "-threads 0 -preset fast -y -pix_fmt yuv420p -crf 21 -vf vflip output.mp4";
    FILE* ffmpeg = _popen(cmd, "wb");
    int* buffer = new int[1000 * 1000];
};

void GameOfLifeApp::setup()
{
    setFrameRate(rate);
    setWindowSize(1000, 1000);
    engine.InitializeBoard();
}

void GameOfLifeApp::mouseDown( MouseEvent event )
{
}

void GameOfLifeApp::update()
{
    engine.Update();
}

void GameOfLifeApp::draw()
{
        gl::clear(Color(0, 0, 0));
        engine.Draw();
        engine.BoardReset();

        //render
        gl::readPixels(0, 0, 1000, 1000, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

        fwrite(buffer, sizeof(int) * 1000 * 1000, 1, ffmpeg);

        framesRendered++;
        if (framesRendered > totalTime * 5) {
            _pclose(ffmpeg);
            EXIT_SUCCESS();
        }
}

void GameOfLifeApp::keyDown( KeyEvent event )
{
    if (event.getChar() == 'q') {
        rate++;
        setFrameRate(rate);
    }
    if (event.getChar() == 'a') {
        rate--;
        setFrameRate(rate);
    }
    if (event.getChar() == 'r') {
        engine.InitializeBoard();
    }
    //if (event.getChar() == '1') {
        //engine.BoardReset();
       // engine.MakeOscillators();
    //}
    if (event.getChar() == '2') {
        engine.BoardReset();
        engine.MakeStillLife();
    }
    if (event.getChar() == '3') {
        engine.BoardReset();
        engine.MakeSpaceShips();
    }
    if (event.getChar() == '9') {
        engine.BoardReset();
        engine.MakeOscillators();
        engine.MakeSpaceShips();
    }
    if (event.getChar() == 'g') {
        engine.BoardReset();
        engine.MakeGalaxy();
    }
    if (event.getChar() == 'b') {
        engine.BoardReset();
        engine.MakeAcorn();
    }
}

CINDER_APP( GameOfLifeApp, RendererGl )
