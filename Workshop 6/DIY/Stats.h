// Workshop 6: DIY
// Date: 2021/3/16
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////

#ifndef SDDS_STATS_H__
#define SDDS_STATS_H__
#include <iostream>

namespace sdds
{

    class Stats
    {
        double *m_arr;
        int m_noOfStats;
        char *m_filename;
        unsigned m_columnWidth;
        unsigned m_noOfColumns;
        unsigned m_precision;
        double dummy = 0;

    public:
        Stats(const Stats &);
        Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
        Stats(const char *filename, unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
        ~Stats();
        double &operator[](unsigned idx);
        double operator[](unsigned idx) const;
        void sort(bool ascending);
        unsigned size() const;
        const char *name() const;
        unsigned occurrence(double min, double max, std::ostream &ostr = std::cout);
        Stats &operator=(Stats &);
        operator bool() const;
        void setFilename(const char *fname, bool isCopy = false);
        void loadNums();
        void saveAs(const char *fileName) const;
        std::ostream &view(std::ostream &ostr) const;
        std::istream &getFile(std::istream &istr);
    };

    std::ostream &operator<<(std::ostream &ostr, const Stats &text);
    std::istream &operator>>(std::istream &istr, Stats &text);
}
#endif