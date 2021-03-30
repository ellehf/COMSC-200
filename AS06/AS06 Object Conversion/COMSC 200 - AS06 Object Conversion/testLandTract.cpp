//
//  main.cpp
//  COMSC 200 - AS06 Object Conversion
//
//  Created by Elle Hoarau on 3/16/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "FeetInches.h"
#include "LandTract.h"
using namespace std;

void menu();

int main()
{
    bool stay = true;             // Boolean to stay in this menu
    string choice, word, text;   // User input for choices and input
    
    //Hold data for LandTract object
    int feet, inches;
    FeetInches width, length;
    LandTract myProperty;
    
    //Hold data for area comparison
    int feet2, inches2;
    FeetInches width2, length2;
    LandTract myProperty2;
    
    auto menu = [] ( ) {
        cout << "_______ LandTract Class Test Menu __________\n"
             << "    m - menu\n"
             << "    n - new LandTract\n"
             << "    d - display the LandTract attributes\n"
             << "    c - compare two LandTract areas\n"
             << "    q - Quit\n";

        };
        menu();
    while(stay) {           // Main menu while starts
        cout << "    Enter your choice: ";
        cin >> choice;      // Take in user choice from menu
        cin.ignore();
        char ch = choice[0];

        switch(ch) { // menu switch start
            case 'n':
            case 'N': // new LandTract
            {
                //Take user input
                cout << "      Enter Tract Width in Feet and Inches: \n";
                cout << "       Feet: ";
                cin >> feet;
                cout << "       Inches: ";
                cin >> inches;
                
                width.setFeet(feet); //Set width feet
                width.setInches(inches); //Set width inches
                
                myProperty.setWidth(width); //Set landtract width
                
                //Take user input
                cout << "      Enter Tract Length in Feet, then Inches: \n";
                cout << "       Feet: ";
                cin >> feet;
                cout << "       Inches: ";
                cin >> inches;
                
                length.setFeet(feet); //Set length feet
                length.setInches(inches); //Set length inches
                
                myProperty.setLength(length); //Set landtract length
                
                cout << endl;
                break;
            }
            case 'd':
            case 'D': // Display this LandTract
            {
                // Display the area.
                cout << "      The width is " << myProperty.getWidth()
                     << "\n      The length is " << myProperty.getLength()
                     << "\n      The area is " << myProperty.getArea() << " square feet."
                     << "\n\n";
                break;
            }
            
            case 'c': //Compare area of two LandTracts
            case 'C':
            {
                cout << "      Enter Tract 1 Width in Feet and Inches: \n";
                cout << "       Feet: ";
                cin >> feet;
                cout << "       Inches: ";
                cin >> inches;
                
                width.setFeet(feet); //Set width feet
                width.setInches(inches); //Set width inches
                
                myProperty.setWidth(width); //Set landtract width
                
                //Take user input
                cout << "      Enter Tract 1 Length in Feet, then Inches: \n";
                cout << "       Feet: ";
                cin >> feet;
                cout << "       Inches: ";
                cin >> inches;
                
                length.setFeet(feet); //Set length feet
                length.setInches(inches); //Set length inches
                
                myProperty.setLength(length); //Set landtract length
                
                cout << "      Enter Tract 2 Width in Feet and Inches: \n";
                cout << "       Feet: ";
                cin >> feet2;
                cout << "       Inches: ";
                cin >> inches2;
                
                width2.setFeet(feet2); //Set width feet
                width2.setInches(inches2); //Set width inches
                
                myProperty2.setWidth(width2); //Set landtract width
                
                //Take user input
                cout << "      Enter Tract 2 Length in Feet, then Inches: \n";
                cout << "       Feet: ";
                cin >> feet2;
                cout << "       Inches: ";
                cin >> inches2;
                
                length2.setFeet(feet2); //Set length feet
                length2.setInches(inches2); //Set length inches
                
                myProperty2.setLength(length2); //Set landtract length
                
                //Compare areas of two LandTracts
                if(myProperty2.getArea() == myProperty.getArea())
                    cout << "LandTracts have equal area." <<endl;
                else
                    cout<< "LandTracts do not have equal area." <<endl;
                
                break;
            }

            case 'm': case 'M':
                menu(); break;
            case 'q': case 'Q': // quit
                stay = false;
                break;

            default: // Invalid! Tells user to try again
                cout << "\nInvalid command!\nTry again!\n\n";
        }
    }
    cout << "\nProgram exit!\n";
}
