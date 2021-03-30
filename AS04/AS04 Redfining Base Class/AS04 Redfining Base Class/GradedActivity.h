//
//  GradedActivity.h
//  AS04 Redfining Base Class
//
//  Created by Elle Hoarau on 2/29/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef GradedActivity_h
#define GradedActivity_h

#include <iostream>
#include <iomanip>
using namespace std;

class GradedActivity
{
protected:
    double score; // To hold the numeric score
public:
    GradedActivity() { score = 0.0; }
    GradedActivity(double s) { score = s; }
    void setScore(double s) { score = s; }
    double getScore() const { return score; }
    virtual char getLetterGrade() const;
};

char GradedActivity::getLetterGrade() const {
    char letterGrade; // To hold the letter grade
    
    if (score > 89) letterGrade = 'A';
    else if (score > 79) letterGrade = 'B';
    else if (score > 69) letterGrade = 'C';
    else if (score > 59) letterGrade = 'D';
    else letterGrade = 'F';
    
    return letterGrade;
}

#endif /* GradedActivity_h */
