#include "Rock.h"

Rock::Rock(int x_pos, int y_pos, bool white) : GeneralTool(x_pos, y_pos, white) {}

Rock::~Rock() {}

bool Rock::move(int x_pos, int y_pos, GeneralTool* board[8][8]) {
    // Make sure the move is legal
    if (x_pos == getX()) {
        // Moving vertically
        int y_step = (y_pos > getY()) ? 1 : -1;
        for (int i = getY() + y_step; i != y_pos; i += y_step) {
            if (board[getX()][i] != nullptr) {
                return false;
            }
        }
        // Check if there is a tool to capture
        if (board[getX()][y_pos] != nullptr) {
            if (board[getX()][y_pos]->isWhite() != isWhite()) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else if (y_pos == getY()) {
        // Moving horizontally
        int x_step = (x_pos > getX()) ? 1 : -1;
        for (int i = getX() + x_step; i != x_pos; i += x_step) {
            if (board[i][getY()] != nullptr) {
                return false;
            }
        }
        // Check if there is a tool to capture
        if (board[x_pos][getY()] != nullptr) {
            if (board[x_pos][getY()]->isWhite() != isWhite()) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        // Invalid move
        return false;
    }
}

std::vector<std::pair<int, int>> Rock::getPossibleMoves(GeneralTool* board[8][8]) {
    std::vector<std::pair<int, int>> moves;
    // Check all positions horizontally and vertically
    for (int i = 0; i < 8; i++) {
        if (i != getY() && (board[getX()][i] == nullptr || board[getX()][i]->isWhite() != isWhite())) {
            moves.push_back(std::make_pair(getX(), i));
        }
        if (i != getX() && (board[i][getY()] == nullptr || board[i][getY()]->isWhite() != isWhite())) {
            moves.push_back(std::make_pair(i, getY()));
        }
    }
    return moves;
}
