//
//  main.cpp
//  AS11 Infix to Postfix Calc
//
//  Created by Elle Hoarau on 5/5/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;

int precedence(char c) //Function to return precendence value
{
    if(c == '^') // '^' takes highest precedence
        return 3;
    else if(c == '*' || c == '/') // '*' and '/' have equal precedence
        return 2;
    else if(c == '+' || c == '-') //'+' and '-' have equal precedence
        return 1;
    else
        return -1; // If other char is sent, return -1
}

void displayI2P(string s, stack<char> st); //Pre-declaration

string infix2postfix(string u) //Function to convert string infix to string postfix
{
    stack<char> OPStack; //STL stack declaration
    string postfixQ; //String to act as queue
    
    for (int i=0; i<u.length(); i++) //Loop through each token of string
    {
        if(isdigit(u[i])) //If token is a number
        {
            postfixQ += u[i]; //Push onto output queue
            
            displayI2P(postfixQ, OPStack);
        }
        else if(u[i] == '(') //If token is a left parentheses
        {
            OPStack.push('('); //Push onto operator stack
            
            displayI2P(postfixQ, OPStack);
        }
        else if(u[i] == ')') //If token is a right parentheses
        {
            while(!OPStack.empty() && OPStack.top() != '(') //While operator at top of stack is not left parentheses
            {
                char o = OPStack.top(); //Pop operator from op stack to output queue
                postfixQ += o;
                OPStack.pop();
                
                displayI2P(postfixQ, OPStack);
            }
            
            OPStack.pop(); // Pop and discard top of op stack when left parentheses is hit
        }
        else //If token is an operator
        {
            //While op at top of stack has greater precedence or has equal precedence and is left associative (i.e. not '^')
            while(!OPStack.empty() && (precedence(u[i]) < precedence(OPStack.top()) || (precedence(u[i]) == precedence(OPStack.top()) && precedence(u[i]) < 3)))
                {
                    char o = OPStack.top(); //Pop operators from op stack to output queue
                    postfixQ += o;
                    OPStack.pop();
                    
                    displayI2P(postfixQ, OPStack);
                }
            
            OPStack.push(u[i]); //Otherwise, push onto operator stack
        }
    }
    
    //If no more tokens to read
    while(!OPStack.empty()) //While operators are still on the stack
    {
        char o = OPStack.top(); //Pop operators onto output queue
        postfixQ += o;
        OPStack.pop();
        
        displayI2P(postfixQ, OPStack);
    }
    
    return postfixQ;
}

//Function to display op stack and postfix queue during conversion
void displayI2P(string s, stack<char> st)
{
    cout << "OP Stack: ";
    while(!st.empty()) // Display stack values
    {
        cout << st.top();
        st.pop();
    }
    
    cout << right << setw(25) << " ";
    
    cout << "Output Queue: " << s <<endl;
    
}

void display(queue<char> q, stack<int> s); //pre-declaration

int postFixCalc(string u) //Function to evaluate using postfix notation
{
    stack<int> S; //STL stack declaration
    queue<char> Q; //STL queue declaration
    
    int x,y; //To hold values under operation

    for(int i=0; i<u.length(); i++) //Loop to push user input on queue
        Q.push(u[i]);

    for (int i=0; i<u.length(); i++) //Loop to push queue on stack
    {
        if (isdigit(u[i])) //If value is number, push on stack
        {
            S.push(u[i] - '0'); //Push to stack, char converted to int
            Q.pop();

            display(Q,S);
        }
        
        else //If value is an operation
        {
            x = S.top(); //Pop last two values on stack and evaluate
            S.pop();

            y = S.top();
            S.pop();
            
            Q.pop(); //Pop operation from queue
            
            cout << "(" << y << u[i] << x << ")"; //Display operation
            display(Q,S);

            switch (u[i]) //Evaluate operation
            {
                case '^':
                    S.push(pow(y,x));
                    break;
                    
                case '+':
                    S.push(y+x);
                    break;
                    
                case '-':
                    S.push(y-x);
                    break;
                    
                case '*':
                    S.push(y*x);
                    break;
                    
                case '/':
                    S.push(y/x);
                    break;
            }
            
            display(Q,S);

        }

    }

    return S.top(); //Return calculated value
}

void display(queue<char> q, stack<int> s) //Function to display queue and stack progress
{
    while(!s.empty()) // Display stack values
    {
        cout << s.top();
        s.pop();
    }

    cout << right << setw(25) << " ";

    while(!q.empty()) //Display queue values
    {
        cout << q.front();
        q.pop();
    }

    cout << endl;
}


int main()
{
    string user;

    cout << "Enter an infix expression: "; //Take user input for postfix calculator
    cin >> user;
        
    string infix = infix2postfix(user);
        
    cout << "\nInfix to Postfix conversion: " << infix <<endl;
    
    cout << "Postfix Calculation: \n" << postFixCalc(infix) <<endl;
    
    return 0;
    
}

