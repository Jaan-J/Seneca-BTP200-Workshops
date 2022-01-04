// Workshop 8
// Date: 2021/3/25
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include <iostream>
#include "LblShape.h"

namespace sdds
{
    class Line : public LblShape
    {
        int m_length;

    protected:
        char *label();

    public:
        Line();
        Line(const char *, int);
        ~Line(){};
        void getSpecs(std::istream &);
        void draw(std::ostream &) const;
    };
}
#endif //!SDDS_LINE_H