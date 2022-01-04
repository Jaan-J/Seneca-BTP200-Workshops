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
#include "Bill.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
	double Bill::totalTax() const
	{
		double totSum = 0.00;
		for (int i = 0; i < m_noOfItems; ++i)
			totSum += m_items[i].tax();
		return totSum;
	}

	double Bill::totalPrice() const
	{
		double totSum = 0.00;
		for (int i = 0; i < m_noOfItems; ++i)
			totSum += m_items[i].price();
		return totSum;
	}

	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid() const
	{
		bool flag = false;

		if (m_title[0] != '\0' && m_items != NULL)
		{
			for (int i = 0; i < m_noOfItems; ++i)
			{
				if (!(m_items[i].isValid()))
				{
					return flag;
				}
			}
			flag = true;
		}

		return flag;
	}

	void Bill::Title() const
	{
		cout << "+--------------------------------------+" << endl;
		if (isValid())
		{
			cout << "| ";
			cout.fill(' ');
			cout.width(36);
			cout.setf(ios::left);
			cout << m_title;
			cout.unsetf(ios::left);
			cout << " |" << endl;
		}
		else
			cout << "| Invalid Bill                         |" << endl;
			cout << "+----------------------+---------+-----+" << endl;
			cout << "| Item Name            | Price   + Tax |" << endl;
			cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer() const
	{
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid())
		{
			cout << "|                Total Tax: " << setfill(' ') << setw(10) << totalTax() << " |" << endl;
			cout << "|              Total Price: " << setfill(' ') << setw(10) << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: " << setfill(' ') << setw(10) << totalPrice() + totalTax() << " |" << endl;
		}
		else
			cout << "| Invalid Bill                         |" << endl;
			cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char *title, int noOfItems)
	{
		if (title[0] == '\0' || noOfItems <= 0)
		{
			setEmpty();
		}
		else
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[noOfItems];
			for (int i = 0; i < noOfItems; ++i)
				m_items[i].setEmpty();
		}
	}

	bool Bill::add(const char *item_name, double price, bool taxed)
	{
		if (m_itemsAdded < m_noOfItems)
		{
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			return true;
		}
		else
			return false;
	}

	void Bill::display() const
	{
		Title();
		for (int d = 0; d < m_noOfItems; ++d)
		{
			m_items[d].display();
		}
		footer();
	}

	void Bill::deallocate()
	{
		for (int d = 0; d < m_noOfItems; ++d)
		{
			delete[] m_items;
			m_items = nullptr;
		}
	}

} // namespace sdds
