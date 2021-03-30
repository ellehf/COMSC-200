//
//  Date.h
//  COMSC200 - Lab 01D Date Class
//
//  Created by Elle Hoarau on 2/4/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Date_h
#define Date_h

#include <iostream>
using namespace std;

//String containing month names
string MONTHS[12]= {"January", "February" , "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//Date class to display various forms
class Date
{
private:
    int month; //To hold month number
    int day; //To hold day number
    int year; //To hold year number
public:
    Date(); //Default constructor
    Date(int m, int d, int y); //Constructor when object passed with initial values
    
    void setMonth(int m); //To set object's month
    void setDay(int d); //To set object's day
    void setYear(int y); //To set object's year
    
    void showDate1(); //To display date in month/day/year form
    void showDate2(); //To display date in month day, year form
    void showDate3(); //To display date in day month year form
};

//Default constructor
Date:: Date()
{
    //Set member variables to zero
    month=0;
    day=0;
    year=0;
}

//Constructor with initial values for member variables
Date:: Date(int m, int d, int y)
{
    //Input validation
    if(m>12 || m<1) //No negative values, or values greater than 12 for months
        cout<< m << " is not a valid value for month.\n";
    else
        month=m;

    if(d>31 || m<1) //No negative values, or values greater than 31 for days
        cout<< d << " is not a valid value for day.\n";
    else
        day=d;
    
    year=y;
    
}

//Set month value
void Date:: setMonth(int m)
{
    month=m;
}

//Set day value
void Date:: setDay(int d)
{
    day=d;
}

//Set year value
void Date:: setYear(int y)
{
    year=y;
}

//Display date in form 1
void Date:: showDate1()
{
    cout<< month << "/" << day << "/" << year <<endl;
}

//Display date in form 2
void Date:: showDate2()
{
    cout<< MONTHS[month-1] << " " << day << ", " << year <<endl;
}

//Display date in form 3
void Date:: showDate3()
{
    cout<< day << " " << MONTHS[month-1] << " " << year <<endl;
}

#endif /* Date_h */
