#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <stdio.h>
#include "cinder/Cinder.h"

#include "cinder/app/App.h"

#include "cinder/gl/gl.h"

#include "cinder/CinderMath.h"
#include "cinder/Matrix.h"
#include "cinder/Vector.h"
#include "cinder/Quaternion.h"

#define NUM_ROWS 100
#define NUM_COLS 100

using namespace cinder::app;

class Engine {
public:
    Engine(int w, int h);
    void InitializeBoard();
    void Update();
    void Draw();
    void SetBoardToAllDead();
    void MakeGlider();
    void MakeBlinker();
    void MakeFrog();
    void MakeRandomBoard();
    void MakeStillLife();
    void MakeOscillators();
    void MakeSpaceShips();
    void MakeBlock();
    void MakeGalaxy();
    void MakeAcorn();
    int GetAliveNumNearby(int x, int y);
    void BoardReset();
private:
    int width;
    int height;
    int board[192][108];
    int new_board[192][108];
    int x = 0;
    int y = 0;
    const cinder::vec2 center = getWindowCenter();
};

#endif
