//
//  main.cpp
//  COMSC 200 - Lab 6
//
//  Created by Elle Hoarau on 3/16/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//ASSOCIATION
class Customer
{
public:
    string name;
    int cellNumber;
};
 
class Order
{
public:
    int number;
    Customer* cust;
    
    void setCustomer(Customer* c)
    {
        cust = c;
    }
};

//AGGREGATION - can exist without
class Clothing
{
public:
    string itemType;
    char size;
};
class Closet
{
public:
    int numHangers;
    int numShelves;
    Clothing* cloth;
    
    void setClothing(Clothing* c)
    {
        cloth = new Clothing;
        cloth->itemType = c->itemType;
        cloth->size = c->size;
    }
};

//COMPOSITION - cannot exist without
class Tire
{
public:
    double radius;
    double tread;
};

class Car
{
public:
    Tire tire;
    Car(Tire t)
    {
        tire.radius = t.radius;
        tire.tread = t.tread;
    }
};

//INHERITANCE
class Employee
{
protected:
    string name;
    int number;
};

class Manager : public Employee
{
private:
    int teamSize;
    int level;
};
