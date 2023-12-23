#include<iostream>

using namespace std;
std::string Questionstring;
int count;

struct node {
    int data;
    node *next;
};

class linkedlist
{
private:
   struct node *head, *tail, *nextnode, *previous; 

public:
    linkedlist(){
        head = NULL;
        tail = NULL;
    }

    void add_node(){
        do{
            node *newnode = new node;
            std::cout<< "Enter the element: ";
            std::cin>> newnode->data;
            newnode->next=NULL;
            if (head==NULL){
                head = newnode;
                tail = newnode;
            }
            else{
                tail->next=newnode;
                tail = tail->next;
            }
            std::cout << "do you wan to add more element? (yes/no): ";
            std::cin >> Questionstring;
        }while (Questionstring=="yes");
        std::cout << "Linked List: ";
        display_and_getLenght();   
    }
    void display_and_getLenght()
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
        std::cout << "There are " << count << " nodes/elemet in linked list" << "\n";
    }

    void reverselinkedlist(){
        previous=0;
        tail=head;
        nextnode=head;
        while (nextnode!=0)
        {
            nextnode=nextnode->next;
            tail->next=previous;
            previous=tail;
            tail=nextnode;
        }
        head=previous;
        std::cout << "Reverse linked List: ";
        display_and_getLenght();
    }

};

int main()
{
    linkedlist a;
    a.add_node();
    a.reverselinkedlist();
    return 0;
}

