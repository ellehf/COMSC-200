//
//  HireDate.h
//  AS04 Lab 4A
//
//  Created by Elle Hoarau on 2/28/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef HireDate_h
#define HireDate_h

//Class to hold hire date in day month year format
class HireDate
{
protected:
    int day; //Holds hire date day
    int month; //Holds hire date mont
    int year; //Holds hire date year
public:
    //Default constructor
    HireDate() {day = 0; month = 0; year = 0;}
    //Constructor with data passed
    HireDate(int d, int m, int y) {day = d; month = m; year = y;}
    
    //Mutators and accessors
    void setDay(int d) {day = d;}
    int getDay() {return day;}
    
    void setMonth(int m) {month = m;}
    int getMonth() {return month;}
    
    void setYear(int y) {year = y;}
    int getYear() {return year;}
    
};

#endif /* HireDate_h */
