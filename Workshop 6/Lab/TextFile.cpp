// Workshop 6: Lab
// Date: 2021/3/11
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    Line::Line(){
        m_value = nullptr;
    }

    Line::~Line(){
        if (m_value != nullptr)
            delete[] m_value;
    }

    Line &Line::operator=(const char *lineContent){
        if (m_value != nullptr)
            delete[] m_value;
        m_value = new char[strLen(lineContent) + 1];
        strCpy(m_value, lineContent);
        return *this;
    }

    Line::operator const char *() const{
        return (const char *)m_value;
    }

    void TextFile::setFilename(const char *fname, bool isCopy){
        m_filename = new char[strLen(fname) + 3];
        if (isCopy)
        {
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }

        else
        {
            strCpy(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines(){
        ifstream fin(m_filename);
        char characters;
        while (fin >> noskipws >> characters)
        {
            if (characters == '\n')
                m_noOfLines++;
        }

        fin.close();
        if (m_noOfLines == 0)
        {
            m_filename = nullptr;
        }

        else
            m_noOfLines++;
    }

    void TextFile::loadText(){
        if (m_filename != nullptr)
        {
            m_textLines = new Line[m_noOfLines];
            ifstream file(m_filename);
            string tempLine;
            int num{0};
            while (getline(file, tempLine))
            {
                m_textLines[num] = tempLine.c_str();
                num++;
            }
            m_noOfLines = num;
            file.close();
        }
    }

    void TextFile::saveAs(const char *fileName) const{
        ofstream fout(fileName);
        for (unsigned i = 0; i < m_noOfLines; i++)
        {
            fout << m_textLines[i] << endl;
        }

        fout.close();
    }

    void TextFile::setEmpty(){
        if (m_textLines)
            delete[] m_textLines;
        m_textLines = nullptr;
        if (m_filename && strLen(m_filename) > 0)
            delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    TextFile::TextFile(unsigned pageSize){
        m_filename = nullptr;
        m_textLines = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char *filename, unsigned pageSize){
        m_filename = nullptr;
        m_textLines = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
        if (filename != nullptr)
        {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile &obj){
        m_filename = nullptr;
        m_textLines = nullptr;
        m_noOfLines = 0;
        m_pageSize = obj.m_pageSize;
        ifstream file(obj.m_filename);
        if (file.good())
        {
            setFilename(obj.m_filename, true);
            obj.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile &TextFile::operator=(const TextFile &obj){
        ifstream file1(m_filename);
        ifstream file2(obj.m_filename);
        if (file1.good() && file2.good())
        {
            m_textLines = nullptr;
            obj.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }

        return *this;
    }

    TextFile::~TextFile(){
        if (m_filename && strLen(m_filename) > 0)
            delete[] m_filename;
        delete[] m_textLines;
    }

    unsigned TextFile::lines() const{
        return m_noOfLines;
    }

    std::ostream &TextFile::view(std::ostream &ostr) const{
        if (m_textLines == nullptr || m_filename == nullptr || m_noOfLines == 0){
            return ostr;
        }
        ostr << m_filename << endl;
        for (int i = 0; m_filename[i] != '\0'; i++){
            ostr << "=";
        }
        ostr << endl;
        for (unsigned d = 0; d < m_noOfLines; d++){
            ostr << m_textLines[d] << endl;
            if ((d + 1) % m_pageSize == 0){
                ostr << "Hit ENTER to continue...";
                getchar();
            }
        }

        return ostr;
    }

    std::istream &TextFile::getFile(std::istream &istr){
        string temp;
        getline(istr, temp);
        setFilename(temp.c_str());
        setNoOfLines();
        loadText();
        return istr;
    }

    TextFile::operator bool() const
    {
        if (m_filename == nullptr || m_noOfLines == 0 || m_textLines == nullptr){
            return false;
        }

        return true;
    }


    const char *TextFile::operator[](unsigned index) const{
        if ( m_filename == nullptr || m_noOfLines == 0 || m_textLines == nullptr){
            return nullptr;
        }
        unsigned flag = 0;
        char *a = nullptr;
        for (unsigned d = 0; d <= index; d++){
            if (flag >= m_noOfLines){
                flag = 0;
            }
            a = m_textLines[flag].m_value;
            flag++;
        }

        return a;
    }

    const char *TextFile::name() const{
        return m_filename;
    }

    ostream &operator<<(ostream &ostr, const TextFile &text){
        text.view(ostr);
        return ostr;
    }

    istream &operator>>(istream &istr, TextFile &text){
        text.getFile(istr);
        return istr;
    }
}