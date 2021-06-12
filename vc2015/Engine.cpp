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

void Engine::MakeAmongUs() {
    board[14][47] = 1;
    board[14][48] = 1;
    board[14][49] = 1;
    board[14][50] = 1;
    board[14][51] = 1;
    board[14][52] = 1;
    board[14][53] = 1;
    board[14][54] = 1;
    board[14][55] = 1;
    board[15][45] = 1;
    board[15][46] = 1;
    board[15][47] = 1;
    board[15][55] = 1;
    board[15][56] = 1;
    board[15][57] = 1;
    board[16][45] = 1;
    board[16][58] = 1;
    board[16][59] = 1;
    board[17][44] = 1;
    board[17][59] = 1;
    board[17][60] = 1;
    board[18][43] = 1;
    board[18][60] = 1;
    board[18][61] = 1;
    board[19][42] = 1;
    board[19][43] = 1;
    board[19][61] = 1;
    board[20][42] = 1;
    board[20][61] = 1;
    board[20][62] = 1;
    board[20][63] = 1;
    board[20][64] = 1;
    board[20][65] = 1;
    board[20][66] = 1;
    board[20][67] = 1;
    board[20][68] = 1;
    board[20][69] = 1;
    board[20][70] = 1;
    board[20][71] = 1;
    board[20][72] = 1;
    board[20][73] = 1;
    board[20][74] = 1;
    board[20][75] = 1;
    board[20][76] = 1;
    board[20][77] = 1;
    board[20][78] = 1;
    board[20][79] = 1;
    board[20][80] = 1;
    board[20][81] = 1;
    board[20][82] = 1;
    board[20][83] = 1;
    board[20][84] = 1;
    board[20][85] = 1;
    board[20][86] = 1;
    board[20][87] = 1;
    board[20][88] = 1;
    board[20][92] = 1;
    board[20][93] = 1;
    board[20][94] = 1;
    board[20][95] = 1;
    board[20][96] = 1;
    board[20][97] = 1;
    board[20][98] = 1;
    board[20][99] = 1;
    board[20][100] = 1;
    board[20][101] = 1;
    board[20][102] = 1;
    board[20][103] = 1;
    board[20][104] = 1;
    board[20][105] = 1;
    board[20][106] = 1;
    board[20][107] = 1;
    board[20][108] = 1;
    board[20][109] = 1;
    board[20][110] = 1;
    board[20][111] = 1;
    board[20][112] = 1;
    board[20][113] = 1;
    board[20][114] = 1;
    board[20][115] = 1;
    board[21][33] = 1;
    board[21][34] = 1;
    board[21][35] = 1;
    board[21][36] = 1;
    board[21][37] = 1;
    board[21][38] = 1;
    board[21][39] = 1;
    board[21][40] = 1;
    board[21][41] = 1;
    board[21][42] = 1;
    board[21][62] = 1;
    board[21][63] = 1;
    board[21][64] = 1;
    board[21][88] = 1;
    board[21][89] = 1;
    board[21][90] = 1;
    board[21][91] = 1;
    board[21][92] = 1;
    board[21][115] = 1;
    board[22][31] = 1;
    board[22][32] = 1;
    board[22][33] = 1;
    board[22][41] = 1;
    board[22][42] = 1;
    board[22][63] = 1;
    board[22][116] = 1;
    board[23][29] = 1;
    board[23][30] = 1;
    board[23][31] = 1;
    board[23][41] = 1;
    board[23][42] = 1;
    board[23][63] = 1;
    board[23][116] = 1;
    board[24][28] = 1;
    board[24][29] = 1;
    board[24][41] = 1;
    board[24][42] = 1;
    board[24][63] = 1;
    board[24][116] = 1;
    board[25][26] = 1;
    board[25][27] = 1;
    board[25][41] = 1;
    board[25][42] = 1;
    board[25][63] = 1;
    board[25][116] = 1;
    board[26][25] = 1;
    board[26][26] = 1;
    board[26][41] = 1;
    board[26][42] = 1;
    board[26][43] = 1;
    board[26][63] = 1;
    board[26][116] = 1;
    board[26][117] = 1;
    board[27][24] = 1;
    board[27][42] = 1;
    board[27][43] = 1;
    board[27][63] = 1;
    board[27][117] = 1;
    board[28][23] = 1;
    board[28][42] = 1;
    board[28][43] = 1;
    board[28][63] = 1;
    board[28][117] = 1;
    board[29][22] = 1;
    board[29][23] = 1;
    board[29][42] = 1;
    board[29][43] = 1;
    board[29][63] = 1;
    board[29][117] = 1;
    board[30][22] = 1;
    board[30][42] = 1;
    board[30][43] = 1;
    board[30][63] = 1;
    board[30][117] = 1;
    board[31][21] = 1;
    board[31][22] = 1;
    board[31][42] = 1;
    board[31][63] = 1;
    board[31][117] = 1;
    board[32][21] = 1;
    board[32][42] = 1;
    board[32][63] = 1;
    board[32][117] = 1;
    board[33][20] = 1;
    board[33][42] = 1;
    board[33][63] = 1;
    board[33][117] = 1;
    board[34][20] = 1;
    board[34][42] = 1;
    board[34][64] = 1;
    board[34][117] = 1;
    board[35][19] = 1;
    board[35][20] = 1;
    board[35][42] = 1;
    board[35][64] = 1;
    board[35][97] = 1;
    board[35][98] = 1;
    board[35][117] = 1;
    board[36][19] = 1;
    board[36][42] = 1;
    board[36][64] = 1;
    board[36][98] = 1;
    board[36][116] = 1;
    board[36][117] = 1;
    board[37][19] = 1;
    board[37][42] = 1;
    board[37][64] = 1;
    board[37][98] = 1;
    board[37][115] = 1;
    board[37][116] = 1;
    board[37][117] = 1;
    board[38][18] = 1;
    board[38][19] = 1;
    board[38][42] = 1;
    board[38][64] = 1;
    board[38][99] = 1;
    board[38][114] = 1;
    board[38][115] = 1;
    board[38][116] = 1;
    board[39][18] = 1;
    board[39][42] = 1;
    board[39][64] = 1;
    board[39][99] = 1;
    board[39][104] = 1;
    board[39][105] = 1;
    board[39][106] = 1;
    board[39][108] = 1;
    board[39][109] = 1;
    board[39][110] = 1;
    board[39][111] = 1;
    board[39][112] = 1;
    board[39][113] = 1;
    board[39][114] = 1;
    board[39][115] = 1;
    board[39][116] = 1;
    board[40][18] = 1;
    board[40][42] = 1;
    board[40][64] = 1;
    board[40][99] = 1;
    board[40][101] = 1;
    board[40][102] = 1;
    board[40][103] = 1;
    board[40][104] = 1;
    board[40][105] = 1;
    board[40][106] = 1;
    board[40][107] = 1;
    board[40][108] = 1;
    board[41][18] = 1;
    board[41][42] = 1;
    board[41][64] = 1;
    board[41][99] = 1;
    board[41][100] = 1;
    board[41][101] = 1;
    board[41][102] = 1;
    board[42][18] = 1;
    board[42][42] = 1;
    board[42][43] = 1;
    board[42][64] = 1;
    board[42][99] = 1;
    board[43][18] = 1;
    board[43][43] = 1;
    board[43][64] = 1;
    board[43][99] = 1;
    board[44][18] = 1;
    board[44][43] = 1;
    board[44][64] = 1;
    board[44][99] = 1;
    board[45][18] = 1;
    board[45][43] = 1;
    board[45][64] = 1;
    board[45][99] = 1;
    board[45][100] = 1;
    board[46][18] = 1;
    board[46][44] = 1;
    board[46][64] = 1;
    board[46][100] = 1;
    board[47][18] = 1;
    board[47][44] = 1;
    board[47][64] = 1;
    board[47][100] = 1;
    board[48][18] = 1;
    board[48][44] = 1;
    board[48][45] = 1;
    board[48][64] = 1;
    board[48][100] = 1;
    board[49][18] = 1;
    board[49][45] = 1;
    board[49][64] = 1;
    board[49][100] = 1;
    board[50][18] = 1;
    board[50][45] = 1;
    board[50][63] = 1;
    board[50][64] = 1;
    board[50][100] = 1;
    board[51][18] = 1;
    board[51][46] = 1;
    board[51][63] = 1;
    board[51][100] = 1;
    board[52][18] = 1;
    board[52][46] = 1;
    board[52][63] = 1;
    board[52][100] = 1;
    board[52][101] = 1;
    board[52][102] = 1;
    board[52][103] = 1;
    board[52][104] = 1;
    board[52][105] = 1;
    board[52][106] = 1;
    board[52][107] = 1;
    board[52][108] = 1;
    board[52][109] = 1;
    board[52][110] = 1;
    board[52][111] = 1;
    board[52][112] = 1;
    board[52][113] = 1;
    board[52][114] = 1;
    board[52][115] = 1;
    board[53][18] = 1;
    board[53][46] = 1;
    board[53][47] = 1;
    board[53][63] = 1;
    board[53][116] = 1;
    board[53][117] = 1;
    board[53][118] = 1;
    board[54][18] = 1;
    board[54][47] = 1;
    board[54][63] = 1;
    board[54][119] = 1;
    board[55][19] = 1;
    board[55][47] = 1;
    board[55][48] = 1;
    board[55][63] = 1;
    board[55][119] = 1;
    board[55][120] = 1;
    board[56][19] = 1;
    board[56][48] = 1;
    board[56][63] = 1;
    board[56][120] = 1;
    board[57][19] = 1;
    board[57][49] = 1;
    board[57][63] = 1;
    board[57][120] = 1;
    board[58][19] = 1;
    board[58][49] = 1;
    board[58][50] = 1;
    board[58][62] = 1;
    board[58][63] = 1;
    board[58][120] = 1;
    board[59][20] = 1;
    board[59][50] = 1;
    board[59][51] = 1;
    board[59][62] = 1;
    board[59][120] = 1;
    board[60][20] = 1;
    board[60][51] = 1;
    board[60][52] = 1;
    board[60][60] = 1;
    board[60][61] = 1;
    board[60][120] = 1;
    board[61][20] = 1;
    board[61][52] = 1;
    board[61][53] = 1;
    board[61][58] = 1;
    board[61][59] = 1;
    board[61][60] = 1;
    board[61][120] = 1;
    board[62][21] = 1;
    board[62][53] = 1;
    board[62][54] = 1;
    board[62][55] = 1;
    board[62][56] = 1;
    board[62][57] = 1;
    board[62][58] = 1;
    board[62][120] = 1;
    board[63][21] = 1;
    board[63][120] = 1;
    board[64][21] = 1;
    board[64][22] = 1;
    board[64][120] = 1;
    board[65][22] = 1;
    board[65][23] = 1;
    board[65][120] = 1;
    board[66][23] = 1;
    board[66][120] = 1;
    board[67][24] = 1;
    board[67][120] = 1;
    board[68][25] = 1;
    board[68][120] = 1;
    board[69][25] = 1;
    board[69][26] = 1;
    board[69][120] = 1;
    board[70][26] = 1;
    board[70][27] = 1;
    board[70][28] = 1;
    board[70][120] = 1;
    board[71][29] = 1;
    board[71][119] = 1;
    board[72][30] = 1;
    board[72][31] = 1;
    board[72][32] = 1;
    board[72][118] = 1;
    board[72][119] = 1;
    board[73][32] = 1;
    board[73][33] = 1;
    board[73][34] = 1;
    board[73][97] = 1;
    board[73][98] = 1;
    board[73][99] = 1;
    board[73][100] = 1;
    board[73][101] = 1;
    board[73][102] = 1;
    board[73][103] = 1;
    board[73][104] = 1;
    board[73][105] = 1;
    board[73][106] = 1;
    board[73][107] = 1;
    board[73][108] = 1;
    board[73][109] = 1;
    board[73][110] = 1;
    board[73][111] = 1;
    board[73][112] = 1;
    board[73][113] = 1;
    board[73][114] = 1;
    board[73][115] = 1;
    board[73][116] = 1;
    board[73][117] = 1;
    board[73][118] = 1;
    board[74][34] = 1;
    board[74][35] = 1;
    board[74][36] = 1;
    board[74][62] = 1;
    board[74][63] = 1;
    board[74][64] = 1;
    board[74][65] = 1;
    board[74][66] = 1;
    board[74][67] = 1;
    board[74][68] = 1;
    board[74][69] = 1;
    board[74][70] = 1;
    board[74][71] = 1;
    board[74][72] = 1;
    board[74][73] = 1;
    board[74][74] = 1;
    board[74][75] = 1;
    board[74][76] = 1;
    board[74][77] = 1;
    board[74][78] = 1;
    board[74][79] = 1;
    board[74][80] = 1;
    board[74][81] = 1;
    board[74][82] = 1;
    board[74][83] = 1;
    board[74][84] = 1;
    board[74][85] = 1;
    board[74][86] = 1;
    board[74][87] = 1;
    board[74][88] = 1;
    board[74][89] = 1;
    board[74][90] = 1;
    board[74][91] = 1;
    board[74][92] = 1;
    board[74][93] = 1;
    board[74][94] = 1;
    board[74][95] = 1;
    board[74][96] = 1;
    board[74][98] = 1;
    board[75][37] = 1;
    board[75][38] = 1;
    board[75][39] = 1;
    board[75][40] = 1;
    board[75][41] = 1;
    board[75][42] = 1;
    board[75][43] = 1;
    board[75][44] = 1;
    board[75][45] = 1;
    board[75][46] = 1;
    board[75][47] = 1;
    board[75][55] = 1;
    board[75][56] = 1;
    board[75][57] = 1;
    board[75][58] = 1;
    board[75][59] = 1;
    board[75][60] = 1;
    board[75][61] = 1;
    board[75][98] = 1;
    board[76][48] = 1;
    board[76][49] = 1;
    board[76][50] = 1;
    board[76][51] = 1;
    board[76][52] = 1;
    board[76][53] = 1;
    board[76][54] = 1;
    board[76][57] = 1;
    board[76][98] = 1;
    board[77][57] = 1;
    board[77][98] = 1;
    board[78][57] = 1;
    board[78][98] = 1;
    board[79][57] = 1;
    board[79][98] = 1;
    board[80][57] = 1;
    board[80][97] = 1;
    board[81][57] = 1;
    board[81][97] = 1;
    board[82][57] = 1;
    board[82][97] = 1;
    board[83][57] = 1;
    board[83][96] = 1;
    board[84][58] = 1;
    board[84][95] = 1;
    board[84][96] = 1;
    board[85][58] = 1;
    board[85][80] = 1;
    board[85][94] = 1;
    board[85][95] = 1;
    board[86][58] = 1;
    board[86][59] = 1;
    board[86][79] = 1;
    board[86][80] = 1;
    board[86][81] = 1;
    board[86][82] = 1;
    board[86][83] = 1;
    board[86][84] = 1;
    board[86][89] = 1;
    board[86][90] = 1;
    board[86][91] = 1;
    board[86][92] = 1;
    board[86][93] = 1;
    board[87][60] = 1;
    board[87][61] = 1;
    board[87][62] = 1;
    board[87][63] = 1;
    board[87][72] = 1;
    board[87][73] = 1;
    board[87][74] = 1;
    board[87][75] = 1;
    board[87][76] = 1;
    board[87][77] = 1;
    board[87][78] = 1;
    board[87][85] = 1;
    board[87][86] = 1;
    board[87][87] = 1;
    board[87][88] = 1;
    board[87][89] = 1;
    board[88][63] = 1;
    board[88][64] = 1;
    board[88][65] = 1;
    board[88][66] = 1;
    board[88][67] = 1;
    board[88][68] = 1;
    board[88][69] = 1;
    board[88][70] = 1;
    board[88][71] = 1;

}