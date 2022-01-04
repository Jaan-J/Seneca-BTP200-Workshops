// Workshop 8
// Date: 2021/3/25
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include <iostream>
#include "Shape.h"

namespace sdds
{
    class LblShape : public Shape
    {
        char *m_label = nullptr;

    protected:
        char *label() const;

    public:
        LblShape();
        LblShape(const char *);
        LblShape(const LblShape &) = delete;
        virtual ~LblShape();
        void getSpecs(std::istream &);
        void operator=(const LblShape &) = delete;
        virtual void draw(std::ostream &) const = 0;
    };
}
#endif //!SDDS_LBLSHAPE_H