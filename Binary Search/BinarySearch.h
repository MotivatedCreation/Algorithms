//
//  BinarySearch.cpp
//  Data Structures
//
//  Created by Jonathan Sullivan on 7/17/15.
//

#include <stdio.h>

template<typename T, A>
T binarySearch(int first, int last, A array[], const T &target)
{
    int mid = 0;
    
    while (first <= last)
    {
        mid = (first + last) / 2;
        
        if (array[mid] < target)
        {
            first = (mid + 1);
        }
        else if (target < array[mid])
        {
            last = (mid - 1);
        }
        else {
            return mid;
        }
    }
    
    return -1;
}

