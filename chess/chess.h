#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "matrix.h"

class chessboard : public Matrix {
public:
    chessboard(int size = 8) : Matrix(size) {}

    void initChessboard();
    void printChessboard() const;
    void setPlace(int row, int col, char piece);
    char getPiece(int row, int col) const;
    bool isempty(int row, int col) const;
};

#endif