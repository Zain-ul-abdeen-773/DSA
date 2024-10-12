#include<iostream>
#include<string>
using namespace std;
class node{
    public:
    string data;
    node* next;
};
class Queue{
    public:
    node* front;
    node* rear;
    Queue(){
        front = rear = nullptr;
    }
    bool isEmpty(){
        return front == nullptr;
    }
    void enqueue(string data){
        node* newnode = new node();
        newnode->data = data;
        if(isEmpty()){
            front = newnode;
            rear = newnode;
            return;
        }
        rear->next = newnode;
        newnode->next = nullptr;
        rear = newnode;
        
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"queue is Empty"<<endl;
        }
        else{
            
            cout<<"Dequed: "<<front->data<<endl;
            node *temp = front;
            front = front->next;
            delete temp;
        }
        }
    void print(){
       if(isEmpty()){
          cout<<"Cant print anything"<<endl;
       }
       else{
        node *tmp;
        for(tmp = front;tmp != NULL;tmp = tmp->next){
            cout<<tmp -> data <<" ";
        }
       }
       cout<<endl;
    }
    void Length(){
    node* current = front; 
    if (current == nullptr) {
        cout << "The queue is empty." <<endl;
        return;
    }
    cout << "Lengths of each string in the queue:" << endl;
    while (current != nullptr) {
        cout<< current->data << " has length: " << current->data.length() << endl;
        dequeue();
        current = current->next;
    }
    }
};
int main(){
    Queue q;
    q.enqueue("hello");
    q.enqueue("world");
    q.Length();
    
    return 0;
}