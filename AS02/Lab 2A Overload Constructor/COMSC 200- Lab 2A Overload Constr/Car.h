//
//  Car.h
//  COMSC 200- Lab 2A Overload Constr
//
//  Created by Elle Hoarau on 2/11/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Car_h
#define Car_h

#include <iostream>
using namespace std;

class Car
{
private:
    //Member variables
    int yearModel;
    string make;
    int speed;
public:
    Car(int ym, string m); //Constructor with year and make passed
    
    //Accessor and mutators
    int getYearModel();
    string getMake();
    int getSpeed();
    
    //Functions to accelerate and brake car
    void accelerate();
    void brake();
};

//Constructor to intialize member variables
Car :: Car(int ym, string m)
{
    yearModel = ym;
    make = m;
    speed = 0;
}

int Car :: getYearModel()
{
    return yearModel;
}

string Car :: getMake()
{
    return make;
}

int Car :: getSpeed()
{
    return speed;
}

//Function that increments speed by 5
void Car :: accelerate()
{
    cout<< "Accelerating..." <<endl;
    speed += 5;
    cout<< "Current speed: " << speed <<endl;
}

//Function that decrements speed by 5
void Car :: brake()
{
    cout<< "Braking..." <<endl;
    speed -= 5;
    cout<< "Current speed: " << speed <<endl;
}

#endif /* Car_h */
