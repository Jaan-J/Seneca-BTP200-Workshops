// Workshop 2: Lab
// Date: 2021/1/27
// Author: Jaan Javed
// Student Numner: 100131192
/////////////////////////////////////////////
#include <iostream>
#include "Employee.h"
#include "cstring.h"
#include "File.h"

using namespace std;

namespace sdds
{

    int noOfEmployees;
    Employee *employees;

    void sort()
    {
        int i = 0, j = 0;
        Employee temp = {};
        for (i = noOfEmployees - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (employees[j].m_empNo > employees[j + 1].m_empNo)
                {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    bool load(Employee &EMP)
    {
        bool ok = false;
        char name[128] = {'\0'};

        if (read(EMP.m_empNo))
        {
            if (read(EMP.m_salary))
            {
                if (read(name))
                {
                    int len = strLen(name);
                    EMP.m_name = new char[len + 1];
                    strCpy(EMP.m_name, name);
                    ok = true;
                }
            }
        }

        return ok;
    }

    bool load()
    {
        bool ok = false;
        if (openFile(DATAFILE))
        {
            noOfEmployees = noOfRecords() + 1;
            employees = new Employee[noOfEmployees]{};
            for (int d = 0; d < noOfEmployees; d++)
            {
                if (!load(employees[d]))
                {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
                    closeFile();
                    return false;
                }
            }
            ok = true;
            closeFile();
        }
        else
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    void display(const Employee &employee)
    {
        cout << employee.m_empNo << ": " << employee.m_name << ", " << employee.m_salary << endl;
    }

    void display()
    {
        sort();
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        int i = 0, d = 0;
        for (i = 0; i < noOfEmployees; i++)
        {
            if (employees[i].m_name[0] != '\0')
            {
                cout << i + 1 + d << "- ";
                display(employees[i]);
            }
            else
            {
                d--;
            }
        }
    }

    void deallocateMemory()
    {
        for (int d = 0; d < noOfEmployees; d++)
        {
            delete[] employees[d].m_name;
        }
        delete[] employees;
    }

} // namespace sdds
