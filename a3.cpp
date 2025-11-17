#include<iostream>
using namespace std;

class phonebook{
    private:
    int long telephone;
    string client_name;

    public:
    phonebook(){
        telephone = 0;
        client_name = "";

    }

    void insert(phonebook arr[],int n,string name,int long number){
        int index = (int)name[0]%n;
        while(arr[index].client_name != ""){
            index = (index+1)%n; 
        }
        arr[index].client_name = name;
        arr[index].telephone = number;
    }

    void displayAll(phonebook arr[],int n){
        cout<<"The telephone book data:"<<endl;
        cout<<"sr.no."<<"\t\t"<<"client"<<"\t\t"<<"number"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<"\t\t"<<arr[i].client_name<<"\t\t"<<arr[i].telephone<<endl;
        }
    }
};

int main() {
    int n;
    cout<<"enter the number of entries:";
    cin>>n;
    phonebook obj;
    phonebook arr[n];

    string name;
    int long number;

    for(int i=0;i<n;i++){
        cout<<"enter the name:";
        cin>>name;
        cout<<"enter the number:";
        cin>>number;
        obj.insert(arr,n,name,number);
    }

    obj.displayAll(arr,n);
    
    return 0;
}