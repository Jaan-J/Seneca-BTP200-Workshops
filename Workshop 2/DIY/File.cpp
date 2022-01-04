// Name: Jaan Javed
// Student ID: 100131192
// Workshop 2: DIY
// Date: Jan 31, 2021
// All work is my own
//////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(int &population)
	{
		bool complete = fscanf(fptr, "%d\n", &population);
		return complete;
	}

   bool read(char* Postal_Code)
	{
		bool complete = fscanf(fptr, "%3s,", Postal_Code);
		return complete;
	}
}