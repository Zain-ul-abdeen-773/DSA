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
    int i =0;
    List(){
        head = nullptr;
    }
    void addnode(double data){
        node* newnode = new node(data);
        i++;
        if(head == nullptr){
            head = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }
    void Selection_sort(){
        for (node* i = head; i->next != nullptr; i = i->next) {
            node* minNode = i; 

            for (node* j = i->next; j != nullptr; j = j->next) {
                if (j->data < minNode->data) {
                    minNode = j; 
                }
            }
            if (minNode != i) {
                double temp = i->data;
                i->data = minNode->data;
                minNode->data = temp;
            }
        
           }
        }
        void printList() {
        node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    };
int main() {
    List l;
    l.addnode(45.5);
    l.addnode(34.6);
    l.addnode(21.9);
    l.addnode(200.5);

    cout << "Original List: ";
    l.printList();

    l.Selection_sort();

    cout << "Sorted List: ";
    l.printList();

    return 0;
}