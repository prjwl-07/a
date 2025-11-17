#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
    char arr[SIZE];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SIZE - 1;
    }

    void push(char c) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            return '\0'; // return null char if empty
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

// Function to check if parentheses are balanced
bool checkParenthesis(string expr) {
    Stack s;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // For closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;

            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }

    // If stack is empty → balanced
    return s.isEmpty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (checkParenthesis(expr))
        cout << "Parentheses are balanced!" << endl;
    else
        cout << "Parentheses are NOT balanced!" << endl;

    return 0;
}
