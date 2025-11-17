#include<iostream>
using namespace std;

class grossary{
    private:
    string name;
    int price;

    public:
    grossary(){}

    grossary(string name ,int price){
        this->name = name;
        this->price = price;
    }

    void seqSearch(grossary arr[],int n,string item){
        for(int i=0;i<n;i++){
            if(arr[i].name == item){
                cout<<"item found\n"<<"Price of "<<item<<" is "<<arr[i].price<<endl;
                return;
            }
        }
        cout<<"Not found"<<endl;
    }

    void sentiSearch(grossary arr[],int n,string item){
        string last = arr[n-1].name;
        arr[n-1].name = item;
        
        int i=0;
        while(arr[i].name != item){
            i++;
        }
        if(i == n-1){
            if(last == item){
                cout<<"item found\n"<<"Price of "<<item<<" is "<<arr[i].price<<endl;
                return;
            }
            else{
                cout<<"Not found"<<endl;
            }
        }else{
            cout<<"item found\n"<<"Price of "<<item<<" is "<<arr[i].price<<endl;
            return;
        }
    }
};

int main() {
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    grossary arr[n];
    for(int i=0;i<n;i++){
        string name;
        int price;
        cout<<i+1<<endl;
        cout<<"enter name: ";
        cin>>name;
        cout<<"enter price: ";
        cin>>price;
        arr[i] = grossary(name,price);
    }

    int status = 1;
    while(status){
        string name;
        cout<<"\n Now enter name to search:";
        cin>>name;
        grossary g;
        int choice;
        cout<<"enter 1 for sequential and 2 for sentinal search"<<endl;
        cin>>choice;
        if(choice == 1)g.seqSearch(arr,n,name);
        else if (choice == 2)g.sentiSearch(arr,n,name);
        
        cout<<"enter 1 to continue and 0 to exit"<<endl;
        cin>>status;
    }

    return 0;
}