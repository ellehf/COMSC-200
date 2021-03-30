//
//  main.cpp
//  COMSC200 - Lab 2B Palindrome
//
//  Created by Elle Hoarau on 2/11/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "Palindrome.h"

int main()
{
    const int SIZE = 6;

    // Create an array of strings to test.
    string testStrings[SIZE] =
            { "ABLE WAS I ERE I SAW ELBA",
              "FOUR SCORE AND SEVEN YEARS AGO",
              "NOW IS THE TIME FOR ALL GOOD MEN",
              "DESSERTS I STRESSED",
              "AKS NOT WHAT YOUR COUNTRY CAN DO FOR YOU",
              "KAYAK" };
   
   // Test the strings.
   for (int i = 0; i < SIZE; i++)
   {
      cout << "\"" << testStrings[i] << "\"";
      if (isPalindrome(testStrings[i]))
          cout << " is a palindrome.\n";
      else
          cout << " is NOT a palindrome.\n";
   }
 
    return 0;
}
