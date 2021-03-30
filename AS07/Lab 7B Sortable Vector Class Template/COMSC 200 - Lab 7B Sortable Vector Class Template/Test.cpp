//
//  main.cpp
//  COMSC 200 - Lab 7B Sortable Vector Class Template
//
//  Created by Elle Hoarau on 3/23/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "SortableVector.h"
using namespace std;

int main()
{
    const int SIZE = 5;  // The array size

        // Define SortableVector objects.
        SortableVector<int> intTable(SIZE);
        SortableVector<double> doubleTable(SIZE);

        // Place values into the arrays in descending order.
        for (int x = 0; x < SIZE ; x++)
        {
            intTable[x] = SIZE - x;
            doubleTable[x]= SIZE - (x * 1.1f);
        }

        // Display the values in the arrays.
        cout << "Before sorting, these values are in intTable:\n";
        for (int x = 0; x < SIZE; x++)
            cout << intTable[x] << "  ";
        cout << "\nBefore sorting, these values are in doubleTable:\n";
        for (int x = 0; x < SIZE; x++)
            cout << doubleTable[x] << "  ";
        
        // Sort the arrays.
        intTable.selectionSort();
        doubleTable.selectionSort();

        cout << "\nAfter sorting, these values are in intTable:\n";
        for (int x = 0; x < SIZE; x++)
            cout << intTable[x] << "  ";
        cout << "\nAfter sorting, these values are in doubleTable:\n";
        for (int x = 0; x < SIZE; x++)
            cout << doubleTable[x] << "  ";

    
    return 0;
}
