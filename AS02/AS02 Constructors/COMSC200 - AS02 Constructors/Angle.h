//
//  Angle.h
//  COMSC200 - AS02 Constructors
//
//  Created by Elle Hoarau on 2/11/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Angle_h
#define Angle_h

#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

class Angle
{
private:
    //Member variables of dms coordinate
    double degrees;
    double minutes;
    double seconds;
    char direction;
public:
    Angle(); //Default constructor
    Angle(double d, double m, double s, char D); //Constructor that takes all parameters
    Angle(double gps, int latlon); //Constructor that takes gps and indicates if lat or lon
    void convertGPS(double gps, int latlon); //Function to convert GPS to DMS
    void print(); //Display function
    
    //Accessors and mutators
    void setDegrees(double d) ;
    void setMinutes(double m);
    void setSeconds(double s);
    void setDirection(char d);
    double getDegrees() const;
    double getMinutes() const;
    double getSeconds() const;
    char getDirection() const;
};

void Angle :: setDegrees(double d)
{
    degrees = d;
}

void Angle :: setMinutes(double m)
{
    minutes = m;
}

void Angle :: setSeconds(double s)
{
    seconds = s;
}

void Angle :: setDirection(char d)
{
    direction = d;
}

double Angle :: getDegrees() const
{
    return degrees;
}

double Angle :: getMinutes() const
{
    return minutes;
}

double Angle :: getSeconds() const
{
    return seconds;
}

char Angle :: getDirection() const
{
    return direction;
}

//Default constructor to initialize member variables
Angle :: Angle()
{
    degrees = 0;
    minutes = 0;
    seconds = 0;
    direction = 'N';
}

//Constructor to initialize member variables to passed values
Angle :: Angle(double d, double m, double s, char D)
{
    degrees = d;
    minutes = m;
    seconds = s;
    direction = 'D';
}

//Constructor to convert passed gps value to dms
Angle :: Angle(double gps, int latlon)
{
    //Set direction
    if(latlon==0 && gps>0) //If latlon=0, then latitude
        direction = 'N';
    else if(latlon==0 && gps<0) //If latlon=0 and coordinate is negative, then direction is south
    {
        direction = 'S';
        gps = gps*-1;
    }
    else if(latlon==1 && gps>0) //If latlon=1, then latitude
        direction = 'E';
    else                    //If latlon=1 and gps negative, then direction is west
    {
        direction = 'W';
        gps = gps*-1;
    }
    
    //Convert gps to dms
    double fract1 = modf(gps, &degrees);
    fract1 = fract1*60;
    double fract2 = modf(fract1, &minutes);
    seconds = fract2*60;
}
    
void Angle :: convertGPS(double gps, int latlon)
{
    if(latlon==0 && gps>0) //If latlon=0, then latitude
        direction = 'N';
    else if(latlon==0 && gps<0) //If latlon=0 and coordinate is negative, then direction is
    {
        direction = 'S';
        gps = gps*-1;
    }
    else if(latlon==1 && gps>0) //If latlon=1, then latitude
        direction = 'E';
    else                        //If latlon=1 and gps negative, then direction is west
    {
        direction = 'W';
        gps = gps*-1;
    }
    
    //Convert gps to dms
    double fract1 = modf(gps, &degrees);
    fract1 = fract1*60;
    double fract2 = modf(fract1, &minutes);
    seconds = fract2*60;
}

//Prints coordinates
void Angle :: print() {
    cout <<setprecision(2) << fixed << degrees << "° " << minutes << "' " << seconds << "\" " << direction;
}

#endif /* Angle_h */
