// Workshop 5: DIY
// Date: 2021/2/21
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds {
	class Mark {
		int m_mark;
	public:
		Mark& operator=(int val);
		Mark& operator+=(int val);
		Mark();
		Mark(int mark);
		operator int();
		operator char();
		operator double();
	};
	int& operator+=(int& val, Mark& mark);
}

#endif // !SDDS_MARK_H
