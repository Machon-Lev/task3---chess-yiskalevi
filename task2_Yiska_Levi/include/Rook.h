#pragma once


#include "GeneralTool.h"

class Rook : public GeneralTool {
public:
    Rook(int x_pos, int y_pos, bool white);
    ~Rook();
    bool move(int x_pos, int y_pos, GeneralTool* board[8][8]) override;
};

