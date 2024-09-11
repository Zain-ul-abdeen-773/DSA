#include<iostream>
using namespace std;
#define MAX 100

class Stack{
    protected:
     int top;
     double elements[MAX];
    public:
     Stack(){
        top=-1;
     } 
     bool isempty(){
       bool check;
       check = top < 0;
       return check;
     }
     void push(double x){
        if( top >= (MAX - 1)){
            cout<<"Stack Full!"<<endl;
        }
        else{
            elements[++top]=x;
            cout<<x <<" Pushed into Stack!"<<endl;
        }
     }
     int pop(){
        if (isempty()){
            cout<<"Stack is empty!"<<endl;
            return 0;
        }
        else{
         double x = elements[top--];
         cout<<x<<" Popped out!"<<endl;
         return x;
        }
     }
     void read_top(){
        cout<<"Top of stack is:" <<elements[top]<<endl;
     }
     
};
int main(){
  Stack s;
  s.isempty();
  s.push(24.3);
  s.push(5.1);
  s.push(19.8);
  s.pop();
  s.read_top();
}