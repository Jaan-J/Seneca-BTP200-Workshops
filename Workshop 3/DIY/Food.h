// Workshop 3: DIY
// Date: Feb 7, 2021
// Author: Jaan Javed
// Student ID: 100131192
// I have done all the coding by myself and only
// copied the code that my professor provided
// to complete my workshops and assignments.
/////////////////////////////////////////////////

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

namespace sdds
{
    class Food 
    {
        char m_foodName[31];
        int m_calNum;
        int m_toConsumption;
        void setName(const char* name);

    public:
        void setEmpty();
        void set(const char* item_name, int calories, int when);
        int calorie()const;
        bool isValid()const;
        void display()const;
    };
}

#endif 