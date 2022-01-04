// Workshop 4: DIY
// Date: 2021/2/14
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "Label.h"
#include <istream>
#include <iomanip>

using namespace std;
namespace sdds 
{
    void Label::readLabel()
    {
        m_Content = new char[71]; 
        cin.getline(m_Content, 71);
    }

    void Label::printLine() const
    {
        int i = 0;
        while(m_Content[i])
        {
            cout << " ";
            i++;
        }
        cout << "  ";
    }

       void Label::setFrame(const char* val)
    {
        if(val != nullptr)
        {
            int i;
            i = strLen(val);
            frame = new char[i + 1];
            strCpy(frame, val);
        }
    }


    void Label::setContent(const char* val)
    {
        if(val != nullptr)
        {
            int i;
            i = strLen(val);
            m_Content = new char[i + 1];
            strCpy(m_Content, val);
        }
    }

    Label::Label()
    {
        m_Content = nullptr;
        frame = new char[9];
        strCpy(frame, "+-+|+-+|");
    }


    Label::Label(const char* frameArg)
    {
        m_Content = nullptr;
        setFrame(frameArg);
    }


    Label::Label(const char* frameArg, const char* content)
    {
        setContent(content);
        setFrame(frameArg);
    }

    std::ostream& Label::printLabel() const
    {
        if( m_Content != nullptr && strLen(m_Content) > 0)
        {
            cout << frame[0];
            for(int i = 0; i<strLen(m_Content)+2; i++)
            {
                cout << frame[1];
            }
            cout << frame[2] << endl;
            cout << frame[7];
                printLine();
            cout << frame[3] << endl;
            cout << frame[7];
                cout << " " << m_Content << " ";
            cout << frame[3] << endl;
            cout << frame[7];
                printLine();
            cout << frame[3] << endl;
            cout << frame[6];
            int i;
            for(i = 0; i < strLen(m_Content) + 2; i++)
            {
                cout << frame[5];
            }
            cout << frame[4];
        } return cout;
    }  

    Label::~Label()
    {
	delete[] frame;
	delete[] m_Content;
	frame = nullptr;
        	m_Content = nullptr;
    }

}