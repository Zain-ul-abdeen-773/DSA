#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void append(int data) {
        Node* new_node = new Node{data, nullptr};
        if (head == nullptr) {
            head = new_node;
            new_node->next = head;
            cout << "Node with data " << data << " appended as head.\n";
            return;
        }
        Node* current = head;
        while (current->next != head){
            current = current->next;
        }
        current->next = new_node;
        new_node->next = head;
        cout << "Node with data " << data << " appended.\n";
    }
    void prepend(int data) {
        Node* new_node = new Node{data, nullptr};
        if (!head) {
            head = new_node;
            new_node->next = head;
            cout << "Node with data " << data << " prepended as head.\n";
            return;
        }
        Node* current = head;
        while (current->next != head)
            current = current->next;
        new_node->next = head;
        current->next = new_node;
        head = new_node;
        cout << "Node with data " << data << " prepended.\n";
    }

    void deleteNode(int key) {
        if (!head) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        // If head needs to be deleted
        if (current->data == key) {
            if (current->next == head) {
                delete current;
                head = nullptr;
                cout << "Node with data " << key << " deleted. List is now empty.\n";
                return;
            }
           while (current->next != head)
                current = current->next;
            Node* temp = head;
            head = head->next;
            current->next = head;
            delete temp;
            cout << "Node with data " << key << " deleted from head.\n";
            return;
        }

        prev = head;
        current = head->next;
        while (current != head) {
            if (current->data == key) {
                prev->next = current->next;
                delete current;
                cout << "Node with data " << key << " deleted.\n";
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Node with data " << key << " not found.\n";
    }

    void traverse() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* current = head;
        cout << "List elements: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    bool search(int key) {
        if (!head) {
            cout << "List is empty.\n";
            return false;
        }
        Node* current = head;
        do {
            if (current->data == key) {
                cout << "Node with data " << key << " found.\n";
                return true;
            }
            current = current->next;
        } while (current != head);
        cout << "Node with data " << key << " not found.\n";
        return false;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (!head)
            return;
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }
};
int main() {
    CircularLinkedList cll;

    // Append nodes
    cll.append(10);
    cll.append(20);
    cll.append(30);

    // Prepend a node
    cll.prepend(5);

    // Traverse the list
    cll.traverse();  // Output: List elements: 5 10 20 30

    // Search for elements
    cll.search(20);  // Output: Node with data 20 found.
    cll.search(40);  // Output: Node with data 40 not found.

    // Delete a node
    cll.deleteNode(20);
    cll.traverse();  // Output: List elements: 5 10 30

    // Delete head
    cll.deleteNode(5);
    cll.traverse();  // Output: List elements: 10 30

    // Delete a non-existing node
    cll.deleteNode(100);  // Output: Node with data 100 not found.

    return 0;
}
