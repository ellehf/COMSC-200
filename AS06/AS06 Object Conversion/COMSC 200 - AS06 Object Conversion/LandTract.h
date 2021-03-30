//
//  LandTrac.h
//  COMSC 200 - AS06 Object Conversion
//
//  Created by Elle Hoarau on 3/16/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef LandTrac_h
#define LandTrac_h
#include "FeetInches.h"
  
class LandTract
{
private:
    FeetInches width, length;

public:
    //Accessors
    FeetInches getWidth() { return width; }
    FeetInches getLength() { return length; }
    double getArea();
    
    //Mutators
    void setWidth(FeetInches w) {width = w;}
    void setLength(FeetInches l) {length = l;}
};

double LandTract :: getArea()
{
    //Object conversion to double
    double w = width;
    double l = length;
    
    return (w*l); //Return area in square feet
}

#endif /* LandTrac_h */
