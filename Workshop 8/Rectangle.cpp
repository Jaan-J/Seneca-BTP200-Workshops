// Workshop 8
// Date: 2021/3/25
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <cstring>
#include <iomanip>
#include <iostream>
#include "Rectangle.h"

using namespace std;

namespace sdds
{
    Rectangle::Rectangle()
    {
        m_height = 0;
        m_width = 0;
    }

    Rectangle::Rectangle(const char *label, int width, int height) : LblShape(label)
    {
        m_width = width;
        m_height = height;

        if (m_height < 3 || m_width < ((int)strlen(LblShape::label()) + 2))
        {
            m_width = 0;
            m_height = 0;
        }
    }

    void Rectangle::getSpecs(std::istream &is)
    {
        LblShape::getSpecs(is);

        is >> m_width;
        is.ignore();

        is >> m_height;
        is.ignore(500, '\n');
    }

    void Rectangle::draw(std::ostream &os) const
    {
        if (m_width > 0 && m_height > 0)
        {
            os << '+';

            for (int i = 0; i < m_width - 2; i++)
            {
                os << '-';
            }

            os << '+' << endl;

            os << '|';
            os << left << setw(m_width - 2) << LblShape::label();
            os << '|' << endl;

            for (int i = 0; i < m_height - 3; i++)
            {
                os << '|';

                for (int i = 0; i < m_width - 2; i++)
                {
                    os << ' ';
                }

                os << '|' << endl;
            }

            os << '+';

            for (int i = 0; i < m_width - 2; i++)
            {
                os << '-';
            }

            os << '+';
        }
    }
}