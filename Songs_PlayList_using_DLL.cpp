
#include<iostream>
using namespace std;
struct song{
    string title;
    string Artist;
    int duration;
    song* next;
    song* prev;
    song(string title,string Artist,int duration){
        this->Artist=Artist;
        this->duration=duration;
        this->title=title;
        next = prev = nullptr;
    }
};
class playlist{
  public:
  song* head;
  song* tail;
  playlist(){
     head = tail = nullptr;
  }
  void addsong_begnning(string title,string artist,int duration){
    song* newsong = new song(title,artist,duration);
    if(head == nullptr){
        head = newsong;
        tail = newsong;
    }
    else{
        newsong->next = head;
        head->prev = newsong;
        head = newsong;
    }
 }
 void addsong_end(string title,string artist,int duration){
    song* newsong = new song(title,artist,duration);
    if(head == nullptr){
        head = newsong;
        tail = newsong;
    }
    else{
        tail->next = newsong;
        newsong->prev = tail;
        newsong->next= nullptr;
        tail = newsong;
    }
 }
 void deletesong(string target){
    song* temp = head;
    bool check = false;
    while(temp != nullptr){
        if(temp->title == target){
            song* del = temp;
            check = true;
            if(temp->next!= nullptr){
                temp->next->prev = temp->prev;
            }
            else if(temp->next == nullptr){
                tail = temp->prev;
            }
            if(temp->prev!= nullptr){
                temp->prev->next= temp->next;
            } 
            delete del;
            break;
        }
        temp= temp->next;
    }
    if(check == false){
        cout<<target<<" Doesnot exsist in playlist!"<<endl;
    }
 }
 void search_song(string t){
    song* tmp = head;
    bool check = false;
    while(tmp != nullptr){
        if(tmp->Artist == t || tmp->title ==t){
            check = true;
            cout<<tmp->title<<" "<<tmp->Artist<<" "<<tmp->duration<<endl;
        }
        tmp = tmp->next;
    }
    if(check == false){
        cout<<"Not found"<<endl;
    }


 }
 void print(){
    song* tmp = head;
    cout<<"Play list:"<<endl;
    while(tmp != nullptr){
        cout<<tmp->title<<" "<<tmp->Artist<<" "<<tmp->duration<<endl;
      tmp = tmp->next;}
 }

};
int main(){
    playlist p;
    p.addsong_begnning("s","df",4);
    p.addsong_begnning("fg","rt",23);
    p.addsong_begnning("fg","rt",34);
    p.addsong_end("hj","ty",67);
    p.deletesong("s");
    p.print();
    p.search_song("fg");
    
    return 0;
    }