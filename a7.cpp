#include<iostream>
using namespace std;

#define size 100

class stack{
    char arr[size];
    int pointer;

public:
    stack(){
        pointer = -1;
    }
    bool isempty(){
        return (pointer == -1);
    }

    bool isfull(){
        return (pointer == size-1);
    }

    void push(char val){
        if(isfull()){
            cout<<"The stack overflow occured try little small data"<<endl;
            return ;
        }
        arr[++pointer] = val;
    }

    char pop(){
        if(isempty()){
            cout<<"The stack is already empty"<<endl;
            return '\0';
        }
        return arr[pointer--];
    }

    char top(){
        if(isempty()){
            cout<<"The stack is already empty"<<endl;
        }
        return arr[pointer];
    }

};

bool checkparenthesis(string eq){
    stack s;
    for(int i=0;i<eq.length();i++){
        char c = eq[i];
        if(c == '(' || c == '{' || c == '['){
            s.push(c);
        }
        
        else if(c == ')' || c == '}' || c == ']'){
            if(s.isempty())return false;

            char tope = s.pop();
            if(c == ')' && tope != '(' ||
               c == '}' && tope != '{' ||
               c == ']' && tope != '[' ){
                return false;
               }
        }
    }

    return s.isempty();
}

int main() {
    
    string s;
    cout<<"enter the string to check the parenthesis:";
    getline(cin,s);
    
    if(checkparenthesis(s))cout<<"The string is well parenthesized"<<endl;
    else cout<<"The string is not well parenthesized"<<endl;
    return 0;
}