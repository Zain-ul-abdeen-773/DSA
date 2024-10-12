#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;  

    DLL() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;  
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) { 
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtPosition(int data, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* temp = head;

        for (int i = 1; temp != nullptr && i < position-1 ; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position greater than the number of nodes." << endl;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;  
        }
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "The list is already empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; 
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (tail == nullptr) {
            cout << "The list is already empty." << endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;  
        }
        delete temp;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "The list is already empty." << endl;
            return;
        }

        if (position == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < position-1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position is greater than the number of nodes." << endl;
            return;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;  
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        delete temp;
    }

    void printListForward() {
        Node* temp = head;
        cout << "Forward List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void printListReverse() {
        Node* temp = tail;
        if (temp == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        cout << "Reverse List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DLL f;
    // f.insertAtEnd(10);
    // f.insertAtEnd(20);
    // f.insertAtBeginning(5);
    f.insertAtPosition(15, 1);
    f.insertAtEnd(45);
    f.insertAtPosition(21,2);

    cout << "After Insertions:" << endl;
    f.printListForward();
    f.printListReverse();

    f.deleteAtBeginning();
    f.deleteAtEnd();
    f.deleteAtPosition(1);

    cout << "After Deletions:" << endl;
    f.printListForward();

    return 0;
}
