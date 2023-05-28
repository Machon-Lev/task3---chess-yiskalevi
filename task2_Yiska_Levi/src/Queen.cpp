#include "Queen.h"


Queen::Queen(int x_pos, int y_pos, bool white) : GeneralTool(x_pos, y_pos, white) {}

Queen::~Queen() {}

bool Queen::move(int x_pos, int y_pos, GeneralTool* board[8][8]) {

    // Calculate the absolute differences in x and y coordinates
    int dx = abs(x_pos - getX());
    int dy = abs(y_pos - getY());

    // Check if the move follows the valid pattern for a Queen
    if (getX() == x_pos || getY() == y_pos || dx == dy) {
        // Determine the direction of movement
        int x_step = (x_pos > getX()) ? 1 : ((x_pos < getX()) ? -1 : 0);
        int y_step = (y_pos > getY()) ? 1 : ((y_pos < getY()) ? -1 : 0);

        // Check if the path is clear for the Queen to move
        int current_x = getX() + x_step;
        int current_y = getY() + y_step;
        while (current_x != x_pos || current_y != y_pos) {
            if (board[current_x][current_y] != nullptr) {
                return false;  // Path is obstructed, move is invalid
            }
            current_x += x_step;
            current_y += y_step;
        }

        // Check if the destination position is empty or occupied by an opponent's tool
        if (board[x_pos][y_pos] == nullptr || board[x_pos][y_pos]->isWhite() != isWhite()) {
            return true;  // Move is valid
        }
    }

    return false;  // Move is invalid
}


