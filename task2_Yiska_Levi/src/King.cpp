#include "King.h"


King::King(int x_pos, int y_pos, bool white) : GeneralTool(x_pos, y_pos, white) {}

King::~King() {}

bool King::move(int  x_pos, int y_pos, GeneralTool* board[8][8]) {

    // Calculate the absolute differences in x and y coordinates
    int dx = abs(x_pos - getX());
    int dy = abs(y_pos - getY());

    // Check if the move is within the allowed range for the King
    if ((dx == 1 && dy == 0) || (dx == 0 && dy == 1) || (dx == 1 && dy == 1)) {
        return true;  // Move is valid
    }

    return false;  // Move is invalid
}


