//
//  main.cpp
//  AS07 Exception
//
//  Created by Elle Hoarau on 3/23/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "ProductionWorker.h"

int main()
{
    string name;
    int num, sft;
    double hr;
    
    int day, month, year;

    for(int i=0; i<4; i++)
    {
        cin.ignore();
        cout << "\nEnter worker's name: ";
        getline(cin, name);
        
        cout<< "Enter worker's employee number: ";
        cin>> num;
        
        cout << "Enter worker's shift: ";
        cin >> sft;
        
        cout << "Enter worker's hourly rate: ";
        cin>> hr;
        
        cout << "Enter worker's day month and year of hire date: " <<endl;
        cin >> day >> month >> year;
        
        HireDate hd(day, month, year);
        
        try
        {
            ProductionWorker worker(name, num, hd, sft, hr);
            
            cout << "\nEmployee info" <<endl;
            cout << "Employee name: " << worker.getName() <<endl;
            cout<< "Employee number: " << worker.getNumber() <<endl;
            cout<< "Employee hire date: " << worker.getDay() << "/" << worker.getMonth() << "/" << worker.getYear() <<endl;
            cout<< "Employee shift: " << worker.getShift() <<endl;
            cout<< "Employee hourly rate: $" << worker.getHourlyRate() <<endl;
        }
        catch (Employee :: InvalidEmployeeNumber e)
        {
            cout << "ERROR: " << e.getNum() << " is invalid employee number." <<endl;
        }
        catch(ProductionWorker :: InvalidShift e)
        {
            cout << "ERROR: " << e.getShift() << " is invalid shift." <<endl;
        }
        catch(ProductionWorker :: InvalidPayRate e)
        {
            cout << "ERROR: " << e.getPay() << " is invalid pay rate." <<endl;
        }
    }
    
    return 0;
}
