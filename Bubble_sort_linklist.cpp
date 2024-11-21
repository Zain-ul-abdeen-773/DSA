#include<iostream>
using namespace std;
struct node{
    double data;
    node* next;
    node(double data){
        this->data = data;
        next  = nullptr;
    }
};
class List{
    public:
    node* head;
    List(){
        head = nullptr;
    }
    void addnode(double data){
        node* newnode = new node(data);
        if(head == nullptr){
            head = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }
    void Bubble_sort(){
        node* tmp = head;
        bool swapped = false;
        while(tmp->next != nullptr){
            node* ahead = tmp->next;
            while(ahead != nullptr){
                if(tmp->data > ahead->data){
                    swap(tmp->data,ahead->data);
                    swapped = true;
                }
                ahead = ahead->next;
            }
          if(!swapped){
            break;
          }
          tmp = tmp->next;
        }
    }
void print(){
    node* current;
    for(current = head;current != nullptr;current = current->next){
        cout<<current->data<<" ";
    }
}
};
int main(){
    List l;
    l.addnode(45);
    l.addnode(34.6);
    l.addnode(21.9);
    l.addnode(200.5);
    l.addnode(300);
    l.Bubble_sort();
    l.print();
    return 0;
}