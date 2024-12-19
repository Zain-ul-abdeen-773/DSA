#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;

    node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Linklist {
public:
    node* head;

    Linklist() {
        this->head = nullptr;
    }

    void print() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void append(int data) {
        node* c = new node(data);
        if (head == nullptr) {
            head = c;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = c;
    }

    void partition(node* head, node*& left, node*& right) {
        node* pivot = head;
        left = right = nullptr;
        node* current = head->next;

        while (current != nullptr) {
            node* nextNode = current->next;  // Save the next node
            if (current->data < pivot->data) {
                current->next = left;
                left = current;
            } else {
                current->next = right;
                right = current;
            }
            current = nextNode;  // Move to the next node
        }
    }

    node* Quick_sort(node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        node *left, *right;
        left = right = nullptr;

        partition(head, left, right);

        left = Quick_sort(left);
        right = Quick_sort(right);

        // Combine sorted left and pivot
        node* tail = left;
        if (tail != nullptr) {
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = head;
        } else {
            left = head;
        }

        // Attach sorted right to pivot
        head->next = right;

        return left;
    }

    void sort() {
        head = Quick_sort(head);
    }
};

int main() {
    Linklist l;
    l.append(90);
    l.append(23);
    l.append(65);
    l.append(233);
    l.print();

    l.sort();
    l.print();

    return 0;
}
