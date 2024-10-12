#include<iostream>
using namespace std;
# define Max 2
class Queue{
 public:
   int front;
   int rear;
   int count;
   double arr[Max];
   Queue(){
    front = rear = -1;
    count= 0;
   }
   bool isEmpty(){
    return front==-1 ;
   }
   bool isFull(){
     return (rear + 1) % Max == front ;
   }
   void Enqueue(double data){
     if(isFull()){
         cout<<"Queue is Full"<<endl;
     }
     else{
        if(isEmpty()){
            front=0;
        }
           count++;
           rear = (rear+1)%Max;
           arr[rear] = data;
           cout<<"Enqued: "<<data<<endl;
     }
   }
   void Dequeue(){
      if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
      }
      else{
        count--;
        cout<<"Dequed: "<< arr[front]<<endl;
        if(front == rear){   
        front = rear = -1;
        }else
        {
        front = (front+1) % Max;
        }
      }
   }
   void print(){
      if(isEmpty()){
        cout<<"Queue is Empty!"<<endl;
      }
      else{
        int x=0;
        for(int start = front;start<=rear;start++){
            cout<<++x<<". "<<arr[start]<<endl;
        }
      }
   }
void size(){
   cout<<"Queue size: "<<count<<endl; 
}
};
int main(){
    Queue q;
    q.Enqueue(34.5);
    q.Enqueue(23.78);
    q.print();
    q.size();
    q.Dequeue();
    q.Dequeue();
    q.print();
    q.size();
    return 0;
}