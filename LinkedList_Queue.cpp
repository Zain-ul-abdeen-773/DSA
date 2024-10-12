#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
class Queue{
    public:
    Node* front;
    Node* rear;
    Queue(){
        front = rear = nullptr;
    }
    bool isEmpty(){
        return front == nullptr;
    }
    void Enqueue(int data){
        Node *newnode = new Node();
        newnode->data = data;
        if(isEmpty()){
            front = newnode;
            rear = newnode;
        }
        rear->next  = newnode ;
        rear = newnode;
        cout<<"Enqueued: "<<data<<endl;
    }
    void Dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }
        else{
            cout<<"Dequed: "<<front->data<<endl;
            Node* del = front;
            front = front->next;
            delete del;
        }
    }
    void print(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }
        Node *current;
        int i =0;
        for(current = front;current != nullptr;current = current->next){
            cout<<++i<<". "<<current->data<<endl;
        }
    }
    ~Queue(){
        Node* curr = front;
        Node* clear = nullptr;
        while(curr != nullptr){
            clear = curr;
            curr = curr->next;
            delete clear;
        }
    }
};
int main(){
    Queue q;
    q.Enqueue(23);
    q.Enqueue(45);
    q.print();
    q.Dequeue();
    q.Dequeue();
    q.print();
    return 0;
}