//
//  ProductionWorker.h
//  AS07 Exception
//
//  Created by Elle Hoarau on 3/23/20.
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
    class InvalidShift
    {
    private:
        int sft;
    public:
        InvalidShift(int s) {sft = s;}
            
        int getShift() const {return sft;}
    };
    
    class InvalidPayRate
    {
    private:
        int hr;
    public:
        InvalidPayRate(int h) {hr = h;}
            
        int getPay() const {return hr;}
    };
    
    //Default constructor
    ProductionWorker() : Employee() {sft = 1; hourlyRate = 0.0;}
    
    //Constructor with data passed
    ProductionWorker(string n, int num, HireDate date, int s, double hr) : Employee(n , num, date)
    {
        if(s==day || s==night)
            sft = s;
        else
            throw InvalidShift(s);
        
        if(hr > 0)
            hourlyRate= hr;
        else
            throw InvalidPayRate(hr);
        
    }
    
    //Mutators and accessors
    void setShift(int s)
    {
        if(s==day)
            sft = day;
        else if(s==night)
            sft = night;
        else
            throw InvalidShift(s);
    }
    
    int getShift() {return sft;}
    
    void setHourlyRate(double hr)
    {
        if(hr > 0)
            hourlyRate = hr;
        else
            throw InvalidPayRate(hr);
        
    }
    double getHourlyRate() {return hourlyRate;}
};


#endif /* ProductionWorker_h */
