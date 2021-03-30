//
//  main.cpp
//  AS04 Redfining Base Class
//
//  Created by Elle Hoarau on 2/29/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "Essay.h"

int main()
{
    cout << "Essay Score Calculator" <<endl;
    cout << "Grading guidelines:" <<endl;
    cout <<"\tA score of 85 and above will receive an A."
    << "\n\tA score of 75 and above will recieve a B."
    << "\n\tAny score below a 75 will receive a C. There are no failing grades." <<endl;
    
    int numStu;
    
    cout << "\nHow many students do you have? ";
    cin >> numStu; //Holds number of students in class
    
    Essay student; //Create essay object
    double g; //Hold grammar score
    double s; //Hold spelling score
    double l; //Hold length score
    double c; //Hold content score
    
    double sum = 0; //Sum of students scores

    for(int i=0; i<numStu; i++) //Loop to enter each student's score
    {
    
    cout << "\nEnter grammar score for student " << i+1 << ": ";
    cin >> g;
    cout<< "Enter spelling score for student " << i+1 << ": ";
    cin>> s;
    cout<< "Enter length score for student " << i+1 << ": ";
    cin >> l;
    cout<< "Enter content score for student " << i+1 << ": ";
    cin>> c;
    
    //Set student's scores
    student.setGrammar(g);
    student.setSpelling(s);
    student.setLength(l);
    student.setContent(c);
        
    double score = student.getScore();
    
    cout<< "\nStudent's total score: " << score
    << "\nStudent's letter grade: " << student.getLetterGrade() <<endl;
    
    sum += score; //Add score to total
        
    }
    
    cout << "\nAverage score of class: " << sum/numStu <<endl; //Average score of class
    
    return 0;
}

