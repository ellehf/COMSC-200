//
//  main.cpp
//  COMSC 200- Lab 2A Overload Constr
//
//  Created by Elle Hoarau on 2/11/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "Car.h"

int main()
{
    Car Nissan(2014, "Altima"); //Create car object and pass values
    
    //Call accelerate function 5 times
    for(int i=0; i<5; i++)
    {
        Nissan.accelerate();
    }
    
    //Call brake function 5 times
    for(int i=0; i<5; i++)
    {
        Nissan.brake();
    }
    
    return 0;
}
