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
#include "Food.h"

using namespace std;
namespace sdds
{

    void Food::setEmpty()
    {
        m_foodName[0] = '\0';
        m_calNum = 0;
        m_toConsumption = 0;
    }

    void Food::set(const char *item_name, int calories, int when)
    {
        if (calories < 0 || item_name == nullptr)
        {
            setEmpty();
        }
        else
        {
            setName(item_name);
            m_calNum = calories;
            m_toConsumption = when;
        }
    }

    void Food::setName(const char *name)
    {
        strCpy(m_foodName, name);
        m_foodName[30] = '\0';
    }

    void Food::display() const
    {
        if (isValid())
        {
            cout << "| ";
            cout.width(30);
            cout << left << setfill('.') << m_foodName;
            cout << " | ";
            cout.width(4);
            cout << left << setfill(' ');
            cout << right << m_calNum;
            cout << " | ";
            cout.width(10);
            if (m_toConsumption == 1)
                cout << left << "Breakfast";
            else if (m_toConsumption == 2)
                cout << left << "Lunch";
            else if (m_toConsumption == 3)
                cout << left << "Dinner";
            else if (m_toConsumption == 4)
                cout << left << "Snack";
            cout << right << setfill(' ');
            cout << " |" << endl;
        }

        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }

    int Food::calorie() const
    {
        return m_calNum;
    }

    bool Food::isValid() const
    {
        return m_foodName[0] != '\0' && m_toConsumption >= 1 && m_toConsumption <= 4;
    }
} // namespace sdds