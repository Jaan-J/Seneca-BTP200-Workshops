// Workshop 3: Lab
// Date: Feb 4, 2021
// Author: Jaan Javed
// Student ID: 100131192
// I have done all the coding by myself and only
// copied the code that my professor provided
// to complete my workshops and assignments.
/////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "Item.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
	const double taxPercentage = 0.13;

	void Item::setEmpty()
	{
		m_itemName[0] = '\0';
		m_taxed = true;
		m_price = 0.0;
	}

	void Item::set(const char *name, double price, bool taxed)
	{
		if (name == NULL || price < 0)
			setEmpty();
		else
		{
			m_price = price;
			m_taxed = taxed;
			setName(name);
		}
	}

	double Item::price() const
	{
		return m_price;
	}

	double Item::tax() const
	{
		if (m_taxed == true)
			return m_price * taxPercentage;
		else
			return 0.0;
	}

	bool Item::isValid() const
	{
		return !(m_itemName[0] == '\0' && m_price == 0.00);
	}

	void Item::display() const
	{
		if (isValid())
		{
			cout << "| ";
			cout.fill('.');
			cout.width(20);
			cout.setf(ios::left);
			cout << m_itemName;
			cout.unsetf(ios::left);
			cout << " | ";
			cout.precision(2);
			cout.fill(' ');
			cout.width(7);
			cout.setf(ios::fixed);
			cout << m_price;
			cout << " | ";

			if (m_taxed == true)
				cout << "Yes";
			else
				cout << "No ";
				cout << " |" << endl;
		}
		else
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
	}

	void Item::setName(const char *name)
	{
		m_itemName[20] = char(0);
		strnCpy(m_itemName, name, 20);
	}

} // namespace sdds