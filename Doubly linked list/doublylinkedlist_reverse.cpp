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

class doublylinkedlist
{
private:
    struct node *head, *tail, *nextnode, *current;

public:
    doublylinkedlist()
    {
        head = 0;
        tail =0;
    }
    void add_node()
    {
        do
        {
            node *newnode = new node;
            std::cout << "Enter the element: ";
            std::cin >> newnode->data;

            newnode->next=0;
            newnode->previous=0;
            if (head == 0)
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

            std::cout << "do you wan to add more element? (yes/no): ";
            std::cin >> Questionstring;

        } while (Questionstring == "yes");
        std::cout << "Linked List: ";
        display();
    }

    void display()
    {
        tail = head;
        count = 0;
        while (tail != NULL)
        {
            count++;
            std::cout << "(" << tail->previous << ") " << tail->data << " (" << tail->next << ") ";
            tail = tail->next;
        }
        std::cout << std::endl;
        std::cout << "there are " << count << "\n";
    }

    void reverse(){
        add_node();

        current=head;
        tail=0;
        while (current!=0)
        {
            tail = current->previous;
            current->previous = current->next;
            current->next = tail;
            current = current->previous;
        }

        if (tail != nullptr) {
            head = tail->previous;
            tail = tail;
        }
        display();
    }
};

int main()
{
    // Create a linked list object
    doublylinkedlist a;
    a.reverse();

    return 0;
}
