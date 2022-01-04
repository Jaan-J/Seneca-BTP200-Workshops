// Workshop 8
// Date: 2021/3/25
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <cstring>
#include "Shape.h"

using namespace std;

namespace sdds
{
	ostream &operator<<(ostream &L, const Shape &shp)
	{
		shp.draw(L);
		return L;
	}

	istream &operator>>(istream &L, Shape &shp)
	{
		shp.getSpecs(L);
		return L;
	}
}