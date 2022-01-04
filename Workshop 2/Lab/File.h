// Workshop 2: Lab
// Date: 2021/1/27
// Author: Jaan Javed
// Student Numner: 100131192
/////////////////////////////////////////////
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

#include <cstdio>

namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();

	bool read(char* emp_Name);
	bool read(int& emp_Num);
	bool read(double& emp_Sal);
}
#endif // !SDDS_FILE_H_
