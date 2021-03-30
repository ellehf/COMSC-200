//
//  SortableVector.h
//  COMSC 200 - Lab 7B Sortable Vector Class Template
//
//  Created by Elle Hoarau on 3/23/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef SortableVector_h
#define SortableVector_h
#include "SimpleVector.h"

template <class T>
class SortableVector : public SimpleVector<T>
{
public:
    //Default Constructor
    SortableVector() : SimpleVector<T>() {}
    
    //Constructor
    SortableVector(int size) : SimpleVector<T>(size) {}
    
    //Copy Constructor
    SortableVector(const SortableVector &);
    
    //Function to sort elements using selection sort
    void selectionSort();
};

template <class T>
SortableVector<T> :: SortableVector(const SortableVector &obj) : SimpleVector<T>(obj.size())
{
    for(int i = 0; i < this->size(); i++)
          this->operator[](count) = obj[count];
}


template <class T>
void SortableVector<T> :: selectionSort()
{
    for (int i = 0; i < this->size()-1; i++)
      {
          // Find the minimum element
          int min = i;
          
          for (int j = i+1; j < this->size(); j++)
          {
              if(this->operator[](j) < this->operator[](min))
                  min = j;
          }
          
          // Swap the found minimum element with the first element
          //store lowest value in temp
          T temp = this->operator[](min);
          //put largest value in second element
          this->operator[](min) = this->operator[](i);
          //store temp in first element
          this->operator[](i) = temp;
      }
}

#endif /* SortableVector_h */
