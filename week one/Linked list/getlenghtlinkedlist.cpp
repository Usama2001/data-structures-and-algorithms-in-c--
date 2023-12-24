#include <iostream>

using namespace std;
std::string Questionstring;
int count;

// Node structure for a singly linked list
struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    struct node *head, *tail;

public:
    linked_list() // Constructor to initialize an empty linked list
    {
        head = NULL;
        tail = NULL;
    }

    void add_node() // Function to add a new node to the end of the list
    {
        do
        { // Create a new node
            node *newnode = new node;
            std::cout << "Enter the element: ";
            std::cin >> newnode->data;
            newnode->next = NULL;
            // If the list is empty, set both head and tail to the new node
            if (head == NULL)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                // Otherwise, add the new node to the end and update the tail
                tail->next = newnode;
                tail = tail->next;
            }
            std::cout << "do you wan to add more element? (yes/no): ";
            std::cin >> Questionstring;
        } while (Questionstring == "yes");
        std::cout << "Linked List: ";
        display_and_getLenght();
    }

    void display_and_getLenght()
    {
        tail = head;
        count = 0;
        while (tail != NULL)
        {
            count++;
            std::cout << tail->data << " (" << tail->next << ") ";
            tail = tail->next;
        }
        std::cout << std::endl;
        std::cout << "There are " << count << " nodes/elemet in linked list" << "\n";
    }
};

int main()
{
    linked_list a;
    a.add_node();
    return 0;
}

