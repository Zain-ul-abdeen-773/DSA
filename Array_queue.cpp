#include<iostream>
using namespace std;
# define Max 3

class Queue{
    public:
    int front;
    int rear;
    int arr[Max];
    Queue(){
        front = rear = -1;
    }
    bool isEmpty(){
        return front == -1;
    }
    bool  isFull(){
        return rear == Max-1;
    }
    void Enqueue(int data){
        if(isFull()==true){
            cout<<"Queue is full"<<endl;
        }
        else{
        	if(isEmpty()){
        		front=0;
			}
            arr[++rear] = data;
        }
    }
    void Dequeue(){
        if(isEmpty() == true){
            cout<<"Queue is Empty!"<<endl;
        }
        else{
            cout<<"Dequeued: "  <<arr[front] <<endl;
            
            for(int i=front;i<rear;i++){
                arr[i] = arr[i+1] ;
            }
            rear--;      
        }
    }
    void Front(){
        if (isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }
        cout<<"Front : "<<arr[front]<<endl;
    }
    void print(){
       if (isEmpty()==true) {
          cout << "Queue is Empty" << endl;
        }
        int g = 0;
        for(int i=front;i<=rear;i++){
            cout<<++g <<". "<<arr[i]<<endl;
        }
    }
};
int main(){
    Queue q;
    q.Enqueue(45);
    q.Enqueue(23);
    q.Enqueue(67);
    q.Enqueue(76);
    q.print();
    q.Dequeue();
    q.print();
    q.Dequeue();
    q.Front();
    
    
}