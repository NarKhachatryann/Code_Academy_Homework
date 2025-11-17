#include <iostream>
#include "chess.h"

void chessboard::initChessboard() {
    const char* initial[8] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            this->setElement(i, j, initial[i][j]);
        }
    }
}

void chessboard::printChessboard() const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << getPiece(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

char chessboard::getPiece(int row, int col) const {
    return this->getElement(row, col);
}

void chessboard::setPlace(int row, int col, char piece) {
    this->setElement(row, col, piece);
}

bool chessboard::isempty(int row, int col) const {
    return this->getElement(row, col) == '.';
}