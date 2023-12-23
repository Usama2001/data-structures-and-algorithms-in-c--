#include <iostream>
#include <string>

int main()
{
    int a[50], size, i, num, pos;
    std::string Questionstring;
    do
    {
        std::cout << "Enter the size of an array :";
        std::cin >> size;
    } while ((size > 50));

    std::cout << "Enter the elemet of an array :";
    for (i = 0; i < size; i++)
    {
        std::cin >> a[i];
        if (i < size - 1)
        {
            std::cout << "Enter the other Element :";
        }
    }

    std::cout << "Enter the number you want to insert :";
    std::cin >> num;

    do
    {
        std::cout << "Enter the postion :";
        std::cin >> pos;
    } while (pos > size);

    std::cout << "your list is sorted or not (yes/no)";
    std::cin >> Questionstring;

    if (Questionstring == "yes")
    {
        if (pos == size)
        {
            std::cout << "Array before added the element: ";
            for (i = 0; i < size; i++)
            {
                std::cout << a[i] << " ";
            }

            std::cout << "size=position";
            a[size] = num;
            size++;

            std::cout << "\n Array before added the element: ";
            for (i = 0; i < size; i++)
            {
                std::cout << a[i] << " ";
            }
        }

        else
        {
            std::cout << "else";
            std::cout << "Array before added the element: ";
            for (i = 0; i < size; i++)
            {
                std::cout << a[i] << " ";
            }

            for (i = size - 1; i >= pos - 1; i--)
            {
                a[i + 1] = a[i];
            }
            a[pos - 1] = num;
            size++;

            std::cout << "\n Array before added the element: ";
            for (i = 0; i < size; i++)
            {
                std::cout << a[i] << " ";
            }
        }
    }
    else{
        a[size]=a[pos-1];
        a[pos-1]=num;
        size++;

        std::cout << "\n Array before added the element: ";
            for (i = 0; i < size; i++)
            {
                std::cout << a[i] << " ";
            }
        
    }
}
