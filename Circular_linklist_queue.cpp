#include <iostream>
using namespace std;

struct Node {
    int volatile data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class CircularQueue {
private:
    Node* rear; 
public:
    CircularQueue() : rear(nullptr) {}
    ~CircularQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    bool isEmpty()  {
        return rear == nullptr;
    }
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        
        Node* front = rear->next;
        int value = front->data;
        
        if (rear == front) {
            rear = nullptr;
        } else {
            rear->next = front->next;
        }
        
        delete front;
        cout << "Dequeued: " << value << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = rear->next;
        cout << "Queue elements: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << endl;
    }
    
    int frontElement() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty. No front element.");
        }
        return rear->next->data;
    }
    
    int rearElement() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty. No rear element.");
        }
        return rear->data;
    }
};

int main() {
    CircularQueue cq;
    
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    
    cq.display(); 
    
    cq.dequeue();
    cq.dequeue();
    
    cq.display(); 
    
    cq.enqueue(50);
    
    cq.display(); 
    
    try {
        cout << "Front element: " << cq.frontElement() << endl; 
        cout << "Rear element: " << cq.rearElement() << endl;  
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue(); 
    cq.display(); 
    
    return 0;
}
