#include<iostream>
using namespace std;

class Player{
   public:
   class song{
      public:
      int id;
      string title;
      float time;
      song* next;

   };

   song* head;

   public:

   Player(){
      head = nullptr;
   }

   void append(int id,string title,float time){
      song* newSong = new song;
      newSong->id = id;
      newSong->title = title;
      newSong->time = time;
      newSong->next = nullptr;
      
      if(head == NULL){
         head = newSong;
         return ;
      }
      song* temp = head;
      while(temp->next != NULL){
         temp = temp->next;
      }
      temp->next = newSong;
   }

   void insert(int position,int id,string title,float time){
      song* newSong = new song;
      newSong->id = id;
      newSong->title = title;
      newSong->time = time;
      newSong->next = nullptr;

      if(head == NULL){
         if(position != 1){
            cout<<"The song player is empty now, enter valid position to insert"<<endl;
            return;
         }
         head = newSong;
         play();
         return ;
      }

      song* temp = head;
      int i=1;
      while(temp->next != NULL && position-1 > i){
         temp = temp->next;
         i++;
      }

      if(temp -> next == NULL && !(position-1 > i)){
         cout<<"Enter the valid position, The position could be out of the playlist"<<endl;
         return;
      } 

      newSong->next = temp->next;
      temp->next = newSong;
      play();
   }
   
   void sort(){
      if(head == NULL || head->next == NULL){
         return ;
      }
      for(song* temp = head; temp != NULL; temp = temp->next){
         for(song* temp1 = temp->next; temp1 != NULL; temp1 = temp1->next){
            if(temp1->id < temp->id){
               swap(temp1->id,temp->id);
               swap(temp1->title,temp->title);
               swap(temp1->time,temp->time);
            }
         }
      }
      play();
   }

   void dlt(int position){
      if(position == 1){
         song* temp = head;
         head = head->next;
         delete temp;
         play();
         return ;
      }
      song* temp = head;

      int i=1;
      while(temp->next != NULL && position-1 > i){
         temp = temp->next;
         i++;
      }

      if(temp -> next == NULL && !(position-1 > i)){
         cout<<"Enter the valid position, The position could be out of the playlist"<<endl;
         return;
      } 

      song* todlt = temp->next;
      temp->next = temp->next->next;
      delete todlt;

      play();
   }

   void play(){
      if(head == NULL){
         cout<<"The player is empty"<<endl;
         return;
      }

      song* temp = head;
      cout<<"The Songs:"<<endl;
      while(temp != NULL){
         cout<<"Id: "<<temp->id<<endl<<"Title: "<<temp->title<<endl<<"Duration(in minutes): "<<temp->time<<endl;
         cout<<"-----------------------------------------------------------"<<endl;
         temp = temp->next;
      }
   }
};

int main() {
    Player p;
    int id;
    string title;
    float time;
    int choice;

    cout<<"Enter the your choice:"<<endl<<"1.append"<<endl<<"2.insert"<<endl<<"3.sort"<<endl<<"4.delete"<<endl<<"5.play"<<endl<<"6.exit"<<endl;
    cin>>choice;

    while(choice != 6){
    
      if(choice == 1){

         int n;
         cout<<"Enter number of elements to append:";
         cin>>n;
         for(int i=0;i<n;i++){
            cout<<"Enter the id:"<<endl;
            cin>>id;
            cout<<"Enter the title:"<<endl;
            cin.ignore();
            getline(cin,title);
            cout<<"Enter the duration(in minutes):"<<endl;
            cin>>time;
            p.append(id,title,time);
         }
      }
      else if(choice == 2){
         int position;
         cout<<"Enter the id:"<<endl;
         cin>>id;
         cout<<"Enter the title:"<<endl;
         cin.ignore();
         getline(cin,title);
         cout<<"Enter the duration(in minutes):"<<endl;
         cin>>time;
         cout<<"Enter the position:"<<endl;
         cin>>position;
         p.insert(position,id,title,time);
      }
      else if(choice == 3){
         p.sort();
      }
      else if(choice == 4){
         int dlt_pos;
         cout<<"Enter the position at which you want to delete the element:";
         cin>>dlt_pos;
         p.dlt(dlt_pos);
      }
      else if(choice == 5){
         p.play();
      }
      else{
         cout<<"The choice was is not valid"<<endl;
      }


      cout<<"Enter the your choice:"<<endl<<"1.append"<<endl<<"2.insert"<<endl<<"3.sort"<<endl<<"4.delete"<<endl<<"5.play"<<endl<<"6.exit"<<endl;
      cin>>choice;
   }
    return 0;
}