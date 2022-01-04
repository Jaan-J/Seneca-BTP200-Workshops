// Workshop 9
// Date: 2021/4/1
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Car.h"
#include "Collection.h"
#include "Employee.h"
#include "ReadWrite.h"
#include "Student.h"
namespace sdds
{
    template <typename T, typename U>
    bool search(Collection<T> &templObj, T arr[], int numElements, U searchKey)
    {
        bool flag = false;
        for (int i = 0; i < numElements; i++)
        {
            if (arr[i] == searchKey)
            {
                flag = true;
                templObj.add(arr[i]);
            }
        }
        return flag;
    }

    template <typename T>
    void listArrayElements(const char *title, const T arr[], int numElements)
    {
        std::cout << title << std::endl;
        for (int i = 0; i < numElements; i++)
        {
            std::cout << i + 1 << ": " << arr[i] << std::endl;
        }
    }
}
#endif