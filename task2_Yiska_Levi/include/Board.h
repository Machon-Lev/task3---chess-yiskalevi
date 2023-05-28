#pragma once
//#ifndef BOARD_H
//#define BOARD_H
#include <vector>

class GeneralTool; // Forward declaration

class Board {
private:
    GeneralTool* _board[8][8]; // 2D array representing the game board
    bool _white_turn = true;
    
    std::pair<int, int>findKing(bool isWhite); // Function to check if the king is found and return its coordinates
    bool isCheck(bool isWhiteKing); // Function to check if the king is being threatened
    bool isCheckmate(bool isWhiteKing); // Function to check if the king is threatened and has no legal moves to escape
    void print(); // Print the current state of the board
    void initialize(); // Initialize the board with starting positions of the tools
    bool isKing(GeneralTool* a);

public:
    Board();
    Board(const Board& other);
    ~Board();
    int move(int x_pos, int fromY, char toX, int toY); // Move a tool on the board

};

//#endif // BOARD_H
