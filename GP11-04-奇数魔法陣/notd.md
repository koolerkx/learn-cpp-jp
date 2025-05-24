# Square matrix

```c++
void display_matrix(int (&matrix)[SIZE][SIZE])
{
    for (int i = 0; i < SIZE*SIZE; i++)
    {
        if (i != 0 && i%SIZE == 0)
        {
            std::cout << "\n";
        }
        std::cout << matrix[i/SIZE][i%SIZE] << " ";
    }
    std::cout << "\n" << "-----" << "\n";
}
```