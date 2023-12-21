#include <iostream>

int main ()
{
    int a[50], size, i;
    int* q= a;
    do 
    {
        std::cout<< "Enter the size off an array: ";
        std::cin >> size;

    } while (size>50);

    for (i=0; i < size; i++ ){
        std::cout << "Element " << i + 1 << ": ";
        std::cin>> a[i]; // std::cin>> *(q+i); // both correct in a case of array 

    }
    std::cout << "Array elements using pointer: ";
    for (int i = 0; i < size; ++i) {
        std::cout << *(q + i) << " ";
    }
    
}

