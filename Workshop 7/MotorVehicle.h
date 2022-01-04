// Workshop 7
// Date: 2021/3/20
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

namespace sdds
{
	class MotorVehicle
	{
		char m_licPlate[8];
		char m_vehicleAdd[64];
		int m_prodYear;

	public:
		MotorVehicle();
		MotorVehicle(const char *plate, int year);
		void moveTo(const char *address);
		std::ostream &write(std::ostream &os);
		std::istream &read(std::istream &in);
	};
	std::istream &operator>>(std::istream &is, MotorVehicle &M);
	std::ostream &operator<<(std::ostream &os, MotorVehicle M);
}

#endif // !SDDS_MOTORVEHICLE_H
