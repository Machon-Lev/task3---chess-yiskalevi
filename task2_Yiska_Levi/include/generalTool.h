#pragma once
//#ifndef BOARD_H
//#define BOARD_H
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using std::cout;
using std::cin; 
using std::endl;
using std::string; 



class GeneralTool {
protected:
    int _x; // x position on the board
    int _y; // y position on the board
    bool _isWhite; // true if the tool is white, false if it is black
public:
    GeneralTool(int x_pos, int y_pos, bool white);
    virtual ~GeneralTool();
    virtual bool move(int x_pos, int y_pos, GeneralTool* board[8][8]) = 0;
    virtual std::vector<std::pair<int, int>> getPossibleMoves(GeneralTool* board[8][8]);
    int getX();
    int getY();
    bool isWhite();
    void setPosition(int x_pos, int y_pos);
};
//#endif // BOARD_H
