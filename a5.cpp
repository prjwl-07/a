#include<iostream>
using namespace std;

//visit a specific web page
//navigate forward and backward
//add new web pages 
//deleting pages from existing list
class Browser{
    class page{
        public:
        string id;
        string time;
        page* next;
        page* prev;
        page(string id,string time){
            this->id = id;
            this->time = time;
            next = nullptr;
            prev = nullptr;
        }
    };

    
    page* head;
    page* visited;
    public:
    Browser(){
        head = nullptr;
        visited = nullptr;
    }
    
    void add(string id,string time){
        page* newPage = new page(id,time);

        if(head == NULL){
            head = newPage;
            return;
        }
        page* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newPage;
        newPage->prev = temp;
    }
    void dlt(string id){
        // if the head is null
        if(head == NULL)return;
        //if the if it has only one element 
        if(head->id == id){
            page* temp1 = head;
            if(head->next){
                head = head->next;
                head->prev = nullptr;
            }
            else{
                head = nullptr;
            }
            delete temp1;
            cout<<endl<<"The page deleted"<<endl;
            return;
        }
        //other than that
        page* temp = head;
        while( temp != NULL ){
            if(temp->id == id){
                if(temp->prev)temp->prev->next = temp->next;
                if(temp->next)temp->next->prev = temp->prev;
                delete temp;
                cout<<endl<<"The page deleted"<<endl;
                return ;
            }
            temp = temp->next;
        }
        
        cout<<endl<<"The page with this id not found"<<endl;
    }

    void visit(string id){
        page* temp = head;
        while(temp != NULL && temp->id != id){
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<endl<<"The page with given id not found"<<endl;
            return;
        }

        visited = temp;
        cout<<endl<<"The page found:"<<endl<<"Page id: "<<temp->id<<endl<<"Opened at: "<<temp->time<<endl;
    }

    void forward() {
        if (visited == NULL) {
            cout << "\nNo page is currently visited.\n";
            return;
        }

        if (visited->next == NULL) {
            cout << "\nNo forward navigation possible.\n";
            return;
        }

        // Move one page ahead
        visited = visited->next;

        cout << "\n--> Page_id : " << visited->id
            << " opened at : " << visited->time << " minutes\n";

        // Show remaining pages
        page* temp = visited->next;
        while (temp != NULL) {
            cout << "    Page_id : " << temp->id
                << " opened at : " << temp->time << " minutes\n";
            temp = temp->next;
        }
    }


    void backward() {
        if (visited == NULL) {
            cout << "\nNo page is currently visited.\n";
            return;
        }

        if (visited->prev == NULL) {
            cout << "\nNo backward navigation possible.\n";
            return;
        }

        // Move one page back
        visited = visited->prev;

        cout << "\n--> Page_id : " << visited->id
            << " opened at : " << visited->time << " minutes\n";

        // Show remaining pages
        page* temp = visited->prev;
        while (temp != NULL) {
            cout << "    Page_id : " << temp->id
                << " opened at : " << temp->time << " minutes\n";
            temp = temp->prev;
        }
    }

};

int main() {
    int choice;
    Browser b;

    cout<<"1.add page"<<endl<<"2.delete page"<<endl<<"3.visit page"<<endl<<"4.navigate"<<endl<<"5.exit"<<"Choice :";
    cin>>choice;
    while(choice != 5){
        
        if(choice == 1){
            int n ;
            cout<<"enter the number of pages to add:";
            cin>>n;
            
            for(int i=0;i<n;i++){

                string id;
                string time;
                cout<<"enter Id:";
                cin>>id;
                cout<<"enter Time:";
                cin>>time;
                b.add(id,time);
                
            }
            cout<<endl<<"successfully Added"<<endl;
        }
        else if(choice == 2){

            string id;
            cout<<"enter Id:";
            cin>>id;
            b.dlt(id);
        }
        else if(choice == 3){
            string id;
            cout<<"enter Id:";
            cin>>id;
            b.visit(id);
        }
        else if(choice == 4){
            int secChoice ;
            cout<<"enter choice:"<<endl<<"1.forward navigation"<<endl<<"2.backward navigation"<<endl;
            cin>>secChoice;
            if(secChoice == 1){
                b.forward();
            }
            else if(secChoice == 2){
                b.backward();
            }
            else {
                cout<<"Enter valid choice"<<endl;
            }
        }
        else{
            cout<<endl<<"Thank you"<<endl;
        }

        cout<<endl<<"1.add page"<<endl<<"2.delete page"<<endl<<"3.visit page"<<endl<<"4.navigate"<<endl<<"Enter choice :";
        cin>>choice;
    }
    return 0;
}