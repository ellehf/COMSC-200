//
//  main.cpp
//  AS10 Template Linked List
//
//  Created by Elle Hoarau on 5/2/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#include "Timer.h"
#include <iostream>
using namespace std;

void show(int *a)
{
    for(int i=0; i<5; i++)
        cout << a[i] << " ";
        cout << endl;
}

void insertionSort(int *array, int size)
{
    int startScan, minValue, minIndex;
    
    for (startScan = 1; startScan < size; startScan++)
    {
        minValue = array[startScan];
        minIndex = startScan - 1;
  
        while (minIndex >= 0 && array[minIndex] > minValue)
        {
            array[minIndex + 1] = array[minIndex];
            minIndex = minIndex - 1;
        }
        array[minIndex + 1] = minValue;
    }
}

void selectionSort(int *array, int size)
{
    int startScan, minIndex, minValue;
    
    for (startScan = 0; startScan < size-1; startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        
        for(int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
            
}

int main()
{
    const int Size = 10000;
       int array1[Size];
       int array2[Size];
       
       srand (time(NULL));
       for(int i=0; i<Size; i++) {
           array1[i] =array2[i] = rand() % 100003; // next prime 10X
       }
       
       show(array1);
       show(array2);
       
    Timer t1;
       insertionSort(array1, Size);
       double run1 = t1.elapsed();
       show(array1);
           
       Timer t2;
       selectionSort(array2, Size);
       double run2 = t2.elapsed();
       show(array2);
       cout << "Insertion Sort Time: " << run1 << " seconds\n"
           << "Selection Sort Time: " << run2 << " seconds\n"
           << "Efficientcy: " << float( run1/run2 );
    
       return 0;
}
