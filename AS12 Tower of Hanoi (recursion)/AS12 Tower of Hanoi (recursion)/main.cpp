//
//  main.cpp
//  AS12 Tower of Hanoi (recursion)
//
//  Created by Elle Hoarau on 5/15/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//
#include <vector>
#include <iostream>
using namespace std;

//STL Vectors implemented as stacks
vector <int> source; //source stack
vector <int> spare; //spare stack
vector <int> dest; //destination stack

void display(); //Pre-declaration of display function

//Hanoi Tower recursive function
void Hanoi(int n, vector<int> &source, vector<int> &dest, vector<int> &spare) //Size of tower passed as argument n
{
    if(n>0) //Base case
    {
        Hanoi(n-1, source, spare, dest); //Call function with spare and dest arguments swapped
        
        dest.push_back(source.back()); //Move disk from source to destination
        source.pop_back();
        
        display(); //Display progress
    
        Hanoi(n-1, spare, dest, source); //Call function with source and spare arguments swapped
    }
}

void display()
{
    //Display source stack
    cout << "Source: ";
    for(int i=0; i<source.size(); i++)
        cout << source.at(i) << ' ';
    
    //Display destination stack
    cout << "| Dest: ";
    for(int i=0; i<dest.size(); i++)
        cout << dest.at(i) << ' ';
    
    //Display spare stack
    cout << "| Spare: ";
    for(int i=0; i<spare.size(); i++)
        cout << spare.at(i) << ' ';
    
    cout <<endl;
}


int main()
{
    int n; //Variable to hold tower size
    
    //Take user input for tower size
    cout << "Enter size of tower: ";
    cin >> n;
    
    //Build tower
    for(int i=n; i>0; i--)
        source.push_back(i);
    
    //Display tower
    display();
    
    //Call Hanoi tower function
    Hanoi(n, source, dest, spare);
    
    return 0;
}
