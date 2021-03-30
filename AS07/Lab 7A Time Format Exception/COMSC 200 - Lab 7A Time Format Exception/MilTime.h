//
//  MilTime.h
//  COMSC 200 - Lab 7A Time Format Exception
//
//  Created by Elle Hoarau on 3/22/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef MilTime_h
#define MilTime_h
#include "Time.h"

// Declaration of the MilTime class

class MilTime : public Time
{
private:
    int milHours;
    int milSeconds;
public:
    
    //Exception class for bad seconds
    class BadSeconds
    {
    private:
        int seconds;
    public:
        BadSeconds(int sec)
            { seconds = sec; }
        
        int getSeconds() const
            { return seconds; }
    };
    
    // Exception class for bad hour
    class BadHour
    {
        private:
            int hour;
        public:
            BadHour(int hr) {hour = hr;}
            
            int getHour() const {return hour;}
    };
    
    MilTime(int h, int s) : Time(0,0, s)
    {
        
            if (h >= 0 && h <= 2359)
                milHours = h;
            else
                throw BadHour(h);
            
            if(s >= 0 && s <= 59)
                milSeconds = s;
            else
                throw BadSeconds(s);
            
            convert();
        
    };

    void convert();

    void setTime(int, int);

    int getHour() const
        { return milHours; }

    int getStandHr() const
        { return hour; }
};


//***********************************************
// convert member function                      *
//***********************************************

void MilTime :: convert()
{
    double temp;

    if (milHours > 1200)
        hour = milHours - 1200;
    else
        hour = milHours;
    
    hour /= 100;
    temp = (milHours - 1200) / 100.0;
    min = static_cast<int>(((temp - static_cast<int>(temp)) * 100));
}

//***********************************************
// setTime member function                      *
//***********************************************

void MilTime :: setTime(int h, int s)
{
    milHours = h;
    milSeconds = s;
    convert();
}


#endif /* MilTime_h */
