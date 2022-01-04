// Workshop 5: Lab
// Date: 2021/2/18
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_num;
      double m_bal; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      bool isInvalid();
      bool operator ~() const;  
      operator bool() const;   
      operator int() const;   
      operator double() const;   
      Account& operator <<(Account& acc);   
      Account& operator >>(Account& acc);    
      Account& operator =(Account& acc);
      Account& operator +=(double val);    
      Account& operator -=(double val);    
      Account& operator =(int num);   
    };

    double operator +(const Account& acc1, const Account& acc2);
    double operator +=(double& val, const Account& acc);

}
#endif // SDDS_ACCOUNT_H_