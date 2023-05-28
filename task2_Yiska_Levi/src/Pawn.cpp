#include "Pawn.h"


Pawn::Pawn(int x_pos, int y_pos, bool white) : GeneralTool(x_pos, y_pos, white) {}

Pawn::~Pawn() {}

bool Pawn::move(int x_pos, int y_pos, GeneralTool* board[8][8]) {

    // Calculate the absolute differences in x and y coordinates
    int dx = abs(x_pos - getX());
    int dy = abs(y_pos - getY());

    // Determine the direction of movement based on the color of the pawn
    int direction = (isWhite()) ? 1 : -1;

    // Check if the move is within the allowed range for the Pawn
    if (dx == 0 && dy == 1 && board[x_pos][y_pos] == nullptr) {
        // Move one step forward (empty square)
        return true;
    }
    else if (dx == 0 && dy == 2 && getY() == 1 && board[getX()][getY() + direction] == nullptr && board[getX()][getY() + 2 * direction] == nullptr) {
        // Move two steps forward (from starting position)
        return true;
    }
    else if (dx == 1 && dy == 1 && board[x_pos][y_pos] != nullptr && board[x_pos][y_pos]->isWhite() != isWhite()) {
        // Capture diagonally (occupied by opponent's tool)
        return true;
    }
    else {
        return false;  // Move is invalid
    }
}


