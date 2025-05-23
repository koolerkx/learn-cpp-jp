#include <iostream>
#include <iomanip>

const int SIZE = 3;
const int START_ROW = 0;
const int START_COL = SIZE/2;

void display_matrix(int mahhoujin[SIZE][SIZE])
{
    std::cout << "„¡„Ÿ„Ÿ";
    for (int x = 1; x < SIZE; x++) {
        std::cout << "„¦„Ÿ„Ÿ";
    }                  
    std::cout << "„¢" << std::endl;

    for (int y = 0; y < SIZE; y++) {
        std::cout << "„ ";
        for (int x = 0; x < SIZE; x++) {
            std::cout << std::setw(2);
            if (mahhoujin[y][x]) {
                std::cout << mahhoujin[y][x];
            }
            else {
                std::cout << " ";
            }
            std::cout << "„ ";
        }
        std::cout << "\n";

        if (y == SIZE - 1) break;

        std::cout << "„¥„Ÿ„Ÿ";
        for (int x = 1; x < SIZE; x++) {
            std::cout << "„©„Ÿ„Ÿ";
        }
        std::cout << "„§\n";
    }

    std::cout << "„¤„Ÿ„Ÿ";
    for (int x = 1; x < SIZE; x++) {
        std::cout << "„¨„Ÿ„Ÿ";
    }
    std::cout << "„£" << std::endl;
}

bool is_empty(int i, int j, int (&matrix)[SIZE][SIZE])
{
    return matrix[i][j] == 0;
}

int abs_size(int num)
{
    return (num + SIZE) % SIZE;
}

int main(int argc, char* argv[])
{
    int matrix[SIZE][SIZE] {};
    
    display_matrix(matrix);

    int row = START_ROW;
    int col = START_COL;
    
    for (int i=1; i <= SIZE*SIZE; i++)
    {
        matrix[row][col] = i;

        if (is_empty(abs_size(row-1), abs_size(col+1), matrix))
        {
            row = abs_size(row-1);
            col = abs_size(col+1);
        } else if (is_empty(abs_size(row+1), col, matrix))
        {
            row = abs_size(row+1);
        }

        std::cin.get();
        display_matrix(matrix);
    }

    std::cin.get();
    
    return 0;
}
