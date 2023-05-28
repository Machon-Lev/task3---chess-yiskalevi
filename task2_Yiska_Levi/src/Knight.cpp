#include "Knight.h"


Knight::Knight(int x_pos, int y_pos, bool white) : GeneralTool(x_pos, y_pos, white) {}

Knight::~Knight() {}

bool Knight::move(int x_pos, int y_pos, GeneralTool* board[8][8]) {

    // Calculate the absolute differences in x and y coordinates
    int dx = abs(x_pos - getX());
    int dy = abs(y_pos - getY());

    // Check if the move follows the valid pattern for a Knight
    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
        // Check if the destination position is empty or occupied by an opponent's tool
        if (board[x_pos][y_pos] == nullptr || board[x_pos][y_pos]->isWhite() != isWhite()) {
            return true;  // Move is valid
        }
    }

    return false;  // Move is invalid
}


