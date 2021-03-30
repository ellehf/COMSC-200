//
//  Employee.h
//  AS07 Exception
//
//  Created by Elle Hoarau on 3/23/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Employee_h
#define Employee_h
#include "HireDate.h"

#include <iostream>
using namespace std;

//Employee class, derived from HireDate class
class Employee : public HireDate
{
protected:
    string name; //Hold employee's name
    int number; //Hold employee's number
    HireDate date; //Hold's employee's hire date
public:
    class InvalidEmployeeNumber
    {
    private:
        int num;
    public:
        InvalidEmployeeNumber(int n) {num=n;}
        
        int getNum() const {return num;}
    };
    
    //Default constructor
    Employee() : HireDate() { name = ""; number = 0;}
    //Constructor with data passed
    Employee(string n, int num, HireDate date) : HireDate(date)
    {
        name = n;
        
        if(num > 0 && num < 9999)
            number = num;
        else
            throw InvalidEmployeeNumber(num);
        
        
    }
    
    //Mutators and accessors
    void setName(string n) {name = n;}
    string getName() {return name;}
    
    void setNumber(int num)
    {
        if(num > 0 && num < 9999)
            number = num;
        else
            throw InvalidEmployeeNumber(num);
        
    }
    int getNumber() {return number;}
    
    void setHireDate(HireDate d)
    {
        date.setDay(d.getDay());
        date.setMonth(d.getMonth());
        date.setYear(d.getYear());
    }
    
};

#endif /* Employee_h */
