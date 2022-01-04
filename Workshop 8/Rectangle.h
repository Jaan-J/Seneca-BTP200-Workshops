// Workshop 8
// Date: 2021/3/25
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include <iostream>
#include "LblShape.h"

namespace sdds
{
    class Rectangle : public LblShape
    {
        int m_width;
        int m_height;

    public:
        Rectangle();
        Rectangle(const char *, int, int);
        ~Rectangle(){};
        void getSpecs(std::istream &);
        void draw(std::ostream &) const;
    };
}
#endif //!SDDS_RECTANGLE_H