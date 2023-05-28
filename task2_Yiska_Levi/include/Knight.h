#pragma once
//#ifndef ROCK_H
//#define ROCK_H

#include "GeneralTool.h"

class Knight : public GeneralTool {
public:
    Knight(int x_pos, int y_pos, bool white);
    ~Knight();
    bool move(int x_pos, int y_pos   , GeneralTool* board[8][8]) override;
};

//#endif // ROCK_H
