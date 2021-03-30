//
//  Timer.h
//  AS10 Template Linked List
//
//  Created by Elle Hoarau on 5/2/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Timer_h
#define Timer_h

#include <chrono> // for std::chrono functions
#include <cstdlib> // srand, rand
#include <ctime> // time
#include <algorithm> // sort
#include <iostream>
using namespace std;
 
class Timer
{
private:
    // Type aliases to make accessing nested type easier
        using clock_t = chrono::high_resolution_clock;
        using second_t = chrono::duration<double, std::ratio<1> >;
        
        chrono::time_point<clock_t> m_beg;
     
public:
        Timer() : m_beg(clock_t::now()) {}
        void reset() { m_beg = clock_t::now(); }
        double elapsed() const
            { return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count(); }
};

#endif /* Timer_h */
