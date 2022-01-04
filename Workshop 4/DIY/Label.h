// Workshop 4: DIY
// Date: 2021/2/14
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>

namespace sdds 
{
   class Label 
   {
        char* frame;
        char* m_Content;

        void printLine() const;
        void setFrame(const char* val);
        void setContent(const char* val);

   public:
        void readLabel();
        std::ostream& printLabel()const;

        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);

        ~Label();
   };
}

#endif //!SDDS_LABEL_H