#include <iostream>

using namespace std;
std::string Questionstring, Questionstringfor123;
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
    struct node *head, *tail, *insertEnt;

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
        insertEnt=tail;
        std::cout << "Linked List: ";
        display();
    }

    void insert_node(){
        add_node();

        std::cout << "do you want to add node at Beginning >> Press 1" << "\n" 
        << "do you want to add node at End >> Press 2" << "\n"
        << "do you want to add node at specific position >> Press 3" << "\n" 
        << "do you want to stop the code >> Press 4" << "\n";
        std::cin>> Questionstringfor123;

        if (Questionstringfor123=="1"){
            insertion_at_beginning(); 
        }
        else if (Questionstringfor123=="2"){
            insertion_at_end();
        }
        else if (Questionstringfor123=="3"){
            insertion_at_specific();
        }
        else{
            std::cout << "No change in results ";
        }
        std::cout << "Updated Linked List: ";
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

    void insertion_at_beginning(){
        node *newnode = new node;
        std::cout << "Enter the element: ";
        std::cin >> newnode->data;
        newnode->next=0;
        newnode->previous=0;
        head->previous=head;
        newnode->next=head;
        head=newnode;
    }

    void insertion_at_end(){
        node *newnode = new node;
        std::cout << "Enter the element: ";
        std::cin >> newnode->data;
        newnode->next=0;
        newnode->previous=0;
        insertEnt->next=newnode;
        newnode->previous=insertEnt;
        insertEnt=newnode;
    }

    void insertion_at_specific(){
    }

};

int main()
{
    // Create a linked list object
    doublylinkedlist a;
    a.insert_node();

    return 0;
}
