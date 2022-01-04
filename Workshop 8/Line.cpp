// Workshop 8
// Date: 2021/3/25
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <cstring>
#include "Line.h"

using namespace std;

namespace sdds
{
    Line::Line()
    {
        m_length = 0;
    }

    Line::Line(const char *label, int length) : LblShape(label)
    {
        m_length = length;
    }

    void Line::getSpecs(std::istream &is)
    {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(500, '\n');
    }

    void Line::draw(std::ostream &os) const
    {
        if (LblShape::label() != nullptr && m_length > 0)
        {
            os << LblShape::label() << endl;
            for (int i = 0; i < m_length; i++)
                os << "=";
        }
    }
}