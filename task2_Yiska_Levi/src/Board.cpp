#include "Board.h"
#include "GeneralTool.h" // Include the header file for GeneralTool
#include "Rook.h" // Include the header file for GeneralTool
#include "King.h" // Include the header file for GeneralTool
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include <iostream>

Board::Board() {
    // Initialize the board with nullptrs
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            _board[i][j] = nullptr;
        }
    }
    initialize();
}

Board::Board(const Board& other) {
    // Copy the state of the other board
    _white_turn = other._white_turn;

    // Copy the tools on the board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            GeneralTool* tool = other._board[i][j];
            if (tool != nullptr) {
                _board[i][j] = tool; // Assuming GeneralTool has a virtual clone() function
            }
            else {
                _board[i][j] = nullptr;
            }
        }
    }
}

Board::~Board() {
    // Clean up the board by deleting the tools
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(_board[i][j] != nullptr)
                delete _board[i][j];
        }
    }
}

void Board::initialize() {
    // Create and place the tools in their starting positions

// Place the pawns
    for (int i = 0; i < 8; ++i) {
        _board[1][i] = new Pawn(i, 1, true);   // White pawns in the second row
        _board[6][i] = new Pawn(i, 6, false);  // Black pawns in the seventh row
     }

    // Place the rooks
    _board[0][0] = new Rook(0, 0, true);   // White rook on a1
    _board[0][7] = new Rook(7, 0, true);   // White rook on h1
    _board[7][0] = new Rook(0, 7, false);  // Black rook on a8
    _board[7][7] = new Rook(7, 7, false);  // Black rook on h8

    // Place the knights
    _board[0][1] = new Knight(1, 0, true);   // White knight on b1
    _board[0][6] = new Knight(6, 0, true);   // White knight on g1
    _board[7][1] = new Knight(1, 7, false);  // Black knight on b8
    _board[7][6] = new Knight(6, 7, false);  // Black knight on g8

    // Place the bishops
    _board[0][2] = new Bishop(2, 0, true);   // White bishop on c1
    _board[0][5] = new Bishop(5, 0, true);   // White bishop on f1
    _board[7][2] = new Bishop(2, 7, false);  // Black bishop on c8
    _board[7][5] = new Bishop(5, 7, false);  // Black bishop on f8

    // Place the queens
    _board[0][3] = new Queen(3, 0, true);   // White queen on d1
    _board[7][3] = new Queen(3, 7, false);  // Black queen on d8

    // Place the kings
    _board[0][4] = new King(4, 0, true);   // White king on e1
    _board[7][4] = new King(4, 7, false);  // Black king on e8
  
}

void Board::print() {
    // Print the current state of the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (_board[i][j] == NULL) {
                std::cout << "-";
            }
            else {
                if (typeid(*_board[i][j]) == typeid(Rook)) {
                    std::cout << "r";
                }
                
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

int Board::move(int fromX, int fromY, char toX, int toY) {
    
    // Check if the destination position is within the board bounds
    if (toX < 0 || toX >= 8 || toY < 0 || toY >= 8) {
        std::cout << "Invalid destination position." << std::endl;
        return false;
    }

    // Check if the source position has a tool
    GeneralTool* tool = _board[fromX][fromY];
    if (tool == nullptr) {
        return 11;
    }
    // Check if the tool in the source square is an opponent's tool
    if (tool->isWhite()!= _white_turn) {
        return 12;
    }
    //**
    // Check if the tool can make the specified move
    if (!tool->move(toX, toY, _board)) {
        std::cout << "Invalid move for the selected tool." << std::endl;
        return 21;
    }

    // Check if the destination position has a tool of the same color
    if (_board[toX][toY] != nullptr && _board[toX][toY]->isWhite() == tool->isWhite()) {
        return 13;
    }

    // Move the tool to the destination position
    Board t(*this); // Create a copy of the current board
    if (t._board[toX][toY] != NULL)
        delete t._board[toX][toY];
    t._board[toX][toY] = tool;
    t._board[fromX][fromY] = nullptr;
    //We will check that the action does not cause chess
    if (isCheckmate(_white_turn)) {
        return 31;
    }

    if (_board[toX][toY]!=NULL)
        delete _board[toX][toY];
    _board[toX][toY] = tool;
    _board[fromX][fromY] = nullptr;
    tool->setPosition(toX, toY);

    //turn change 
    if (_white_turn) {
        _white_turn = false;
    }
    else {
        _white_turn = true;
    }
    //Checking if the move caused a check on the opponent
    if (isCheck(_white_turn))
        return 41;
    return 42;
}

bool Board::isKing(GeneralTool* a) {
    return typeid(*a) == typeid(King);
}

std::pair<int, int> Board::findKing(bool isWhite) {
    // Iterate over the board to find the king
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            GeneralTool* piece = _board[i][j];
            if (piece != nullptr && isKing(piece) && piece->isWhite() == isWhite) {
                // Found the king with the matching color
                return std::make_pair(i, j);
            }
        }
    }

    // King not found, return invalid coordinates
    return std::make_pair(-1, -1);

}

bool Board::isCheck(bool isWhiteKing)
{
    // Find the position of the king
    std::pair<int, int> kingPosition = findKing(isWhiteKing);
    int kingX = kingPosition.first;
    int kingY = kingPosition.second;

    // Check if the king position is valid
    if (kingX == -1 || kingY == -1) {
        // King not found, return false
        return false;
    }

    // Iterate over opponent's pieces to check if they can attack the king
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            GeneralTool* tool = _board[x][y];
            if (tool != nullptr && tool->isWhite() != isWhiteKing) {
                std::vector<std::pair<int, int>> moves = tool->getPossibleMoves(_board);
                for (const auto& move : moves) {
                    if (move.first == kingX && move.second == kingY) {
                        // The king is threatened
                        return true;
                    }
                }
            }
        }
    }

    // The king is not threatened
    return false;
}


bool Board::isCheckmate(bool isWhiteKing) {
    // Find the position of the king
    std::pair<int, int> kingPosition = findKing(isWhiteKing);
    int kingX = kingPosition.first;
    int kingY = kingPosition.second;

    // Check if the king position is valid
    if (kingX == -1 || kingY == -1) {
        // King not found, return false
        return false;
    }

    // Check if the king is threatened
    if (isCheck(isWhiteKing)) {
        // Iterate over the king's possible moves
        GeneralTool* king = _board[kingX][kingY];
        std::vector<std::pair<int, int>> kingMoves = king->getPossibleMoves(_board);
        for (const auto& move : kingMoves) {
            int newX = move.first;
            int newY = move.second;

            // Simulate the king's move and check if it's still threatened
            GeneralTool* previousPiece = _board[newX][newY];
            _board[newX][newY] = king;
            _board[kingX][kingY] = nullptr;
            bool isStillThreatened = isCheck(isWhiteKing);

            // Restore the board state
            _board[kingX][kingY] = king;
            _board[newX][newY] = previousPiece;

            // If the king can make a move that eliminates the threat, it's not checkmate
            if (!isStillThreatened) {
                return false;
            }
        }

        // Iterate over the opponent's pieces and check if any of them can capture the threatening piece or block the threat
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                GeneralTool* piece = _board[i][j];
                if (piece != nullptr && piece->isWhite() != isWhiteKing) {
                    std::vector<std::pair<int, int>> pieceMoves = piece->getPossibleMoves(_board);
                    for (const auto& move : pieceMoves) {
                        int destX = move.first;
                        int destY = move.second;

                        // Simulate the piece's move and check if it eliminates the threat
                        GeneralTool* capturedPiece = _board[destX][destY];
                        _board[destX][destY] = piece;
                        _board[i][j] = nullptr;
                        bool isStillThreatened = isCheck(isWhiteKing);

                        // Restore the board state
                        _board[i][j] = piece;
                        _board[destX][destY] = capturedPiece;

                        // If the piece can capture the threatening piece or block the threat, it's not checkmate
                        if (!isStillThreatened) {
                            return false;
                        }
                    }
                }
            }
        }

        // If the king has no legal moves and no other piece can eliminate the threat, it's checkmate
        return true;
    }

    // The king is not threatened, return false
    return false;
}


