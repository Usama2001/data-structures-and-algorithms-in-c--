#include <iostream>

int main()  {
    const int m = 3;
    const int n = 4;

    int myArray[m][n];
    int* ptr = &myArray[0][0]; //a[0]
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> *(ptr + i * n + j);  //myArray[i][j]
        }
    }
    std::cout << "Initialized 2D array:" << std::endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << *(ptr + i * n + j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
