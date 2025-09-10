#include <iostream>

bool matrixchecker(char** matrix, int size) {
    int count = 0;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(matrix[i][j] != ' ') {
                count++;
            }
        }
    }
    if(size * size == count) return false;

    return true;
}

void board(char** matrix, int size) {
    std::cout << "\n" << "|---+---+---|" << std::endl;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout<< "| " << matrix[i][j] << " ";
        }
        std::cout << "|" << "\n" << "|---+---+---|" << std::endl;
    }
    std::cout << std::endl;

} 

bool check(char** matrix, int size, int row, int col) {
    if((row > 0 || row < 4) || (col > 0 || col < 4) ) {
        return false;
    }
    else if(matrix[row][col] != ' ') {
        return false;
    }
    return true;
}

void game(char** matrix, int size) {
    char playero = 'o';
    char playerx = 'x';
    char player = playerx;
    int row = 0, col = 0;

    board(matrix,size);

    while (true)
    {
        bool checker = false;
        do {
                std::cout << "Enter the row for player " << player << ": ";
                std::cin >> row;
                std::cout << "Enter the column for player " << player << ": ";
                std::cin >> col;
                if(!check(matrix, size, row, col)) {
                    std::cout << "Wrong Row or Column!!" << std::endl << "Try again!" << std::endl;
                } else {
                    checker = true;
                }
            } while(checker == true);

        matrix[row - 1][col - 1] = player;

        board(matrix,size);

        if(player == playerx) {
            player = playero;
        } else {
            player = playerx;
        }

        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
            
        }
    }
    }
}

int main() {
    int size = 3;

    char** matrix = new char*[size];
    for(int  i = 0; i < size; ++i) {
        matrix[i] = new char[size];
    }
    
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            matrix[i][j] = ' ';
        }
    }

    game(matrix,size);

    for(int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}