// Workshop 6: Lab
// Date: 2021/3/11
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////

#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds
{
    class Text;
    class Line
    {
        char *m_value{nullptr};
        Line();
        ~Line();
        operator const char *() const;
        Line &operator=(const char *);
        friend class TextFile;
    };

    class TextFile
    {
        Line *m_textLines;
        char *m_filename;
        unsigned m_noOfLines;
        unsigned m_pageSize;
        void setFilename(const char *fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char *fileName) const;
        void setEmpty();

    public:
        TextFile(unsigned pageSize = 15);
        TextFile(const char *filename, unsigned pageSize = 15);
        TextFile(const TextFile &);
        TextFile &operator=(const TextFile &);
        ~TextFile();
        std::ostream &view(std::ostream &ostr) const;
        std::istream &getFile(std::istream &istr);
        operator bool() const;
        unsigned lines() const;
        const char *name() const;
        const char *operator[](unsigned index) const;
    };
    std::ostream &operator<<(std::ostream &ostr, const TextFile &text);
    std::istream &operator>>(std::istream &istr, TextFile &text);

}
#endif // !SDDS_TEXTFILE_H__