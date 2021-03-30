//
//  main.cpp
//  COMSC200 - Lab 01D Date Class
//
//  Created by Elle Hoarau on 2/4/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "Date.h"

int main()
{
    //Using overloaded constructor
    Date today(12, 25, 2012);

    //Show date in form #1.
    today.showDate1();

    //Store new month, day, and year in object
    today.setMonth(8);
    today.setDay(16);
    today.setYear(2012);

    //Show date in form #2
    today.showDate2();

    //Show date in form #3
    today.showDate3();

    //Test invalid date
    Date someday(12, 32, 2012);
    
    return 0;
}
