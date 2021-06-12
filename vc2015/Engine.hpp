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

#define NUM_COLS 144
#define NUM_ROWS 96

using namespace ci;
using namespace ci::app;

class Engine {
public:
    Engine(int w, int h);
    void InitializeBoard();
    void Update();
    void Draw();
    void SetBoardToAllDead();
    void MakeAmongUs();
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
    int length = 5;
    int board[NUM_ROWS][NUM_COLS];
    int new_board[NUM_ROWS][NUM_COLS];
    int colorBoard[NUM_ROWS][NUM_COLS];
    int x = 0;
    int y = 0;
    const cinder::vec2 center = getWindowCenter();
    Color ages[4];
};

#endif
