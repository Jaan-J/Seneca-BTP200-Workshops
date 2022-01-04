// Name: Jaan Javed
// Student ID: 100131192
// Workshop 2: DIY
// Date: Jan 31, 2021
// All work is my own
//////////////////////////////////////////////////
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   bool read(char* Postal_Code);
   bool read(int &population); 
}
#endif // !SDDS_FILE_H_