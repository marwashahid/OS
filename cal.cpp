#include <iostream>
#include <stack>
#include<math.h>
#include <algorithm>
#include<unistd.h>
#include <cstdlib>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    else {
        return false;
    }
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string InfixToPrefix(stack<int> s, string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= '0' && infix[i] <= '9')) {
            prefix += infix[i];
        }
        else if (infix[i] == '(') {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((s.top() != '(') && (!s.empty())) {
                prefix += s.top();
                s.pop();
            }

            if (s.top() == '(') {
                s.pop();
            }
        }
        else if (isOperator(infix[i])) {
            if (s.empty()) {
                s.push(infix[i]);
            }
            else {
                if (precedence(infix[i]) > precedence(s.top())) {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.top()))
                    && (infix[i] == '^')) {
                    while ((precedence(infix[i]) == precedence(s.top()))
                        && (infix[i] == '^')) {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if (precedence(infix[i]) == precedence(s.top())) {
                    s.push(infix[i]);
                }
                else {
                    while ((!s.empty()) && (precedence(infix[i]) < precedence(s.top()))) {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}
bool isOperand(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    else {
        return false;
    }
}
int PrefixToPostfix(string prefix) {
    stack <int> s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
            int op = prefix[i] - '0';
            //string op(1, prefix[i]);
            s.push(op);
        }
        else {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();

            if (prefix[i] == '+')
            s.push(op1 + op2);
            else if (prefix[i] == '-')
                s.push(op1 - op2);
            else if (prefix[i] == '*')
                s.push(op1 * op2);
            else if (prefix[i] == '/')
            {   
                if (op2 != 0)
                    s.push(op1 / op2);
                else
                    std::cout << "MATH ERROR: DIVISION BY ZERO";
                    std::cin.get();
                    std::cin.get();

            }
            if (prefix[i] == '^')
                s.push(pow(op1,op2));

        }
    }
    return s.top();
}

int main()
{

    string infix, prefix;
    
     cout << "Enter a Infix Expression :" << endl;
     cin >> infix;
     stack<int> stack;
     
     cout << "INFIX EXPRESSION: " << infix << endl;
     prefix = InfixToPrefix(stack, infix);
     cout << endl
          << "PREFIX EXPRESSION: " << prefix;

    
    std::cout << "\nANS:" << PrefixToPostfix(prefix);
    
    std::cin.get();
    std::cin.get();
    return 0;
}
