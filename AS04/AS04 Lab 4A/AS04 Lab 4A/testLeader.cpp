//
//  testLeader.cpp
//  AS04 Lab 4A
//
//  Created by Elle Hoarau on 2/28/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include <stdio.h>

#include "TeamLeader.h"

int main()
{
    HireDate date(03, 02, 2020);
    
    TeamLeader obj2("Elle", 1234, date, 2, 20, 100, 12, 15);
    
    cout << "Team leader's info";
    cout << "\nName: " << obj2.getName() <<endl;
    cout << "Number: " << obj2.getNumber() <<endl;
    cout << "Hire date: " << obj2.getDay() << "/" << obj2.getMonth() << "/" << obj2.getYear() <<endl;
    cout << "Shift: " << obj2.getShift() <<endl;
    cout<< "Hourly rate: $" << obj2.getHourlyRate() <<endl;
    cout << "Bonus: $" << obj2.getBonus() <<endl;
    cout << "Required training hours: " << obj2.getReqHrs() <<endl;
    cout << "Attended traning hours: " << obj2.getAttHrs() <<endl;
    
    
    if(obj2.getAttHrs() >= obj2.getReqHrs())
       cout << "Team leader gets a $" << obj2.getBonus() << " bonus!" <<endl;
    else
       cout << "Team leader did not attend enough training hours to receive a bonus." <<endl;
    
    return 0;
}
