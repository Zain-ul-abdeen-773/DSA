#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAfter(Node* prevNode, int data) {
        if (prevNode == nullptr) {
            cout << "Previous node cannot be null." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    

    void deleteNode(int key) {
        Node* current = head;
        Node* prev = nullptr;

        if (current != nullptr && current->data == key) {
            head = current->next;
            delete current;
            return;
        }

        while (current != nullptr && current->data != key) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            return;
        }

        prev->next = current->next;
        delete current;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void modfiyElement(int old_element,int new_element){
        Node *current = head;
        while(current != nullptr){
            if(current->data == old_element){
                current->data = new_element;
                return;
            }
            current = current->next;
        }
        cout<<"Element not Found!"<<endl;
    }

    void searchElement(int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                cout << key << " Found in List" << endl;
                return;
            }
            current = current->next;
            
        }
         cout << "Element not found." << endl;
    }

    void changeHead(Node* newHead) {
        if (newHead != nullptr) {
            head = newHead;
        } else {
            cout << "New head node cannot be null." << endl;
        }
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtBeginning(2);
    list.changeHead(list.head->next);
    list.insertAtEnd(3);
    list.insertAfter(list.head->next, 4);
    cout << "Linked list: "; 
    list.printList();
    list.searchElement(4);
    list.deleteNode(3);
    list.deleteNode(1);
    list.modfiyElement(4,6);
    cout << "Linked list after deletion & Modification: ";
    list.printList();

    return 0;
}