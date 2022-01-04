// Name: Jaan Javed
// Student ID: 100131192
// Workshop 2: DIY
// Date: Jan 31, 2021
// All work is my own
//////////////////////////////////////////////////
#include <iostream>
#include "Population.h"
#include "File.h"

using namespace std;

namespace sdds
{
	int popSum;
	int pcNum;
	PopulationPC *pcPopulation;

	int strLen(const char *s)
	{
		int i = -1;
		while (s[++i])
			;
		return i;
	}

	void strCpy(char *dest, const char *src)
	{
		while (*src)
		{
			*dest++ = *src++;
		}
		*dest = 0;
	}

	bool load(const char filename[])
	{
		bool flag = false;

		if (openFile(filename))
		{

			pcNum = noOfRecords();
			pcPopulation = new PopulationPC[pcNum]{};

			for (int x = 0; x < pcNum; x++)
			{

				if (!load(pcPopulation[x]))
				{

					cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
					closeFile();
					return false;
				}
			}
			closeFile();
			flag = true;
		}
		else
		{
			cout << "Could not open data file: " << filename << endl;
		}
		return flag;
	}



	bool load(PopulationPC &pcPopulation)
	{

		bool flag = false;

		char postalCode[25] = {'\0'};

		if (read(postalCode))
		{

			if (read(pcPopulation.Population))
			{

				pcPopulation.pCode = new char[strLen(postalCode) + 1];
				strCpy(pcPopulation.pCode, postalCode);
				popSum+= pcPopulation.Population;
				flag = true;
			}
		}
		return flag;
	}

	
	void sort()
	{
		PopulationPC temporary;

		for (int d = pcNum - 1; d > 0; d--)
		{

			for (int i = 0; i < d; i++)
			{

				if (pcPopulation[i].Population > pcPopulation[i + 1].Population)
				{

					temporary = pcPopulation[i];

					pcPopulation[i] = pcPopulation[i + 1];

					pcPopulation[i + 1] = temporary;
				}
			}
		}
	}

	void display()
	{
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;

		sort();

		for (int number = 0; number < pcNum; ++number)
		{

			cout << number + 1 << "- ";
			display(pcPopulation[number]);
		}

		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << popSum << endl;
	}

	void display(const PopulationPC &pcPopulation)
	{
		cout << pcPopulation.pCode << ":  " << pcPopulation.Population << endl;
	}

	void deallocateMemory()
	{
		for (int d = 0; d < pcNum; d++)
		{
		}
	}

} // namespace sdds