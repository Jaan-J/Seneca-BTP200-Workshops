// Workshop 3: DIY
// Date: Feb 7, 2021
// Author: Jaan Javed
// Student ID: 100131192
// I have done all the coding by myself and only
// copied the code that my professor provided
// to complete my workshops and assignments.
/////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;

namespace sdds
{

    int CalorieList::totalCalorie() const
    {
        int combined = 0;

        for (int d = 0; d < m_noOfItems; d++)
        {
            combined += m_items[d].calorie();
        }
        return combined;
    }

    void CalorieList::setEmpty()
    {
        m_items = nullptr;
    }

    bool CalorieList::isValid() const
    {
        bool valid = true;
        valid = m_items != nullptr;

        for (int d = 0; valid == true && d < m_noOfItems; d++)
        {
            valid = m_items[d].isValid() && valid;
        }
        return valid;
    }

    void CalorieList::Title() const
    {
        cout << "+----------------------------------------------------+" << endl;

        if (isValid())
        {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }

        else
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }

        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }

    void CalorieList::footer() const
    {
        cout << "+--------------------------------+------+------------+" << endl;

        if (isValid())
        {

            cout << "|    Total Calories for today:";
            cout.width(9);
            cout << right << totalCalorie();
            cout << " | ";

            cout.width(12);
            cout << setfill(' ');
            cout << " |" << endl;
        }

        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }

        cout << "+----------------------------------------------------+" << endl;
    }

    void CalorieList::init(int size)
    {
        if (size < 1)
        {
            m_itemsAdded = 0;
            m_noOfItems = 0;
        }

        else
        {
            m_itemsAdded = 0;
            m_noOfItems = size;
            m_items = new Food[m_noOfItems];
            for (int d = 0; d < m_noOfItems; d++)
                m_items[d].setEmpty();
        }
    }

    bool CalorieList::add(const char *item_name, int calories, int when)
    {
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, calories, when);
            m_itemsAdded++;
            return true;
        }
        return false;
    }

    void CalorieList::display() const
    {
        Title();
        for (int d = 0; d < m_noOfItems; d++)
        {
            m_items[d].display();
        }
        footer();
    }
    
    void CalorieList::deallocate()
    {
        delete[] m_items;
    }
} // namespace sdds