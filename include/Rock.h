#ifndef ROCK_H
#define ROCK_H

#include "GeneralTool.h"

class Rock : public GeneralTool {
public:
    Rock(int x_pos, int y_pos, bool white);
    ~Rock();
    bool move(int x_pos, int y_pos, GeneralTool* board[8][8]) override;
    std::vector<std::pair<int, int>> getPossibleMoves(GeneralTool* board[8][8]) override;
};

#endif // ROCK_H
