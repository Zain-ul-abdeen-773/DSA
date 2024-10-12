
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList : public Node{
private:
    Node* head;  
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void removeDuplicates() {
        Node* current = head;
        while (current != nullptr) {
            Node* runner = current->next;
            while (runner != nullptr) {
                if (runner->data == current->data) {
                    
                    Node* duplicate = runner;

                    if (runner->prev != nullptr) {
                        runner->prev->next = runner->next;
                    }
                    if (runner->next != nullptr) {
                        runner->next->prev = runner->prev;
                    }

                    runner = runner->next; 

                    delete duplicate;  
                } else {
                    runner = runner->next;  
                }
            }
            current = current->next; 
        }
    }
};

int main() {
    DoublyLinkedList dll;

    cout << "Original List: ";
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(3);
    dll.append(3);
    dll.display();

    dll.removeDuplicates();
    cout << "After removing duplicates: ";
    dll.display();

   

    return 0;
}
