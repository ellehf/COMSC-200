//
//  TeamLeader.h
//  AS04 Lab 4A
//
//  Created by Elle Hoarau on 2/28/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef TeamLeader_h
#define TeamLeader_h
#include "ProductionWorker.h"

//TeamLeader is a ProductionWorker
class TeamLeader : public ProductionWorker
{
protected:
    int bonus; //Holds dollar amount bonus
    int reqHrs; //Holds number of required training hours
    int attHrs; //Holds number of attended training hours
public:
    //Default constructor
    TeamLeader() : ProductionWorker() {bonus = 0; reqHrs = 0; attHrs = 0;}
    //Constructor with data passed
    TeamLeader(string n, int num, HireDate date, int s, double hr, int bon, int req, int att) : ProductionWorker(n, num, date, s, hr) {bonus = bon; reqHrs = req; attHrs = att;}
    
    //Accessors and mutators
    void setBonus(int b) {bonus = b;}
    int getBonus() {return bonus;}
    
    void setReqHrs(int req) {reqHrs = req;}
    int getReqHrs() {return reqHrs;}
    
    void setAttHrs(int att) {attHrs = att;}
    int getAttHrs() {return attHrs;}
};

#endif /* TeamLeader_h */
