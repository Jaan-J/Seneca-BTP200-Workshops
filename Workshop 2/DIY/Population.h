// Name: Jaan Javed
// Student ID: 100131192
// Workshop 2: DIY
// Date: Jan 31, 2021
// All work is my own
//////////////////////////////////////////////////
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_


namespace sdds 
{
  	  struct PopulationPC {
     	       char* pCode;
      	      int Population;
      	  };
	
    	void sort();
	bool load(const char filename[]);
    	bool load(PopulationPC& pcPopulation);

	void display();
   	void display(const PopulationPC& pcPopulation);

	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_