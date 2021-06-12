#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Area.h"
#include "D:\Coding\CPP\Cinder\GameOfLife\vc2015\Engine.hpp"
#include <stdio.h>

#define WIDTH 480
#define HEIGHT 720

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
    Engine engine{ WIDTH,HEIGHT };
    float rate = 10.0f;
    int totalTime = 15;
    int framesRendered = 0;
    //start ffmpeg
    //need to update when I change the resolution
    const char* cmd = "ffmpeg -r 10 -f rawvideo -pix_fmt rgba -s 480x720 -i - "
        "-threads 0 -preset fast -y -pix_fmt yuv420p -crf 21 -vf vflip output.mp4";
    FILE* ffmpeg = _popen(cmd, "wb");
    int* buffer = new int[WIDTH * HEIGHT];
    bool isRecording = false;
};

void GameOfLifeApp::setup()
{
    setFrameRate(rate);
    setWindowSize(WIDTH, HEIGHT);
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
        if (isRecording == true) {
            framesRendered++;
            if (framesRendered > totalTime * 10) {
                _pclose(ffmpeg);
                EXIT_SUCCESS();
            }
            gl::readPixels(0, 0, WIDTH, HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

            fwrite(buffer, sizeof(int) * WIDTH * HEIGHT, 1, ffmpeg);
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
    if (event.getChar() == '1') {
        isRecording = true;
        cout << "Starting Recording..." << endl;
    }
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
