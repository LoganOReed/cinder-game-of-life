#include "cinder/Cinder.h"

#include "cinder/app/App.h"

#include "cinder/gl/gl.h"

#include "cinder/CinderMath.h"
#include "cinder/Matrix.h"
#include "cinder/Vector.h"
#include "cinder/Quaternion.h"
#include "Engine.hpp"

using namespace cinder;

Engine::Engine(int w, int h) {
    width = w;
    height = h;
}

void Engine::InitializeBoard() {
    SetBoardToAllDead();
    MakeRandomBoard();
}

void Engine::Update() {
    for (size_t r = 0; r < NUM_ROWS; r++) {
        for (size_t c = 0; c < NUM_COLS; c++) {
            if (board[r][c] == 0 && GetAliveNumNearby(r, c) == 3) {
                new_board[r][c] = 1;
            }
            else if (board[r][c] == 1 && (GetAliveNumNearby(r, c) == 3 || GetAliveNumNearby(r, c) == 4)) {
                new_board[r][c] = 1;
            }
            else if (board[r][c] == 1 && (GetAliveNumNearby(r, c) <= 2 || GetAliveNumNearby(r, c) >= 5)) {
                new_board[r][c] = 0;
            }
        }
    }
}

void Engine::Draw() {
    cinder::gl::color(Color(1, 1, 1));
    for (size_t r = 0; r < NUM_ROWS; r++) {
        for (size_t c = 0; c < NUM_COLS; c++) {
            if (new_board[r][c] == 1) {
                gl::drawSolidRect(Rectf(r * length, c * length, r * length + length, c * length + length));
            }
        }
    }
}

int Engine::GetAliveNumNearby(int x, int y) {
    int live_count = 0;
    for (int r = x - 1; r <= x + 1; r++) {
        for (int c = y - 1; c <= y + 1; c++) {
            if (board[r][c] == 1) {
                live_count++;
            }
        }
    }
    return live_count;
}

void Engine::BoardReset() {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            board[r][c] = new_board[r][c];
            new_board[r][c] = 0;
        }
    }
}

void Engine::SetBoardToAllDead() {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            board[r][c] = 0;
        }
    }
}

void Engine::MakeRandomBoard() {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            bool half_prob = (rand() % 100) < 60; // 50% probability
            if (half_prob) {
                board[r][c] = 1;
            }
        }
    }
}

void Engine::MakeFrog() {
    board[15][15] = 1;
    board[15][16] = 1;
    board[15][17] = 1;
    board[16][16] = 1;
    board[16][17] = 1;
    board[16][18] = 1;
}

void Engine::MakeBlinker() {
    board[10][20] = 1;
    board[10][21] = 1;
    board[10][22] = 1;
}

void Engine::MakeGlider() {
    board[10][10] = 1;
    board[11][10] = 1;
    board[12][10] = 1;
    board[10][11] = 1;
    board[11][12] = 1;
}

void Engine::MakeBlock() {
    board[20][20] = 1;
    board[20][21] = 1;
    board[21][20] = 1;
    board[21][21] = 1;
}

void Engine::MakeStillLife() {
    MakeBlock();
}

void Engine::MakeOscillators() {
    MakeFrog();
    MakeBlinker();
}

void Engine::MakeSpaceShips() {
    MakeGlider();
}

void Engine::MakeGalaxy() {
    for (int i = 0; i < 6; i++) {
        board[30][30 + i] = 1;
        board[38][32 + i] = 1;
        board[30 + i][30] = 1;
        board[32 + i][38] = 1;
    }
}

void Engine::MakeAcorn() {
    board[30][30] = 1;
    board[30][31] = 1;
    board[28][31] = 1;
    board[29][33] = 1;
    board[30][34] = 1;
    board[30][35] = 1;
    board[30][36] = 1;
}