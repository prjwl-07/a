#include<iostream>
using namespace std;

// swap
void swap(float &a,float &b){
    int temp=a;
    a=b;
    b=temp;

}

// print array
void show(int arr[],string p[],int n){
    // cout<<"these are the elements in the array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" name is "<<p[i]<<endl;
    }
}
void show(float arr[],string p[],int n){
    // cout<<"these are the elements in the array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" name is "<<p[i]<<endl;
    }
}

// bubble sort
void bubble_sort(int pi[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
        if(pi[j]>pi[j+1]){
            swap(pi[j],pi[j+1]);
         }
        }
    }
}

// selection sort
void selection_sort(float price[],int n){
    for(int i=0;i<n;i++){
    int minindex=i;
    for(int j=i;j<n;j++){
        if(price[minindex]>price[j])minindex=j;
    }
    swap(price[i],price[minindex]);

   }
}

// insertion sort 
void insertion_sort(int qr[],int n){
    for(int i=0;i<n;i++){
        int curr=qr[i];
        int prev=i-1;
        while(prev>=0&&qr[prev]<curr){
            swap(qr[prev],qr[prev+1]);
            prev--;
        }
    qr[prev+1]=curr;
    }
    
}


int main(){
    int pi[10],n,qr[10];;
    string pn[10];
    string man[10];
    float price[10];
    cout<<"enter the no. of the list(below 10):";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter product name:";
        cin>>pn[i];
        cout<<"enter product id:";
        cin>>pi[i];
        cout<<"enter manufacturer:";
        cin>>man[i];
        cout<<"enter price:";
        cin>>price[i];
        cout<<"enter quality rating (out of 5):";
        cin>>qr[i];
        cout<<endl;
       
    }

    cout<<"sorted arrays:"<<endl;
    bubble_sort(pi,n);
    cout<<"these are product id's in ascending order:"<<endl;
    show(pi,pn,n);


    selection_sort(price,n);
    cout<<"these are product prices in ascending order:"<<endl;
    show(price,pn,n);

    insertion_sort(qr,n);
    cout<<"these are ratings in descending order:"<<endl;
    show(qr,pn,n); 

    return 0;
}
