//
//  main.cpp
//  COMSC200 - AS02 Constructors
//
//  Created by Elle Hoarau on 2/11/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//
#include "Angle.h"

int main()
{
    double lat, lon; //Initialize variables to hold gps values
    Angle latA, lonA; //Create to angle objects
    
    //Get user input for gps coordinates
    cout << "\nEnter GPS-style coordinates:"
         << "\n\tLatitude: (+/- 0-90.00): ";
    cin >> lat;
    cout << "\tLongitude: (+/- 0-180.00): ";
    cin >> lon;
    
    //Use Angle function to convert gps to dms
    latA.convertGPS(lat, 0);
    lonA.convertGPS(lon, 1);

    cout << "\tDMS: (";
    latA.print();
    cout << ", ";
    lonA.print();
    cout << ")\n";
    
    // using GPS to DMS constructor
    cout << "\n\tEnter GPS-style coordinates:"
         << "\n\t\tLatitude: (+/- 0-90.00): ";
    cin >> lat;
    Angle latC(lat, 0);
    
    cout << "\t\tLongitude: (+/- 0-180.00): ";
    cin >> lon;
    Angle lonC(lon, 1);
    
    cout << "\tDMS: (";
    latC.print();
    cout << ", ";
    lonC.print();
    cout << ")\n";
    
    return 0;
}
