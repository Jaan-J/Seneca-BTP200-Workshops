// Workshop 8
// Date: 2021/3/25
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds
{
    char *LblShape::label() const
    {
        return m_label;
    }

    LblShape::LblShape()
    {
        if (m_label != nullptr)
        {
            m_label = nullptr;
        }
    }

    LblShape::LblShape(const char *label)
    {
        int len;
        len = strlen(label);
        m_label = new char[len + 1];
        strcpy(m_label, label);
        m_label[len] = '\0';
    }

    LblShape::~LblShape()
    {
        delete[] m_label;
    }

    void LblShape::getSpecs(std::istream &istr)
    {
        string str;
        int len;
        getline(istr, str, ',');
        len = str.length();

        if (m_label != nullptr)
        {
            delete[] m_label;
        }

        m_label = new char[len + 1];
        strcpy(m_label, str.c_str());
        m_label[len] = '\0';
    }
}