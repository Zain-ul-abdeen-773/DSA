#include <iostream>
#include<vector>
using namespace std;

struct Node {
    int data;   
    Node* next; 

    Node(int value) {
        data = value;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList(){
        this->head = nullptr;
    }

     void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = nullptr;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if(temp->next != nullptr){
                cout<<"->";
            }
            temp = temp->next;
        }
        cout<<endl;
    }

    Node* findMiddle(Node* head) {
        if (head == nullptr){
            return nullptr;
        }
        Node* slow = head;
        Node* fast = head->next;
        // Move fast by two and slow by one
        // When Fast is at end then slow is at middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

// Merges two sorted linked lists and returns the head of the merged list
Node* merge(Node* left, Node* right) {
    
    // If the left list is empty, return the right list (since it's already sorted)
    if (left == nullptr) {
        return right;
    }
    
    // If the right list is empty, return the left list (since it's already sorted)
    if (right == nullptr) {
        return left;
    }
    
    // If left's data is smaller, merge the rest of left and right recursively
    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    } 
    // If right's data is smaller, merge left and rest of right recursively
    else {
        right->next = merge(left, right->next);
        return right;
    }
}


   Node* mergeSort(Node* head) {
        // Base case: if head is null or only one element in list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Split the list into two halves
        Node* middle = findMiddle(head);
        Node* nextToMiddle = middle->next;
        middle->next = nullptr;

        // Sort the two halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(nextToMiddle);

        // Merge the sorted halves
        Node* sortedList = merge(left, right);
        return sortedList;
    }
    // Method to initiate merge sort and update the head of the list
    void sort() {
        head = mergeSort(head);
    }
};

int main() {
    LinkedList list;
    vector<int>values{10,20,8,17,5,13,4};
    for(int value : values){
        list.append(value);
    }
    cout << "Initial Linked List: ";
    list.display();

    list.sort();

    cout << "Sorted Linked List: ";
    list.display();
    values.clear();
    return 0;
}