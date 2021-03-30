//
//  main.cpp
//  COMSC200- AS 01 Intro to Classes
//
//  Created by Elle Hoarau on 2/5/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "Employee.h"

int main()
{
    int NUM; //Number of employees
    
    cout<< "Enter number of employees: ";
    cin>> NUM; //User inputs number
    
    Employee listEmp[NUM]; //Array of employee objects
    string name; //Name of employee
    int id; //Id number of employee
    string dept; //Department of employee
    string pos; //Position of employee
    
    //Loop for user to enter employee information
    for(int i=0; i<NUM; i++)
    {
        //Get employee name
        cout<< "Enter name of employee " << i+1 << ": ";
        cin.ignore();
        getline(cin, name);
        
        //Get employee id
        cout<< "Enter id number of employee " << i+1 << ": ";
        cin>> id;
        
        //Get employee department
        cout<< "Enter deparment of employee " << i+1 << ": ";
        cin>> dept;
        
        //Get employee position
        cout<< "Enter position of employee " << i+1 << ": ";
        cin>> pos;
        
        //Set employee info
        listEmp[i].setName(name);
        listEmp[i].setID(id);
        listEmp[i].setDept(dept);
        listEmp[i].setPos(pos);
    }
    
    //Table for information
    cout<< setw(4) << "Name" << setw(20) << "ID Number" << setw(15) << "Department" << setw(15) << "Position" <<endl;
    
    //Output user-entered data
    for(int i=0; i<NUM; i++)
    {
        cout<< setw(4) << listEmp[i].getName() << setw(10) << listEmp[i].getID() << setw(20) << listEmp[i].getDept() << setw(15) << listEmp[i].getPos() <<endl;
    }
    
    return 0;
}
