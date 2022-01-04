// Workshop 5: DIY
// Date: 2021/2/21
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include "Mark.h"
#include "cstring.h"

using namespace std;

namespace sdds
{

	Mark &Mark::operator=(int val)
	{
		if (val <= 100 && val >= 0 )
			m_mark = val;
		else
			m_mark = 0;
		return *this;
	}

	Mark &Mark::operator+=(int val)
	{
		if (m_mark != -1 && val > 0 && m_mark + val <= 100)
			m_mark += val;
		else
			m_mark = 0;
		return *this;
	}

	Mark::Mark()
	{
		m_mark = 0;
	}

	Mark::Mark(int mark)
	{
		if (mark >= 0 && mark <= 100 )
			m_mark = mark;
		else
			m_mark = -1;
	}

	Mark::operator int()
	{
		if (m_mark == -1)
			return 0;
		else
			return m_mark;
	}

	Mark::operator char()
	{
		if (m_mark < 50 && m_mark > 0)
			return 'F';
		else if (m_mark < 60 && m_mark >= 50)
			return 'D';
		else if (m_mark < 70 && m_mark >= 60)
			return 'C';
		else if (m_mark >= 70 && m_mark < 80)
			return 'B';
		else if (m_mark >= 80 && m_mark <= 100)
			return 'A';
		else
			return 'X';
	}

	Mark::operator double()
	{
		if (m_mark > 0 && m_mark < 50)
			return 0.0;
		else if (m_mark >= 50 && m_mark < 60)
			return 1.0;
		else if (m_mark >= 60 && m_mark < 70)
			return 2.0;
		else if (m_mark >= 70 && m_mark < 80)
			return 3.0;
		else if (m_mark >= 80 && m_mark <= 100)
			return 4.0;
		else
			return 0.0;
	}

	int &operator+=(int &val, Mark &mark)
	{
		if (int(mark) != -1)
			val += int(mark);
		return val;
	}
}