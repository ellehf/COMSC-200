//
//  Palindrome.h
//  COMSC200 - Lab 2B Palindrome
//
//  Created by Elle Hoarau on 2/17/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Palindrome_h
#define Palindrome_h

#include <string>
#include <iostream>
using namespace std;

//Boolean function to test if string is palindrome
bool isPalindrome(string s)
{
    int len = s.length(); //Set to length of string

    string first = s.substr(0,1); //Hold first letter in string
    string last = s.substr((len-1), 1); //Hold last letter in string

    if (first == last) //Compare if first and last letter are the same
    {
        s = s.substr(1, (len-2)); //Move through string and continue comparing letters
        
        if (s.length() <= 1) //Base case, a string of one letter is a palindrome
            return 1;
        
        return isPalindrome(s); //Recursive call to check each letter
    }
    else
        return 0; //If two letters are not found equal, then string is not a palindrome
}

#endif /* Palindrome_h */
