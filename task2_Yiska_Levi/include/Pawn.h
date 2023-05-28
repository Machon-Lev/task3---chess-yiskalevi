#pragma once
//#ifndef ROCK_H
//#define ROCK_H

#include "GeneralTool.h"

class Pawn : public GeneralTool {
public:
    Pawn(int x_pos, int y_pos, bool white);
    ~Pawn();
    bool move(int x_pos, int y_pos   , GeneralTool* board[8][8]) override;
};

//#endif // ROCK_H
