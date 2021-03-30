//
//  BasicShape.h
//  COMSC 200 - AS05 Abstract Base Class
//
//  Created by Elle Hoarau on 3/9/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef BasicShape_h
#define BasicShape_h

//Abstract base class
class BasicShape
{
protected:
    double area; //Hold shape's area
public:
    double getArea() const {return area;} //Return shape's area
    
    virtual void calcArea() = 0; //Pure virtual function
};

#endif /* BasicShape_h */
