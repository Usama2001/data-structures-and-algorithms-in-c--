#include<iostream>


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
    doublylinkedlist(){
        head=0;
        newnode->next=0;
        newnode->previous=0;
    }

    void add_node(){
        node *newnode = new node;
        std::cout << "Enter the element: ";
        std::cin >> newnode->data;



    }
    

};


doublylinkedlist::~doublylinkedlist()
{
}
