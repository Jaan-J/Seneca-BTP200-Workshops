// Workshop 2: Lab
// Date: 2021/1/27
// Author: Jaan Javed
// Student Numner: 100131192
/////////////////////////////////////////////

#include "Employee.h"
using namespace sdds;
int main() {
   if (load()) {
      display();
   }
   deallocateMemory();
   return 0;
}