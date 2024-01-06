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

    for (i = 0; i < size; i++)
    {
        std::cout << "Enter " << i+1 << " Element :";
        std::cin >> a[i];
    }

    do
    {
        std::cout << "Enter the postion of element that you want to delete :";
        std::cin >> pos;
    } while (pos > size);

    std::cout << "your list is sorted or not (yes/no)";
    std::cin >> Questionstring;

    if (Questionstring == "yes")
    {
        if (pos == size)
        {
            std::cout << "Array before deleted the element: ";
            for (i = 0; i < size; i++)
            {
                std::cout << a[i] << " ";
            }

            std::cout << "size=position";
            // a[size] = num;
            size--;

            std::cout << "\n Array after deleted the element: ";
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

            for (i = pos - 1; i < size - 1; i++)
            {
                a[i] = a[i+1];
            }
            size--;

            std::cout << "\n Array After deleted the element: ";
            for (i = 0; i < size; i++)
            {
                std::cout << a[i] << " ";
            }
        }
    }
    else{
        a[pos-1]=a[size-1];
        size--;

        std::cout << "\n Array after deleted the element (else else): ";
            for (i = 0; i < size; i++)
            {
                std::cout << a[i] << " ";
            }
        
    }
}
