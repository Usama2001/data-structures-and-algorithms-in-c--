#include <iostream>

using namespace std;
std::string Questionstring;

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
                newnode->next = head; // Make it point to itself to form a circle
            }
            else
            {
                // Otherwise, add the new node to the end and update the tail
                tail->next = newnode;
                tail = newnode;
                newnode->next = head; // Make it point back to the head to form a circle
            }

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
};

int main()
{
    // Create a circular linked list object
    CircularLinkedList circularList;

    // Add nodes to the end of the circular linked list
    circularList.add_node();

    return 0;
}
