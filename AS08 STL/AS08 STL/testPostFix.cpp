//
//  main.cpp
//  AS08 STL
//
//  Created by Elle Hoarau on 4/7/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "postfixCalculator.h"

int main()
{
    string user;

    cout << "Enter a postfix expression: "; //Take user input for postfix calculator
    cin >> user;
    
    cout << postFixCalc(user) <<endl;
    
    return 0;
}
