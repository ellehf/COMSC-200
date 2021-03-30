//
//  Date.h
//  COMSC200- AS 01 Intro to Classes
//
//  Created by Elle Hoarau on 2/5/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Employee_h
#define Employee_h

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Employee Class
class Employee
{
private:
    string name; //To hold employee's name
    int idNumber; //To hold employee's id
    string department; //To hold employee's department
    string position; //To hold employee's position
public:
    Employee(); //Default constructor
    Employee(string n, int i); //Constructor with name and id parameters passed
    Employee(string n, int i, string d, string p); //Constructor with all parameters passed
    
    void setName(string n); //To set name
    void setID(int i); //To set id
    void setDept(string d); //To set department
    void setPos(string p); //To set position
    
    string getName(); //Return name
    int getID(); //Return id
    string getDept(); //Return department
    string getPos(); //Return position
};

//Default constructor
Employee:: Employee()
{
    //Set member variables to blank or zero
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

//Constructor to initialize name and id
Employee:: Employee(string n, int i)
{
    name = n;
    idNumber = i;
    department = "";
    position = "";
}

//Constructor to initialize all member variables
Employee:: Employee(string n, int i, string d, string p)
{
    name = n;
    idNumber = i;
    department = d;
    position = p;
}

void Employee:: setName(string n)
{
    name = n;
}

void Employee:: setID(int i)
{
    idNumber = i;
}

void Employee:: setDept(string d)
{
    department = d;
}

void Employee:: setPos(string p)
{
    position = p;
}

string Employee:: getName()
{
    return name;
}

int Employee:: getID()
{
    return idNumber;
}

string Employee:: getDept()
{
    return department;
}

string Employee:: getPos()
{
    return position;
}

#endif /* Employee_h */
