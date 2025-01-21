#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

int getPrecedence(char oper) {
    if(oper == '+' || oper == '-') return 1;
    if(oper == '*' || oper == '/') return 2;
    return 0;
}

void convertToPostfix(string expression) {
    stack<char> operators;
    for(char ch : expression) {
        if(isdigit(ch)) {
            cout << ch;
        }
        else if(ch == '(') {
            operators.push(ch);
        }
        else if(ch == ')') {
            while(!operators.empty() && operators.top() != '(') {
                cout << operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else {
            while(!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(ch)) {
                cout << operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while(!operators.empty()) {
        cout << operators.top();
        operators.pop();
    }
    cout << endl;
}

int evaluatePostfixExpression(string expr) {
    stack<int> operands;
    for(char ch : expr) {
        if(isdigit(ch)) {
            operands.push(ch - '0');
        }
        else {
            int b = operands.top(); operands.pop();
            int a = operands.top(); operands.pop();
            if(ch == '+') operands.push(a + b);
            else if(ch == '-') operands.push(a - b);
            else if(ch == '*') operands.push(a * b);
            else if(ch == '/') operands.push(a / b);
        }
    }
    return operands.top();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: ";
    convertToPostfix(infix);

    string postfix;
    cout << "Enter postfix expression for evaluation: ";
    cin >> postfix;

    cout << "Result of postfix evaluation: " << evaluatePostfixExpression(postfix) << endl;

    return 0;
}

