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
    struct node *head, *tail, *newnode;

public:
    doublylinkedlist()
    {
        std::cout << "1";
        head = 0;
        newnode->next = 0;
        newnode->previous = 0;
    }

    void add_node()
    {
        std::cout << "2";
        do
        {
            node *newnode = new node;
            std::cout << "Enter the element: ";
            std::cin >> newnode->data;

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
        std::cout << "there are" << count << "\n";
    }
};

int main()
{
    // Create a linked list object
    doublylinkedlist a;
    a.add_node();

    return 0;
}
