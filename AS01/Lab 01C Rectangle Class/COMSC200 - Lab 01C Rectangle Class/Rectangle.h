//
//  Rectangle.h
//  COMSC200 - Lab 01C Rectangle Class
//
//  Created by Elle Hoarau on 2/4/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h

#include <iostream>
#include <memory>
using namespace std;

class Rectangle
{
   private:
      double width;
      double length;
   public:
      void setWidth(double);
      void setLength(double);
      double getWidth() const;
      double getLength() const;
      double getArea() const;
};

//Assign value to the width member
void Rectangle:: setWidth(double w)
{
   width= w;
}

//Assign value to the length member
void Rectangle:: setLength(double len)
{
   length= len;
}

//Return value in the width member
double Rectangle:: getWidth() const
{
   return width;
}

//Return value in the length member
double Rectangle:: getLength() const
{
   return length;
}

//Returns area
double Rectangle:: getArea() const
{
   return width*length;
}

#endif /* Rectangle_h */
