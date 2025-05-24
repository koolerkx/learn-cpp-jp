#include <iostream>
#include <iomanip>

constexpr int SIZE = 5; // SIZE‚Ì’l‚ÍŠï”‚Ì‚İ
constexpr int START_ROW = 0;
constexpr int START_COL = SIZE/2;

void display_matrix(const int (&matrix)[SIZE][SIZE])
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
            if (matrix[y][x]) {
                std::cout << matrix[y][x];
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

bool is_empty(int i, int j, const int (&matrix)[SIZE][SIZE])
{
    return matrix[i][j] == 0;
}

int wrap_index(int num)
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

        int row_upper = wrap_index(row-1);
        int col_right = wrap_index(col+1);
        
        if (is_empty(row_upper, col_right, matrix))
        {
            row = row_upper;
            col = col_right;
        } else
        {
            row = wrap_index(row+1);
        }

        std::cin.get();
        display_matrix(matrix);
    }

    std::cin.get();
    
    return 0;
}
