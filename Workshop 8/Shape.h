// Workshop 8
// Date: 2021/3/25
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds
{
    class Shape
    {
    public:
        virtual void draw(std::ostream &) const = 0;
        virtual void getSpecs(std::istream &) = 0;
        virtual ~Shape(){};
    };

    std::istream &operator>>(std::istream &L, Shape &shp);
    std::ostream &operator<<(std::ostream &L, const Shape &shp);
}
#endif //!SDDS_SHAPE_H