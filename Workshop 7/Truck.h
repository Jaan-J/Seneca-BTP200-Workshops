// Workshop 7
// Date: 2021/3/20
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include "MotorVehicle.h"

namespace sdds
{
	class Truck : public MotorVehicle
	{
		double m_kgCapacity;
		double m_cargoLoad;

	public:
		Truck(const char *lisencePlate, int year, double capacity, const char *add);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream &write(std::ostream &os);
		std::istream &read(std::istream &in);
	};
	std::istream &operator>>(std::istream &is, Truck &T);
	std::ostream &operator<<(std::ostream &os, Truck &T);
}
#endif // !SDDS_TRUCK_H
