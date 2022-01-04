// Workshop 2: Lab
// Date: 2021/1/27
// Author: Jaan Javed
// Student Numner: 100131192
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
    FILE *fptr;
    bool openFile(const char filename[])
    {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords()
    {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1)
        {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile()
    {
        if (fptr)
            fclose(fptr);
    }

    bool read(char *emp_Name)
    {
        if (fscanf(fptr, "%[^\n]\n", emp_Name) != 0)
        {
            return 1;
        }
        return 0;
    }

    bool read(int &emp_Num)
    {
        if (fscanf(fptr, "%d,", &emp_Num) != 0)
        {
            return 1;
        }
        return 0;
    }

    bool read(double &emp_Salary)
    {
        if (fscanf(fptr, "%lf,", &emp_Salary) != 0)
        {
            return 1;
        }
        return 0;
    }
} // namespace sdds
