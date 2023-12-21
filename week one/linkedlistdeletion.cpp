#include <iostream>

using namespace std;
std::string Questionstring;
std::string Questionstringfor123;
int count, pos, i = 1;

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
        display();
    }

    void delete_node()
    {
        add_node();

        std::cout << "do you want to delete node at Beginning >> Press 1"
                  << "\n"
                  << "do you want to delete node at End >> Press 2"
                  << "\n"
                  << "do you want to delete node at specific position >> Press 3"
                  << "\n"
                  << "do you want to stop the code >> Press 4"
                  << "\n";
        std::cin >> Questionstringfor123;

        if (Questionstringfor123 == "1")
        {
            delete_node_beginning();
        }
        else if (Questionstringfor123 == "2")
        {
            delete_node_end();
        }
        else if (Questionstringfor123 == "3")
        {
        }
        else
        {
            std::cout << "Linked List: ";
            display();
        }
    }

    void delete_node_beginning()
    {
        tail = head;
        head = head->next;
        free(tail);
        display();
    }

    void delete_node_end()
    {
        struct node *previous;
        tail = head;
        while (tail->next != 0);
        {
            previous = tail;
            tail = tail->next;
        }
        if (tail == head)
        {
            head = 0;
        }
        else
        {
            previous->next =0; 
        }
        free(tail);
        display();
    }

    void insert_node_specific()
    {
    }

    void display()
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
        std::cout << "there are " << count;
        std::cout << std::endl;
    }
};

int main()
{
    // Create a linked list object
    linked_list a;

    a.delete_node();

    return 0;
}

/* We have made two nodes – head and tail. We will store the first node in ‘head’ and
the last node in ‘tail’. The constructor of the linked list is making both ‘head ’ and ‘ tail’ NULL
because we have not yet added any element to our linked list and thus both are NULL. */