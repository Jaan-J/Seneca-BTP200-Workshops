// Workshop 6: DIY
// Date: 2021/3/16
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "cstring.h"
#include "Stats.h"

using namespace std;
namespace sdds
{
	Stats::Stats(const Stats &other) : m_arr(nullptr), m_noOfStats(0), m_filename(nullptr), m_columnWidth(0), m_noOfColumns(0), m_precision(0)
	{
		ifstream file(other.m_filename);

		if (file.good())
		{
			m_noOfColumns = other.m_noOfColumns;
			m_precision = other.m_precision;
			m_columnWidth = other.m_columnWidth;
			setFilename(other.m_filename, true);
			other.saveAs(m_filename);
			loadNums();
		}
	}

	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision)
	{
		m_noOfStats = 0;
		m_filename = nullptr;
		m_columnWidth = columnWidth;
		m_noOfColumns = noOfColumns;
		m_precision = precision;
		m_arr = nullptr;
	}

	Stats::Stats(const char *filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision)
	{
		m_noOfStats = 0;
		m_columnWidth = columnWidth;
		m_noOfColumns = noOfColumns;
		m_precision = precision;
		m_filename = nullptr;
		m_arr = nullptr;

		if (filename != nullptr)
		{
			setFilename(filename);
			loadNums();
		}
	}

	Stats::~Stats()
	{
		if (m_noOfStats != 0)
			delete[] m_arr;
		if (m_filename != nullptr && strLen(m_filename) > 0)
			delete[] m_filename;
	}

	double &Stats::operator[](unsigned idx)
	{

		if (!(*this && m_noOfStats > 0))
			return dummy;
		return m_arr[idx % m_noOfStats];
	}

	double Stats::operator[](unsigned idx) const
	{

		double i = 0;
		if (*this && m_noOfStats > 0)
		{
			i = m_arr[idx % m_noOfStats];
		}

		return i;
	}

	void Stats::sort(bool ascending)
	{
		for (int i = 0; i < m_noOfStats - 1; i++)
		{
			for (int d = 0; d < m_noOfStats - i - 1; d++)
			{
				if ((ascending && m_arr[d] > m_arr[d + 1]) ||
					(!ascending && m_arr[d] < m_arr[d + 1]))
				{
					double temp = m_arr[d];
					m_arr[d] = m_arr[d + 1];
					m_arr[d + 1] = temp;
				}
			}
		}
	}

	unsigned Stats::size() const
	{
		return m_noOfStats;
	}

	const char *Stats::name() const
	{
		return m_filename;
	}

	unsigned Stats::occurrence(double min, double max, std::ostream &ostr)
	{
		unsigned counter = 0;
		if (*this)
		{
			ostr << endl;
			ostr << fixed << setprecision(m_precision);
			bool flag = false;
			for (int i = 0; i < m_noOfStats; i++)
			{
				if (m_arr[i] >= min && m_arr[i] <= max)
				{
					flag = false;
					ostr << right << setw(m_columnWidth) << m_arr[i];
					if ((counter + 1) % m_noOfColumns == 0)
					{
						flag = true;
						ostr << endl;
					}

					counter++;
				}
			}

			if (!flag)
				ostr << endl;
			ostr << "Total of " << counter << " numbers are between " << min << " and " << max << endl;
		}

		return counter;
	}

	Stats &Stats::operator=(Stats &other)
	{
		ifstream file1(m_filename);
		ifstream file2(other.m_filename);

		if (file1.good() && file2.good())
		{

			m_noOfColumns = other.m_noOfColumns;
			m_precision = other.m_precision;
			m_columnWidth = other.m_columnWidth;
			other.saveAs(m_filename);
			delete[] m_arr;
			delete[] other.m_arr;
			m_noOfStats = 0;
			other.m_noOfStats = 0;
			loadNums();
		}

		return *this;
	}

	Stats::operator bool() const
	{
		if (m_noOfStats == 0 || m_filename == nullptr)
		{
			return false;
		}

		return true;
	}

	void Stats::setFilename(const char *fname, bool isCopy)
	{
		delete [] m_filename; 
		m_filename = nullptr;
		m_filename = new char[strLen(fname) + 3];
		if (!isCopy)
			strCpy(m_filename, fname);
		else
		{
			strCpy(m_filename, "C_");
			strCat(m_filename, fname);
		}
	}

	void Stats::loadNums()
	{
		m_noOfStats = 0;
		ifstream file(m_filename);

		if (file.good())
		{
			string line;
			getline(file, line);
			stringstream ss(line);
			double a;
			string num;

			while (getline(ss, num, ','))
			{
				m_noOfStats++;
			}

			m_arr = new double[m_noOfStats];
			stringstream ss2(line);
			int idex = 0;
			while (getline(ss2, num, ','))
			{
				a = stod(num);
				m_arr[idex] = a;
				idex++;
			}

			file.close();
		}
	}

	void Stats::saveAs(const char *fileName) const
	{
		ofstream fout(fileName);
		ifstream fin(m_filename);
		string line;

		while (getline(fin, line))
		{
			fout << line;
		}

		fin.close();
		fout.close();
	}

	std::ostream &Stats::view(std::ostream &ostr) const
	{
		if (m_filename == nullptr || m_arr == nullptr || m_noOfStats == 0)
		{
			return ostr;
		}

		ostr << m_filename << endl;
		for (int i = 0; m_filename[i] != '\0'; i++)
		{
			ostr << "=";
		}

		bool flag = false;
		ostr << endl
			 << endl;
		ostr << fixed << setprecision(m_precision);

		for (int i = 0; i < m_noOfStats; i++)
		{
			ostr << right << setw(m_columnWidth) << m_arr[i];
			flag = false;
			if ((i + 1) % m_noOfColumns == 0)
			{
				flag = true;
				ostr << endl;
			}
		}

		if (!flag)
			ostr << endl;
		ostr << "Total of " << m_noOfStats << " listed!" << endl;
		return ostr;
	}

	std::istream &Stats::getFile(std::istream &istr)
	{
		string tmp;
		getline(istr, tmp);
		setFilename(tmp.c_str());
		loadNums();
		return istr;
	}

	std::ostream &operator<<(std::ostream &ostr, const Stats &text)
	{
		text.view(ostr);
		return ostr;
	}

	std::istream &operator>>(std::istream &istr, Stats &text)
	{
		return text.getFile(istr);
	}
}