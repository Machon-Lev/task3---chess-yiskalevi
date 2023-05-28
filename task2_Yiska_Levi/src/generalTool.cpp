#include "GeneralTool.h" 
#include <iostream>

GeneralTool::GeneralTool(int x_pos, int y_pos, bool white) : _x(x_pos), _y(y_pos), _isWhite(white) {}

GeneralTool::~GeneralTool() {}

std::vector<std::pair<int, int>> GeneralTool::getPossibleMoves(GeneralTool* board[8][8])
{
    std::vector<std::pair<int, int>> moves;
    // Check all positions horizontally and vertically
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (this->move(i, j, board)) {
                moves.push_back(std::make_pair(i, j));
            }
        }
    }
    return moves;
}

int GeneralTool::getX() { return _x; }

int GeneralTool::getY() { return _y; }

bool GeneralTool::isWhite() { return _isWhite; }

void GeneralTool::setPosition(int x_pos, int y_pos) { _x = x_pos; _y = y_pos; }