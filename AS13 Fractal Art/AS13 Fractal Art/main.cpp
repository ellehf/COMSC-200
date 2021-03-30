//
//  main.cpp
//  AS13 Fractal Art
//
//  Created by Elle Hoarau on 5/9/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include<iostream>
using namespace std;

void pattern( int left, int length )
{
   if ( length == 0 ) return;
    
   pattern( left, length / 2 );                     // "Half pattern" above

    if(left != 0) cout << "*";                      // Left border
    for ( int i = 0; i < left  ; i++ ) cout << "  ";
    for ( int i = 0; i < length; i++ ) cout << "* ";  // Central string
    for ( int i = 0; i < left  ; i++ )  cout << "  ";
    cout << "*" << endl;                            // Right border

   pattern( left + length / 2, length / 2 );  // "Half pattern" below
   
}

int main()
{
    pattern( 0, 16 );
    
    return 0;
}
