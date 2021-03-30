//
//  main.cpp
//  COMSC200 - module 1 ex
//
//  Created by Elle Hoarau on 2/4/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include <iostream>
using namespace std;

enum Month {Jan, Feb, Mar, Apr, May, June, July, Aug, Sept, Oct, Nov, Dec};

const int MONTHS = 12;

class rainFall
{
private:
    double rainfall[MONTHS];
    Month m;
    double total=0.0;
public:
    void getRainFall();
    double getTotal();
    double getAvg();
    double getHigh();
    double getLow();
};

void rainFall:: getRainFall()
{
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
}

double rainFall:: getTotal()
{
    for(m = Jan; m <= Dec; m = static_cast<Month>(m+1))
    {
        total += rainfall[m];
    }
    
    return total;
}

double rainFall:: getAvg()
{
    return total/12.0;
}

double rainFall:: getHigh()
{
    double x=0.0;
    
    for(m = Jan; m <= Dec; m = static_cast<Month>(m+1))
    {
        if(rainfall[m]>x)
            x = rainfall[m];
    }
    
    return x;
}

double rainFall:: getLow()
{
    double y=rainfall[Jan];
    
    for(m = Jan; m <= Dec; m = static_cast<Month>(m+1))
    {
        if(rainfall[m]<y)
            y = rainfall[m];
    }
    
    return y;
}


int main()
{
    rainFall test1;
    
    test1.getRainFall();
    
    cout<< "\nThe total rainfall is: " << test1.getTotal();
    cout<< "\nThe average rainfall is: " << test1.getAvg();
    cout<< "\nThe highest rainfall is: " << test1.getHigh();
    cout<< "\nThe lowest rainfall is: " << test1.getLow();
    
    return 0;
}
