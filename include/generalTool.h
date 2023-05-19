#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using std::cout;
using std::cin; 
using std::endl;
using std::string; 



class generalTool {
protected:
    int _x; // x position on the board
    int _y; // y position on the board
    bool _isWhite; // true if the tool is white, false if it is black
public:
    generalTool(int x_pos, int y_pos, bool white) : x(x_pos), y(y_pos), isWhite(white) {}
    virtual ~generalTool();
    virtual bool move(int x_pos, int y_pos, generalTool* board[8][8]) = 0;
    virtual std::vector<std::pair<int, int>> getPossibleMoves(generalTool* board[8][8]) = 0;
    int getX();
    int getY();
    bool isWhite();
    void setPosition(int x_pos, int y_pos);
};
