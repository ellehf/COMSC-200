//
//  Rectangle.h
//  COMSC 200 - AS05 Abstract Base Class
//
//  Created by Elle Hoarau on 3/9/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h

#include "BasicShape.h"

class Rectangle : public BasicShape
{
private:
    long width, length; //Hold rectangle's width and length
public:
    Rectangle() {width = 0; length = 0;} //Default constructor
    Rectangle(long w, long l); //Constructor to accept values
    
    long getWidth() const {return width;} //Return rectangle's width
    long getLength() const {return length;} //Return rectangle's length
    
    virtual void calcArea(); //Virtual function to calculate area of shape
};

Rectangle :: Rectangle(long w, long l)
{
    width = w;
    length = l;
    
    calcArea();
}

void Rectangle :: calcArea() 
{
    area = length * width;
}

#endif /* Rectangle_h */
