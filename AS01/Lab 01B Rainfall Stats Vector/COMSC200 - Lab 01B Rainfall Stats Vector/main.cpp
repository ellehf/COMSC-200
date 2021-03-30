//
//  main.cpp
//  COMSC200 - Lab 01B Rainfall Stats Vector
//
//  Created by Elle Hoarau on 2/4/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    enum Month {Jan, Feb, Mar, Apr, May, June, July, Aug, Sept, Oct, Nov, Dec};

    const int MONTHS = 12;
    
    vector<double> rainfall(MONTHS);
    Month m;
    double total=0.0;
    
    for(m = Jan; m <= Dec; m = static_cast<Month>(m+1))
    {
        cout<< "Enter rainfall for month " << m+1 << ": ";
        cin>> rainfall[m];
        
        while(rainfall[m]<0)
        {
            cout<< "Rainfall must be 0 or more. Please enter a valid rainfall.\n";
            cin>> rainfall[m];
        }
    }
    
    for(m = Jan; m <= Dec; m = static_cast<Month>(m+1))
    {
        total += rainfall[m];
    }
    
    double x=0.0;
    
    for(m = Jan; m <= Dec; m = static_cast<Month>(m+1))
    {
        if(rainfall[m]>x)
            x = rainfall[m];
    }
    
    double y=rainfall[Jan];
    
    for(m = Jan; m <= Dec; m = static_cast<Month>(m+1))
    {
        if(rainfall[m]<y)
            y = rainfall[m];
    }
    
    
    cout<< "\nThe total rainfall is: " << total;
    cout<< "\nThe average rainfall is: " << total/12.0;
    cout<< "\nThe highest rainfall is: " << x;
    cout<< "\nThe lowest rainfall is: " << y;
    
    return 0;
}

