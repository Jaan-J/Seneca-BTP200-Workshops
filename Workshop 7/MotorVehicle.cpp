// Workshop 7
// Date: 2021/3/20
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <iostream>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
	MotorVehicle::MotorVehicle()
	{
		m_prodYear = 0;
		m_licPlate[0] = '\0';
		m_vehicleAdd[0] = '\0';
	}

	MotorVehicle::MotorVehicle(const char *plate, int year)
	{
		strCpy(m_licPlate, plate);
		m_prodYear = year;
		strCpy(m_vehicleAdd, "Factory");
	}

	void MotorVehicle::moveTo(const char *address)
	{
		if (strCmp(m_vehicleAdd, address) != 0)
		{

			cout << "|";
			cout.setf(ios::right);
			cout.width(8);
			cout << m_licPlate;
			cout.unsetf(ios::right);
			cout << "| |";
			cout.setf(ios::right);
			cout.width(20);
			cout << m_vehicleAdd;
			cout.unsetf(ios::right);
			cout << " ---> ";
			cout.setf(ios::left);
			cout.width(20);
			cout << address;
			cout.unsetf(ios::left);
			cout << "|" << endl;
			strCpy(m_vehicleAdd, address);
		}
	}

	ostream &MotorVehicle::write(ostream &os)
	{
		os << "| " << m_prodYear << " | " << m_licPlate << " | " << m_vehicleAdd;
		return os;
	}

	istream &MotorVehicle::read(istream &in)
	{
		cout << "Built year: ";
		in >> m_prodYear;
		cout << "License plate: ";
		in >> m_licPlate;
		cout << "Current location: ";
		in >> m_vehicleAdd;
		return in;
	}

	istream &operator>>(istream &is, MotorVehicle &M)
	{
		M.read(is);
		return is;
	}

	ostream &operator<<(ostream &os, MotorVehicle M)
	{
		M.write(os);
		return os;
	}
}