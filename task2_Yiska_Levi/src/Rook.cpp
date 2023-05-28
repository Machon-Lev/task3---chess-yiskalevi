#include "Rook.h"

Rook::Rook(int x_pos, int y_pos, bool white) : GeneralTool(x_pos, y_pos, white) {}

Rook::~Rook() {}

bool Rook::move(int x_pos, int y_pos, GeneralTool* board[8][8]) {
    // Make sure the move is legal
    if (x_pos == getX()) {
        // Moving vertically
        int y_step = (y_pos > getY()) ? 1 : -1;
        for (int i = getY() + y_step; i != y_pos; i += y_step) {
            if (board[getX()][i] != nullptr) {
                return false;
            }
        }
        return true;
    }
    else if (y_pos == getY()) {
        // Moving horizontally
        int x_step = (x_pos > getX()) ? 1 : -1;
        for (int i = getX() + x_step; i != x_pos; i += x_step) {
            if (board[i][getY()] != nullptr) {
                return false;
            }
        }
        return true;
    }
    else {
        // Invalid move
        return false;
    }
}



