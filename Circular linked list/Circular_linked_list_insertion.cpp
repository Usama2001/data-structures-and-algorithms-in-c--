#include <iostream>

using namespace std;
std::string Questionstring,Questionstringfor123;
int count, pos, i=1;

// Node structure for a circular linked list
struct node
{
    int data;
    node *next;
};

// Circular linked list class
class CircularLinkedList
{
private:
    struct node *head, *tail;

public:
    // Constructor to initialize an empty circular linked list
    CircularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // Function to add a new node to the end of the circular linked list
    void add_node()
    {
        do
        {
            // Create a new node
            node *newnode = new node;
            cout << "Enter the element: ";
            cin >> newnode->data;

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
                tail = newnode;
            }
            newnode->next = head; // Make it point to itself to form a circle //Make it point back to the head to form a circle

            cout << "Do you want to add more elements? (yes/no): ";
            cin >> Questionstring;
        } while (Questionstring == "yes");

        // Display the circular linked list
        cout << "Circular Linked List: ";
        display();
    }

    // Function to display the elements of the circular linked list
    void display()
    {
        // Reset tail to head for traversal
        node *current = head;
        do
        {
            cout << current->data << " (" << current->next << ") ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    void insert_node()
    {
        add_node();

        std::cout << "do you want to add node at Beginning >> Press 1"
                  << "\n"
                  << "do you want to add node at End >> Press 2"
                  << "\n"
                  << "do you want to add node at specific position >> Press 3"
                  << "\n"
                  << "do you want to stop the code >> Press 4"
                  << "\n";
        std::cin >> Questionstringfor123;

        if (Questionstringfor123 == "1")
        {
            insert_node_beginning();
        }
        else if (Questionstringfor123 == "2")
        {
            insert_node_end();
        }
        else if (Questionstringfor123 == "3")
        {
            insert_node_specific();
        }
        else
        {
            std::cout << "No changes ";
        }
        std::cout << "Updated Linked List: ";
        display();
    }

    void insert_node_beginning()
    {
        node *newnode = new node;
        std::cout << "Enter the element: ";
        std::cin >> newnode->data;
        newnode->next = head;
        head = newnode;
    }

    void insert_node_end()
    {
        node *newnode = new node;
        std::cout << "Enter the element: ";
        std::cin >> newnode->data;
        newnode->next = 0;
        tail = head;
        while (tail->next != 0)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }

    void insert_node_specific()
    {
        node *newnode = new node;
        do
        {
            std::cout << "Enter the Postion: ";
            std::cin >> pos;
        } while (pos > count);

        std::cout << "Enter the element: ";
        std::cin >> newnode->data;

        tail = head;
        while (i < pos)
        {
            tail = tail->next;
            i++;
        }
        newnode->next = tail->next;
        tail->next = newnode;
    }





};

int main()
{
    // Create a circular linked list object
    CircularLinkedList circularList;

    // Add nodes to the end of the circular linked list
    circularList.add_node();

    return 0;
}
