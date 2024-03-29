#include <iostream>

using namespace std;
std::string Questionstring;

// Node structure for a singly linked list
struct node
{
    int data;
    node *next;
};

// Linked list class
class linked_list
{
private:
    struct node *head, *tail;

public:
    // Constructor to initialize an empty linked list
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    // Function to add a new node to the end of the list
    void add_node()
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
        display();

    }

    void display()
    {
        tail = head;
        while (tail != NULL)
        {
            std::cout << tail->data << " (" << tail->next << ") ";
            tail = tail->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    // Create a linked list object
    linked_list a;

    // Add nodes to the end of the list
    a.add_node();
    return 0;
}

/* We have made two nodes – head and tail. We will store the first node in ‘head’ and
the last node in ‘tail’. The constructor of the linked list is making both ‘head ’ and ‘ tail’ NULL
because we have not yet added any element to our linked list and thus both are NULL. */