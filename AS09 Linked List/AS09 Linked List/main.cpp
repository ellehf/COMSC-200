//
//  main.cpp
//  AS09 Linked List
//
//  Created by Elle Hoarau on 4/20/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "LinkedQueue.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void menu()
{
    cout << "\n--- AS9 LinkedQueue Test Menu ---\n"
    << " N - to bulk create New Queue\n"
    << " D - to Display\n"
    << " E - is Empty?\n"
    << " A - to Add ~ push front\n"
    << " a - to append ~ push back\n"
    << " R - to Remove ~ pop front\n"
    << " r - to Remove ~ pop back\n"
    << " L - Length of Queue?\n"
    << " C - to Clear\n"
    << " Q - to Q this program\n"
    << " H - this menu\n";
}

string del = ","; // default delimiter

int main()
{
  
    bool stay = true;
    
    // create one instance for each of the test classes
    cout << "\nInstanciate an object of Queue\n";
    // string catchVar; // To hold values popped off the Queue
    IntLinkedQueue q;
    
    cout << "\nFirst, test with hard-wired data sets!\n"
         << "For example, \nyou may use one set of tokens for all test classes: \n";
    string choice; // user input for choices
    string str; // user input for queue, delimiter, ...
    int s[] = {1, 3, 5, 7, 9};
    vector<int> input(s, end(s));
    
    // show the initial queue
    int input_size = input.size();
    for (auto item : input ) {
        cout << item << ((input_size <= 1) ? " " : ", ");
        input_size--;
    }
    cout << endl;
    
    // initialize the Queue class instances
    for (auto i: input) q.append( i );
    cout << "\nUse menu to test a Queue class instance.\n";
    menu();
    // main menu while
    while(stay) { // main menu while starts
        cout << "\n Enter your command: ";
        stay = true;
        cin >> choice;
        cin.ignore();
        int pos;
        string input;
        string token;
        int item;
        stringstream sst;
        stringstream ss;
        int Queue_size;
        
        if(choice.size() == 1) {
            char ch = choice[0];
            vector<string> dump;
            string value;
            switch(ch) { // main menu switch starts
                case 'n':
                case 'N':
                {
                    if(!q.isEmpty()) q.clear();
                    cout << "\t\tEnter a line of comma (,) delmited data set: ";
                    getline (cin, input); // user input -> string
                    ss << input; // string -> stream
                    while ( getline(ss, token, ',') ) { // stream -> string token
                        stringstream sst(token);
                        sst >> item;
                        q.append(item);
                    }
                    break;
                }
                
                case 'd':
                case 'D':
                {
                    cout << "Queue: " << q.toString() <<endl;
                    
                    break;
                }
                
                case 'e':
                case 'E':
                {
                    if(q.isEmpty())
                        cout << "Queue is empty." <<endl;
                    else
                        cout << "Queue is not empty." <<endl;
                    
                    break;
                }
                
                case 'A':
                {
                    int value;
                    cout << "Enter value to add: ";
                    cin >> value;
                    
                    if(q.add(value))
                        cout << value << " is added." <<endl;
                    
                    break;
                }
                    
                case 'a':
                {
                    int value;
                    cout << "Enter value to append: ";
                    cin >> value;
                    
                    if(q.append(value))
                        cout << value << " is appended." <<endl;
                    
                    break;
                }
                    
                case 'R':
                {
                    if(q.fremove())
                        cout << "Front is popped." <<endl;
                    else
                        cout << "Queue is already empty." <<endl;
                        
                    break;
                }
                    
                case 'r':
                {
                    if(q.rremove())
                        cout << "Back is popped." <<endl;
                    else
                        cout << "Queue is already empty." <<endl;
                    
                    break;
                }
                    
                case 'l':
                case 'L':
                {
                    cout << "Size of queue is: " << q.getSize() <<endl;
                    
                    break;
                }
                    
                case 'c':
                case 'C':
                {
                    q.clear();
                    
                    cout << "Queue is clear." <<endl;
                    
                    break;
                }
                
                case 'q': // exit Queue sub-menu
                case 'Q':
                    stay = false;
                    break;
                
                case 'h': // help - display menu
                case 'H':
                case '?':
                    menu();
                    break;
                
                default:
                    cout << "\nInvalid Selection!\nTry again!\n\n";
            
            } // end of menu switch
        } // only process single character
    } // end of main menu while
    cout << "Program exit!\n";
    
    return 0;
}
