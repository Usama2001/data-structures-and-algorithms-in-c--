#include <iostream>

using namespace std;
std::string Questionstring, Questionstringfor123;
int count, pos,i=1;

struct node
{
    int data;
    node *next;
    node *previous;
};

class doublylinkedlist
{
private:
    struct node *head, *tail, *deleteatend;

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
            delete_at_beginning();
        }
        else if (Questionstringfor123 == "2")
        {
            delete_at_end();
        }
        else if (Questionstringfor123 == "3")
        {
           delete_at_specific(); 
        }
        else
        {
            std::cout << "No change in results ";
        }
        if (Questionstringfor123 != "4")
        {
            std::cout << "Updated Linked List: ";
        }
        display();
    }

    void delete_at_beginning(){
        if (head==0){
            std::cout << "Doubly Linked list is empty";
        }
        else{
            tail=head;
            head=head->next;
            head->previous=0;
            free(tail);
        }
    }

    void delete_at_end(){
        if (head==0){
            std::cout << "Doubly Linked list is empty";
        }
        else{
            tail->previous->next=0;
            tail=tail->previous;
            tail->next=0;
            free(tail);
        }
    }


    void delete_at_specific (){
        if (head==0){
            std::cout << "Doubly Linked list is empty";
        }
        else{
            do {
                std::cout << "Enter the position: " ;
                std::cin >> pos;
            } while (pos>count);
            tail=head;
            while (i<pos)
            {
                tail=tail->next;
                ++i;
            }
            tail->previous->next=tail->next;
            tail->next->previous=tail->previous;
            free(tail);
        }
    }
};

int main()
{
    // Create a linked list object
    doublylinkedlist a;
    a.delete_node();

    return 0;
}
