//
//  main.cpp
//  COMSC200 - Lab 01C Rectangle Class
//
//  Created by Elle Hoarau on 2/4/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "Rectangle.h"

int main()
{
   double num; //To hold dimensions
   double total; //Total area

   //Declare rectangle objects
   Rectangle kitchen;
   Rectangle bedroom;
   Rectangle den;

   //Get kitchen dimensions
   cout<< "What is the kitchen's length? ";
   cin>> num; //Get length
   kitchen.setLength(num); //Store in kitchen object
   cout<< "What is the kitchen's width? ";
   cin>> num; //Get width
   kitchen.setWidth(num); //Store in kitchen object
   
   //Get bedroom dimensions
   cout<< "What is the bedroom's length? ";
   cin>> num; //Get length
   bedroom.setLength(num); //Store in bedroom object
   cout<< "What is the bedroom's width? ";
   cin>> num; //Get width
   bedroom.setWidth(num); //Store in bedroom object

   //Get den dimensions.
   cout<< "What is the den's length? ";
   cin>> num; //Get length
   den.setLength(num); //Store in den object
   cout<< "What is the den's width? ";
   cin>> num; //Get width
   den.setWidth(num); //Store in den object
   
   //Calculate total area of three rooms
   total= kitchen.getArea() + bedroom.getArea() + den.getArea();
   
   //Display total area of three rooms
   cout<< "The total area of the three rooms is: " << total << endl;
   
   return 0;
} 
