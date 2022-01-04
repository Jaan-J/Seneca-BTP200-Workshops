// Workshop 7
// Date: 2021/3/20
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <iostream>
#include "cstring.h"
#include "Truck.h"
#include "MotorVehicle.h"

using namespace std;

namespace sdds
{
	Truck::Truck(const char *lisencePlate, int year, double capacity, const char *add): MotorVehicle(lisencePlate, year)
	{
		m_kgCapacity = capacity;
		m_cargoLoad = 0;
		moveTo(add);
	}

	bool Truck::addCargo(double cargo)
	{
		bool flag;
		if (m_kgCapacity != m_cargoLoad && cargo != 0)
		{
			if (m_cargoLoad + cargo <= m_kgCapacity)
				m_cargoLoad += cargo;
			else
				m_cargoLoad = m_kgCapacity;
			flag = true;
		}
		else
			flag = false;

		return flag;
	}

	bool Truck::unloadCargo()
	{
		bool flag;
		if (m_cargoLoad == 0)
			flag = false;
		else
			flag = true;

		m_cargoLoad = 0;

		return flag;
	}

	ostream &Truck::write(ostream &os)
	{
		MotorVehicle::write(os);
		os << " | " << m_cargoLoad << "/" << m_kgCapacity;
		return os;
	}

	istream &Truck::read(istream &in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_kgCapacity;
		cout << "Cargo: ";
		in >> m_cargoLoad;
		return in;
	}

	istream &operator>>(istream &is, Truck &T)
	{
		T.read(is);
		return is;
	}

	ostream &operator<<(ostream &os, Truck &T)
	{
		T.write(os);
		return os;
	}
}