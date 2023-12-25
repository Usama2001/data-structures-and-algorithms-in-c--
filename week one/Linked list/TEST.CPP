#include <iostream>

// Node structure for a doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor to initialize data and pointers
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            // If the list is empty, set both head and tail to the new node
            head = tail = newNode;
        } else {
            // Otherwise, update the links and set the new node as the new head
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to display the elements of the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "(" << current->prev << ") " << current->data << " (" << current->next << ") "  ;
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList myList;

    // Get the number of nodes from the user
    int numNodes;
    std::cout << "Enter the number of nodes: ";
    std::cin >> numNodes;

    // Get data for each node from the user
    for (int i = 0; i < numNodes; ++i) {
        int nodeData;
        std::cout << "Enter data for node " << i + 1 << ": ";
        std::cin >> nodeData;
        myList.insertAtBeginning(nodeData);
    }

    // Display the doubly linked list
    std::cout << "Doubly Linked List: ";
    myList.display();

    return 0;
}
