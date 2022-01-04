// Workshop 2: Lab
// Date: 2021/1/27
// Author: Jaan Javed
// Student Numner: 100131192
/////////////////////////////////////////////
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#define DATAFILE "employees.csv"
#include "File.h"
#include "cstring.h"

namespace sdds
{
    struct Employee
    {
        char *m_name;
        int m_empNo;
        double m_salary;
    };

    void sort();

    bool load(Employee &employee);

    bool load();

    void display(const Employee &employee);

    void display();

    void deallocateMemory();
} // namespace sdds
#endif //
