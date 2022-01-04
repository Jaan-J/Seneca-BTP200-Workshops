// Workshop 4: Lab
// Date: 2021/2/11
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h" 
#include "Canister.h"
#include <istream>
#include <iomanip>
#include <cstring>
using namespace std;
namespace sdds {

	double mathPi = 3.14159265;

	void Canister::setToDefault()
	{
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentName = nullptr;
		m_contentVolume = 0;
		m_usable = true;
	}

	bool Canister::isEmpty()const
	{
		if (m_contentVolume < 0.00001)
			return true;
		else
			return false;
	}

	bool Canister::hasSameContent(const Canister& C)const
	{
		if (strCmp(this->m_contentName, C.m_contentName) == 0 && this->m_contentName != nullptr && C.m_contentName != nullptr)
			return true;
		else
			return false;
	}

	void Canister::setName(const char* Cstr)
	{
		if (m_usable == true && Cstr != nullptr)
		{
			delete [] m_contentName;
			m_contentName = new char[strLen(Cstr) + 1];
			strCpy(m_contentName, Cstr);
		}

	}




	Canister::Canister()
	{
		setToDefault();
	}

	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName)
	{
		if ( diameter <= 30 && diameter >= 10 && height <= 40 && height >= 10)
		{
			setToDefault();
			m_diameter = diameter;
			m_height = height;
			setName(contentName);
		}
		else
		{
			setToDefault();
			m_usable = false;
		}
	}

	void Canister::clear()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	double Canister::capacity()const
	{
		return mathPi * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}

	double Canister::volume()const
	{
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName)
	{
		if (contentName == nullptr)
			m_usable = false;
		else if (isEmpty())
			setName(contentName);
		else if (strcmp(contentName, m_contentName) != 0)
			m_usable = false;

		return *this;
	}

	Canister& Canister::pour(double quantity)
	{
		if ( quantity + volume() <= capacity() && m_usable == true && quantity > 0)
		{
			m_contentVolume += quantity;
		}
		else
			m_usable = false;

		return *this;
	}

	Canister& Canister::pour(Canister& C)
	{
		setContent(C.m_contentName);
		if (C.volume() > capacity() - volume())
		{
			C.m_contentVolume -= capacity() - volume();
			m_contentVolume = capacity();
		}
		else
		{
			pour(C.volume());
			C.m_contentVolume = 0.0;
		}

		return *this;
	}

	std::ostream& Canister::display()const
	{
		cout.setf(ios::fixed);
		cout.precision(1);
		cout.width(7);
		cout << capacity() << "cc (" << this->m_height << "x" << this->m_diameter << ") Canister";

		if (m_usable == false)
			cout << " of Unusable content, discard!";
		else if (m_contentName != nullptr)
		{
			cout << " of ";
			cout.width(7);
			cout << volume() << "cc   " << this->m_contentName;
		}
		return cout;
	}

	Canister::~Canister()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
	}

}