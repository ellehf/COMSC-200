//
//  postfixCalculator.h
//  AS08 STL
//
//  Created by Elle Hoarau on 4/8/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef postfixCalculator_h
#define postfixCalculator_h

#include <queue>
#include <stack>
#include <iomanip>
#include <iostream>
using namespace std;

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

#endif /* postfixCalculator_h */
