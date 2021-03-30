//
//  Essay.h
//  AS04 Redfining Base Class
//
//  Created by Elle Hoarau on 2/29/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Essay_h
#define Essay_h

#include "GradedActivity.h"



class Essay : public GradedActivity
{
private:
    const int G = 30; //Max points on grammar
    const int S = 20; //Max points on spelling
    const int L = 20; //Max points on length
    const int C = 30; //Max points on content
    
    double grammar; //Hold grammar score
    double spelling; //Hold spelling score
    double length; //Hold length score
    double content; //Hold content score
public:
    //Default constructor
    Essay() : GradedActivity() {grammar = 0.0; spelling = 0.0; length = 0.0; content = 0.0;}
    //Constructor with scores passed
    Essay(double gram, double spell, double len, double cont) : GradedActivity(gram+spell+len+cont)
    {grammar = gram; spelling = spell; length = len; content= cont;}
    
    //Accessors and mutators
    void setGrammar(double gram);
    double getGrammar() const {return grammar;}
    
    void setSpelling(double spell);
    double getSpelling() const {return spelling;}
    
    void setLength(double len);
    double getLength() const {return length;}
       
    void setContent(double cont);
    double getContent() {return content;}
    
    virtual char getLetterGrade() const;
    
    
};

void Essay :: setGrammar(double gram)
{
    //Input validation
    while(gram<0 || gram>G)
    {
        cout << "Grammar score must be between 0 and 30 points. "
        << "Please enter again: " <<endl;
        cin >> gram;
    }
    
    grammar = gram; //Set grammar score
    setScore(grammar+spelling+length+content); //Update total score
}

void Essay :: setSpelling(double spell)
{
    //Input validation
    while(spell<0 || spell>S)
    {
        cout << "Spelling score must be between 0 and 20 points. "
        << "Please enter again: " <<endl;
        cin >> spell;
    }
    
    spelling = spell; //Set spelling score
    setScore(grammar+spelling+length+content); //Update total score
}

void Essay :: setLength(double len)
{
    //Input validation
    while(len<0 || len>G)
    {
        cout << "Length score must be between 0 and 20 points. "
        << "Please enter again: " <<endl;
        cin >> len;
    }
    
    length = len;//Set length score
    setScore(grammar+spelling+length+content); //Update total score
}

void Essay :: setContent(double cont)
{
    //Input validation
    while(cont<0 || cont>G)
    {
        cout << "Content score must be between 0 and 30 points. "
        << "Please enter again: " <<endl;
        cin >> cont;
    }
    
    content = cont; //Set content score
    setScore(grammar+spelling+length+content); //Update total score
}

//Calculate letter grade
char Essay :: getLetterGrade() const
{
    char letterGrade;
    
    if (score > 84) letterGrade = 'A'; //Redefine A to be 85 and above
    else if (score > 74) letterGrade = 'B'; //Redfine B to be 75 and above
    else letterGrade = 'C';    //No failing grade for an essay. All essays below 75 receive a 'C' grade
    
    return letterGrade;
}

#endif /* Essay_h */
