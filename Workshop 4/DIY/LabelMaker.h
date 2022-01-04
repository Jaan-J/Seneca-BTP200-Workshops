// Workshop 4: DIY
// Date: 2021/2/14
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_LABELMAKERH
#define SDDS_LABELMAKERH
#include "Label.h"

namespace sdds 
{
   class LabelMaker 
   {
      Label* labels;
      int noOfLabels;

   public:
        void readLabels();
        void printLabels();
        
        LabelMaker(int numLabels);
        ~LabelMaker();
   };
}
#endif //!SDDS_LABELMAKERH