#pragma once
//#ifndef ROCK_H
//#define ROCK_H

#include "GeneralTool.h"

class Bishop : public GeneralTool {
public:
    Bishop(int x_pos, int y_pos, bool white);
    ~Bishop();
    bool move(int column, int y_pos   , GeneralTool* board[8][8]) override;
};

//#endif // ROCK_H
