
#include <iostream>

using namespace std;
std::string Questionstring;
int count;

struct node
{
    int data;
    node *next;
    node *previous;
};

class circularDoublyLinkedList
{
private:
    struct node *head, *tail;

public:
    circularDoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void add_node()
    {
        do
        {
            node *newnode = new node;
            cout << "Enter the element: ";
            cin >> newnode->data;

            newnode->next = nullptr;
            newnode->previous = nullptr;
            if (head == nullptr)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                tail->next = newnode;
                newnode->previous = tail;
                tail = newnode;
            }

            cout << "Do you want to add more elements? (yes/no): ";
            cin >> Questionstring;

        } while (Questionstring == "yes");

        if (head != nullptr)
        {
            tail->next = head; // Make the list circular
            head->previous = tail; // Update the previous pointer of the first node
        }

        cout << "Circular Doubly Linked List: ";
        display();
    }

    void display()
    {
        node *current = head;
        count = 0;
        do
        {
            count++;
            cout << "(" << current->previous << ") " << current->data << " (" << current->next << ") ";
            current = current->next;
        } while (current != head);

        cout << endl;
        cout << "There are " << count << " nodes/elements in the circular doubly linked list" << endl;
    }
};

int main()
{
    // Create a circular doubly linked list object
    circularDoublyLinkedList a;
    a.add_node();

    return 0;
}

