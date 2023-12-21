#include <iostream>
#include <vector>

int main() {
    int m, n;

    std::cout << "Enter the number of rows: ";
    std::cin >> m;
    std::cout << "Enter the number of columns: ";
    std::cin >> n;
    
    int myArray[m][n];
        
    std::cout << "Enter the elements of the 2D array:" << std::endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> myArray[i][j];
        }
    }

    std::cout << "The 2D array:" << std::endl;
    for (int i = 0; i < m; i++) {
        std::cout<< "[";
        for (int j = 0; j < n; j++) {
            std::cout << myArray[i][j] ;
            if (j<n-1){
                std::cout<< ",";
            }
        }
        std::cout<< "]";
        std::cout << std::endl;
    }
}
