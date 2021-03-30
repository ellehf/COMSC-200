//
//  Timer.h
//  AS10 Template Deque
//
//  Created by Elle Hoarau on 5/2/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Timer_h
#define Timer_h
#include <chrono> // chrono
#include <cstdlib> // srand, rand
#include <ctime> // time
#include <algorithm> // sort
#include <iostream>

class Timer {
    // Type aliases to make accessing nested type easier
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    
    std::chrono::time_point<clock_t> m_beg;
 
public:
    Timer() : m_beg(clock_t::now()) {}
    void reset() { m_beg = clock_t::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

#endif /* Timer_h */
