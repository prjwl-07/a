#include<bits/stdc++.h>
using namespace std;

class products{
    public:
    int id;
    string name;
    int price;
    int rating ;

    void input(){
        cout<<"enter the name of the product:";
        cin>>name;
        cout<<endl<<"enter the id:";
        cin>>id;
        cout<<endl<<"enter the price:";
        cin>>price;
        cout<<endl<<"enter the rating:";
        cin>>rating;
    }
    void bubble(products s[],int n){
        for(int i=n-1;i>0;i++){
            for(int j=0;j<i;j++){
                if(s[j].id < s[j+1].id){
                    swap(s[j],s[j+1]);
                }
            }
        }
        cout<<"sorting by id:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<" "<<"id:"<<s[i].id<<","<<"name:"<<s[i].name<<","<<endl;
        }
    }
    void selection(products s[],int n){
        int maxIndex = 0;
        for(int i=0;i<n;i++){
            maxIndex = i;
            for(int j=i;j<n;j++){
                if(s[maxIndex].price > s[j].price){
                    maxIndex = j;
                }
            }
            swap(s[i],s[maxIndex]);
        }
        cout<<"sorting by price:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<" "<<"price:"<<s[i].price<<","<<"name:"<<s[i].name<<","<<endl;
        }
    }
    void insertion(products s[],int n){
        for(int i=0;i<n;i++){
            int j = i;
            while(j>0 && s[j].rating < s[j-1].rating){
                swap(s[j],s[j-1]);
                j--;
            }
        }
        cout<<"sorting by rating:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<" "<<"rating:"<<s[i].rating<<","<<"name:"<<s[i].name<<","<<endl;
        }
    }
};

int main() {
    int n;
    cout<<"enter the number of products:";
    cin>>n;
    products p[n];
    for(int i=0;i<n;i++){
        p[i].input();
    }

    int choice;
    cout<<"enter 1 for id 2 for price and 3 for rating:";
    cin>>choice;
    products obj;
    if(choice == 1){
        obj.bubble(p,n);
    }
    else if(choice == 2){
        obj.selection(p,n);
    }
    else if(choice == 3){
        obj.insertion(p,n);
    }
    else {
        cout<<"you have entered wrong option:"<<endl;
    }
    return 0;
}