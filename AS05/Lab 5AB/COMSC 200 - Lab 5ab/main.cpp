//
//  main.cpp
//  COMSC 200 - Lab 5ab
//
//  Created by Elle Hoarau on 3/9/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include <iostream>
using namespace std;

class Two
{
public:
    Two(int b) {b=0;}
};

class One
{
public:
    One(int a) {a=0;}
};

class Three : public Two , public One
{
protected:
    int x;
public:
    Three(int a, int b, int c) : Two(b), One(c)
    { x = a; }
    ~Three();
};

int main()
{
  
    
    return 0;
}
