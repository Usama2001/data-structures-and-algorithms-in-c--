#include <iostream>

using namespace std;
std::string Questionstring, Questionstringfor123;
int count, pos, i = 1;

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
    struct node *head, *tail, *temp;

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
            // cheaker
            std::cout << tail->next->data;
            cout << endl;
        }
        else if (Questionstringfor123 == "2")
        {
            delete_node_end();
            // cheaker
            std::cout << tail->next->data;
            cout << endl;
        }
        else if (Questionstringfor123 == "3")
        {
            delete_node_specific();
        }
        else
        {
            std::cout << "No changes ";
        }
        std::cout << "Updated Linked List: ";
        display();
    }

    void delete_node_beginning()
    {
        temp=tail->next;
        if (tail == NULL)
        {
            std::cout << "There is no element in the circular linked list";
            cout << endl;
        }
        else if (temp->next=temp)
        {
            tail=0;
            free(temp);
        }
        else{
            tail->next=temp->next;
            free(temp);
        }
    }

    void delete_node_end()
    {
    }

    void delete_node_specific()
    {
    }
};

int main()
{
    // Create a circular linked list object
    CircularLinkedList circularList;

    // Add nodes to the end of the circular linked list
    circularList.delete_node();

    return 0;
}
