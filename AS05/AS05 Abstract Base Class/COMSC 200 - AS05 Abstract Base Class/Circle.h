//
//  Circle.h
//  COMSC 200 - AS05 Abstract Base Class
//
//  Created by Elle Hoarau on 3/9/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Circle_h
#define Circle_h

#include "BasicShape.h"

//Circle is a basic shape
class Circle : public BasicShape
{
private:
    long centerX, centerY; //Hold coordinates of circle's center
    double radius; //Hold circle's radius
public:
    Circle() {centerX = 0; centerY = 0; radius = 0;} //Default constructor
    Circle(long x, long y, double r); //Constructor to accept values
    
    long getCenterX() const {return centerX;} //Return x coordinate of center
    long getCenterY() const {return centerY;} //Return y coordinate of center
    
    virtual void calcArea(); //Virtual function to calculate area of shape
};

Circle :: Circle(long x, long y, double r)
{
    centerX = x;
    centerY = y;
    radius = r;
    
    calcArea();
}

void Circle :: calcArea()
{
    area = 3.14159 * radius * radius;
}

#endif /* Circle_h */
