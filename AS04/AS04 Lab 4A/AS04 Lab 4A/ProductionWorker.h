//
//  ProductionWorker.h
//  AS04 Lab 4A
//
//  Created by Elle Hoarau on 2/28/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef ProductionWorker_h
#define ProductionWorker_h

#include "Employee.h"

enum Shift{day = 1, night =2};

//ProductionWorker is an Employee
class ProductionWorker : public Employee
{
protected:
    int sft; //Holds if worker's shift was day or night
    double hourlyRate; //Holds worker's hourly rate
public:
    //Default constructor
    ProductionWorker() : Employee() {sft = 1; hourlyRate = 0.0;}
    //Constructor with data passed
    ProductionWorker(string n, int num, HireDate date, int s, double hr) : Employee(n , num, date) {sft = s; hourlyRate= hr;}
    
    //Mutators and accessors
    void setShift(int s)
    {
        if(s==day)
            sft = day;
        else
            sft = night;
    }
    int getShift() {return sft;}
    
    void setHourlyRate(double hr) {hourlyRate = hr;}
    double getHourlyRate() {return hourlyRate;}
};



#endif /* ProductionWorker_h */
