
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class DLL{
    public:
    Node *head;
    DLL(){
        head = NULL;
    }

void insertAtBeginning( int data)
{
    
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}


void insertAtEnd( int data)
{
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

   
    temp->next = newNode;
    newNode->prev = temp;
}



void insertAtPosition( int data, int position)
{
    if (position < 1) {
        cout << "Position should be >= 1." << endl;
        return;
    }

    if (position == 1) {
        insertAtBeginning( data);
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;

    for (int i = 1; temp != nullptr && i < position - 1;
         i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position greater than the number of nodes."
             << endl;
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteAtBeginning()
{
    if (head == nullptr) {
        cout << "The list is already empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void deleteAtEnd()
{
    if (head == nullptr) {
        cout << "The list is already empty." << endl;
        return;
    }

    Node* temp = head;
    if (temp->next == nullptr) {
        head = nullptr;
        delete temp;
        return;
    }

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

void deleteAtPosition( int position)
{
    if (head == nullptr) {
        cout << "The list is already empty." << endl;
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position is greater than the number of "
                "nodes."
             << endl;
        return;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    delete temp;
}


void printListForward()
{
    Node* temp = head;
    cout << "Forward List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void printListReverse()
{
    Node* temp = head;
    if (temp == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

  
    while (temp->next != nullptr) {
        temp = temp->next;
    }


    cout << "Reverse List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
};
int main()
{
    DLL f;
    f.insertAtEnd( 10);
    f.insertAtEnd( 20);
    f.insertAtBeginning( 5);
    f.insertAtPosition( 15, 2);
    cout << "After Insertions:" << endl;
    f.printListForward();
    f.printListReverse();
    f.deleteAtBeginning();
    f.deleteAtEnd();
    f.deleteAtPosition( 2);
    cout << "After Deletions:" << endl;
    f.printListForward();

    return 0;
}
