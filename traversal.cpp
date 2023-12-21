#include <iostream>

int main()
{
    int a[50];
    int size, i;
    
    std::cout << "Enter the size of an array: ";
    std::cin >> size;

    std::cout << "Enter elements of an array: ";
    for (i = 0; i < size; i++)
    {
        std::cin >> a[i];
        if (i<size-1){
            std::cout << "Enter the other elements of an array: ";
        }
    }

    std::cout << "Elements are: ";
    for (i = 0; i < size; i++)
    {
        std::cout << a[i] << " ";
    }

    return 0;
}