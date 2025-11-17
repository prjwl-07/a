#include<iostream>
using namespace std;

class Order{
    public:
    int id;
    Order* next;
    Order* prev;
    Order(int id){
        this->id = id;
        next = nullptr;
        prev = nullptr;
    }
};
class PizzaHut{
    public:
    Order* front;
    Order* rear;
    PizzaHut(){
        front = nullptr;
        rear = nullptr;
    }
    void addFront(int id){
        Order* o = new Order(id);

        if(front == NULL){
            front = rear = o;
        }else{
            front->prev = o;
            o->next = front;
            front = o;
        }
        cout<<"Order is added at front"<<endl;
    }
    void addRear(int id){
        Order* o = new Order(id);

        if(rear == NULL){
            front = rear = o;
        }else{
            rear->next = o;
            o->prev = rear;
            rear = o;
        }
        cout<<"Order is added at end"<<endl;
    }
    void processFront(){
        if(front == NULL){
            cout<<"No order to process"<<endl;
            return;
        }
        Order* temp = front;
        front = front->next;

        if(front == NULL){
            rear = nullptr;
        }else{
            front->prev = nullptr;
            temp->next = nullptr;
        }
        cout<<"Order processed"<<endl;
    }
    void processRear(){
        if(rear == NULL){
            cout<<"No order to process"<<endl;
            return;
        }
        Order* temp = rear;
        rear = rear->prev;

        if(rear == NULL){
            front = nullptr;
        }else{
            rear->next = nullptr;
            temp->prev = nullptr;
        }
        cout<<"Order processed"<<endl;
    }
    void displayFrontOrder(){
        if(front == NULL){
            cout<<"No order to process"<<endl;
            return;
        }
        else{
            cout<<"Order : "<<front->id<<" is under process"<<endl;
        }
    }
};

int main() {
    int choice;
    PizzaHut P;
    int id;

    bool status = true;
    while(status){
    
    cout<<"\n1)add urgert order\n2)add order(will take time)\n3)process front\n4)process rear\n5)display processing order\n6)exit\n"<<"Enter the choice :";
    cin>>choice;

        switch (choice)
    {
    case 1 :
        cout<<"Enter id : ";
        cin>>id;
        P.addFront(id);
    break;

    case 2 :
        cout<<"Enter id : ";
        cin>>id;
        P.addRear(id);
    break;

    case 3 :
        P.processFront();
    break;

    case 4 :
        P.processRear();
    break;

    case 5 :
        P.displayFrontOrder();
    break;

    case 6 :
        status = false;
    break;
    
    default:
    cout<<"Wrong choice"<<endl;
        break;
    }
    }
    return 0;
}
