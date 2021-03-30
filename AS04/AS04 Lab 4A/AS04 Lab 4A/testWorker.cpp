//
//  main.cpp
//  AS04 Lab 4A
//
//  Created by Elle Hoarau on 2/28/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "ProductionWorker.h"

int main2()
{
    HireDate date(2,28,2020);
    
    ProductionWorker obj("Elle", 1234, date, night, 20);
    
    cout << "Employee info" <<endl;
    cout << "Employee name: " << obj.getName() <<endl;
    cout<< "Employee number: " << obj.getNumber() <<endl;
    cout<< "Employee hire date: " << obj.getDay() << "/" << obj.getMonth() << "/" << obj.getYear() <<endl;
    cout<< "Employee shift: " << obj.getShift() <<endl;
    cout<< "Employee hourly rate: $" << obj.getHourlyRate() <<endl;
    
    return 0;
}
