//
//  main.cpp
//  COMSC 200 - AS03
//
//  Created by Elle Hoarau on 2/20/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "Frac.h"

int main()
{
    Frac x(3,4);
    Frac y(1,2);
    cout << "\nCreated Frac x(3,4) as " << x;
    cout << "\nCreated Frac y(1,2) as " << y;
    
    Frac z(x);
    cout << "\nCopy constructed z as x: " << z<<endl;
    
    Frac a = x;
    cout << "Assigned x to a: " << a <<endl;
    
    Frac h;
    cout << "\nSetting h numerator to 3..." <<endl;
    h.setNum(3);
    cout << "Setting h numerator to 5..." <<endl;
    h.setDen(5);
    cout << "Fraction numerator is: " << h.getNum() <<endl;
    cout << "Fraction denominator is: " << h.getDen() <<endl;
    
    // Turn on this one when you completed the definition of string constructor
    Frac s("6/7"); // passing a Frac number as a string.
    cout << "\nString constructed: s: " << s <<endl;
    
    
    Frac v = x + y;
    cout << "\nx + y is: " << v<<endl;
    
    Frac t = x - y;
    cout << "\nx - y is: " << t<<endl;
    
    Frac w = x * y;
    cout << "\nx * y is: " << w<<endl;
    
    Frac q = x / y;
    cout<< "\nx / y is: " << q<<endl;
    
    cout<< "\nTesting if " << x << " is equal to " << y<<endl;
    if(x == y)
        cout<< "True!" <<endl;
    else
    cout<< "False!" <<endl;
    
    cout<< "\nTesting if " << x << " is not equal to " << y<<endl;
    if(x != y)
        cout<< "True!" <<endl;
    else
        cout<< "False!" <<endl;
        
    cout<< "\nTesting if " << x << " is less than " << y<<endl;
    if(x < y)
        cout<< "True!" <<endl;
    else
        cout<< "False!" <<endl;
    
    cout<< "\nTesting if " << x << " is greater than " << y<<endl;
    if(x > y)
        cout<< "True!" <<endl;
    else
        cout<< "False!" <<endl;
    
    cout<< "\nTesting if " << x << " is less than or equal to " << y <<endl;
    if(x <= y)
        cout<< "True!" <<endl;
    else
        cout<< "False!" <<endl;
    
    cout<< "\nTesting if " << x << " is greater than or equal to " << y<<endl;
    if(x >= y)
        cout<< "True!" <<endl;
    else
        cout<< "False!" <<endl;
    
    cout<< "\nTesting pre and postfix increment/decrement:"<<endl;
    Frac c(3,2);
    cout << c << " " << c++ << " " << c-- << " " << --c << " " << ++c <<endl;
    
    Frac f1(3,5);
    Frac f2(9,2);
    cout << "\nFrac f1: " << f1 << "\nFrac f2: " << f2
    << "\nFirst fraction as Integer: " << int(f1)
    << "\nSecond fraction as Double: " << double(f2) <<endl;
    
    Frac i;
    cin >> i;
    cout<< "Fraction entered is: " << i <<endl;
    
    cout << "\nPlease observe the outputs of identical commands\n"
            << "executed in one statement v. separated statements. \n";
    
    Frac f(5,6);
    cout << f << " "     // start
            << --f << " "
            << f << " "
            << ++f << " "
            << --f << " "
            << ++f << endl; // end of one statement
             
    cout << f << " " ;
    cout << --f << " " ;
    cout << f << " " ;
    cout << ++f << " " ;
    cout << --f << " " ;
    cout << ++f;
    cout <<endl;
    
    return 0;
}
