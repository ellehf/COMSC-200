//
//  main.cpp
//  COMSC 200 - Lab 7A Time Format Exception
//
//  Created by Elle Hoarau on 3/22/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include <iostream>
#include "MilTime.h"
using namespace std;

int main()
{
    int hour, seconds;
    
    for(int i=0; i<4; i++)
    {
        cout << "\nEnter military hour and seconds:\n";
        cin >> hour >> seconds;
        
        try
        {
            MilTime timeObj(hour, seconds);
            cout << "The hour in military format is "
                 << timeObj.getHour() << endl;
            cout << "The hour in standard format is "
                 << timeObj.getStandHr() << endl;
            cout << "The minutes are "
                 << timeObj.getMin() << endl;
            cout << "The seconds are "
                 << timeObj.getSec() << endl;
        }
        catch (MilTime :: BadHour h)
        {
            cout<< "Error: " << h.getHour()
            << " is an invalid value for the MilTime's Hours." <<endl;
        }
        catch (MilTime :: BadSeconds s)
        {
            cout<< "Error: " << s.getSeconds()
            << " is an invalid value for the MilTime's seconds." <<endl;
        }
    }
    
    return 0;
}
