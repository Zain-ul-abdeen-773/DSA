#include <iostream>
using namespace std;
#define MAX 10

class Queue {
public:
    int rear;
    int front;
    double elements[MAX];

    Queue() {
        rear = -1;
        front = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return rear == MAX - 1;
    }
    void enqueue(double x) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
        } else {
            if (isEmpty()) {
                front = 0;
            }
            rear = (rear + 1) % MAX; //Circular  queue
            elements[rear] = x;
            cout<<"Enqueued : "<<x<<endl;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            double g = elements[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % MAX; //Circular  queue
            }
            cout << "Dequeued element: " << g << endl;
        }
    }
    int size() {
        if (isEmpty()) {
            return 0;
        } else {
            return (rear + 1 - front) % MAX;
        }
    }
    double read_peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0; 
        } else {
            return elements[front];
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout<<"Queue Elements: "<<endl;
            for (int i = front; i <= rear; i = (i + 1) % MAX) {
                cout << elements[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10.5);
    q.enqueue(20.2);
    q.enqueue(30.7);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(56.2);
    q.enqueue(79.8);
    q.enqueue(68.4);
    q.display();
    cout << "Size: " << q.size() << endl;
    cout << "Peek: " << q.read_peek() << endl;

    return 0;
}