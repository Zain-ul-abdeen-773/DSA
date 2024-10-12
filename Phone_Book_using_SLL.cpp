#include<iostream>
using namespace std;
struct Phone_node{
    string phone;
    string name;
    Phone_node *next;
};

class Phone_List{
    public:
    Phone_node *head;
    Phone_List();
    ~Phone_List();
    void print();
    void insert_at_beggining(string,string);
    void insert_at_end(string,string);
    void modify_phone_no(string,string);
    void modify_name(string,string);
    void modify_both(string,string,string,string);
    void delete_contact(string);
    void search_phone_no(string);
    void total_contacts();
    void insert_after(Phone_node*,string,string);
    void insert_at_position(int,string,string);
};

Phone_List::Phone_List(){
    head = NULL;
}

Phone_List::~Phone_List(){
    Phone_node* current = head;
    while (current != nullptr){
        Phone_node * temp = current;
        current = current->next;
        delete temp;
    }
}

void Phone_List::print(){
    Phone_node* current;
    cout<<"Name    Phone No"<<endl;
    for(current = head ; current!= nullptr; current=current->next) {
        cout<<current->name<<"    "<<current->phone<<endl;
    }
}

void Phone_List::insert_at_beggining(string name,string phone){
        Phone_node * current = new Phone_node();
        current->name = name;
        current->phone = phone;
        current->next = head;
        head = current;
        }

void Phone_List::insert_at_end(string name,string phone){
    Phone_node* newcontact = new Phone_node();
    newcontact->name = name;
    newcontact->phone = phone;
    newcontact->next = NULL;

    if(head == NULL){
        head = newcontact;
    }
    else{
        Phone_node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newcontact;
    }
}

void Phone_List::modify_phone_no(string check,string new_phone){
    Phone_node *current = head;
    while(current != nullptr){
        if(current->name==check){
            current->phone=new_phone;
            break;
        }
        else{
             cout<<"contact name not found!"<<endl;
        }
        current =  current->next;
    }
   
}

void Phone_List::modify_name(string check,string new_name){
    Phone_node * current = head;
    while(current != NULL){
        if(check == current->phone){
            current->name = new_name;
            break;
        }
        else{
            cout<<"Contact number not found!"<<endl;
        }
        current = current -> next;
    }
}

void Phone_List::modify_both(string old_name,string old_no,string new_name,string new_no){
    Phone_node * current = head;
    while(current != nullptr){
        if(current->name == old_name && current->phone == old_no){
            current->name=new_name;
            current->phone=new_no;
            break;
        }
        else{
            cout<<"Please a emnter a valid name and phone number"<<endl;
        }
        current = current->next;
    }
}

void Phone_List::delete_contact(string target_name){
    Phone_node* current = head;
    Phone_node* previous = nullptr;

    if(current != nullptr && current->name == target_name){
        head = current->next;
        delete current;
    }

    while(current != nullptr && current-> name == target_name){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    delete current;

}

void Phone_List::search_phone_no(string target_name){
    Phone_node * current = head;
    while(current != nullptr){
        if(current->name == target_name){
            cout<<"The Name you entered have phone num:"<<endl;
            cout<<current->phone<<endl;
            break;
        }
        else{
            cout<<"Please enter a valid name"<<endl;
            break;
        }
        current = current->next;
    }
}

void Phone_List::total_contacts(){
    Phone_node* current = head;
    int count =0;
    while(current != nullptr){
        count++;
        current = current->next;
    }
    cout<<"Total Contacts: "<<count<<endl;
}
void Phone_List::insert_after(Phone_node* prev,string name,string phone){
    if(prev == nullptr){
        cout<<"Cant insert a contact after null"<<endl;
        return;
    }
    Phone_node* new_contact = new Phone_node();
    new_contact->name=name;
    new_contact->phone=phone;
    new_contact->next=prev->next;
    prev->next = new_contact;
}
void Phone_List::insert_at_position(int position,string name,string phone){
    Phone_node* newcontact = new Phone_node();
    newcontact->name=name;
    newcontact->phone=phone;

    if(position == 1){
        newcontact->next = head;
        head = newcontact;
        return;
    }
    
    Phone_node* current = head;
    Phone_node* prev = nullptr;
    int current_position = 1;
    
    while(current != nullptr && current_position < position){
       prev = current;
       current = current->next;
       current_position++;
    }
      if (current_position == position) {
        prev->next = newcontact;
        newcontact->next = current;
    } 
    else {
        cout << "Position out of bounds" << endl;
        delete newcontact; 
    }
}
int main(){
    Phone_List contacts;

    contacts.insert_at_beggining("Zain","03091754514");
    contacts.insert_at_beggining("Umer","03214569856");
    contacts.insert_at_end("Talha","03569654128");
    contacts.insert_after(contacts.head->next,"Shelby","778545");
    contacts.insert_at_position(3,"Hassan","98564785213");
    contacts.modify_phone_no("Umer","b");
    contacts.modify_name("b","taha");
    contacts.modify_both("taha","b","Far","785");
    contacts.delete_contact("Far");
    contacts.print();
    contacts.total_contacts();
    contacts.search_phone_no("Zain");
    
    return 0;
}