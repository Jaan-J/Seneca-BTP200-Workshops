// Workshop 5: Lab
// Date: 2021/2/18
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
   void Account::setEmpty()
   {
      m_num = -1;
      m_bal = 0.0;
   }

   Account::Account()
   {  
      m_num = 0;
      m_bal = 0.0;
   }
   Account::Account(int number, double balance )
   {
      setEmpty();
      if ( number <= 99999 && number >= 10000 && balance > 0)
      {
         m_num = number;
         m_bal = balance;
      }
   }
    std::ostream& Account::display() const
    {
      if (*this) {  
         cout << " ";
         cout << m_num;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_bal;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this)
    {
         cout << "  NEW  |         0.00 ";
    }
      else {
         cout << "  BAD  |    ACCOUNT   ";
    }
      return cout;
   }

    bool Account::isInvalid() 
    {
        return (m_num < 0 || m_bal < 0.0);
    }

    bool Account::operator ~() const 
    {
        return (m_num == 0);
    }

    Account::operator bool() const 
    {
        return (m_num >= 10000 && m_num <= 99999 && m_bal >= 0);
    }

    Account::operator int() const  
    {
        return m_num;
    }

    Account::operator double() const 
    {
        return m_bal;
    }

    Account& Account::operator <<(Account& acc) 
    {
        if (!this->isInvalid() && !acc.isInvalid() && this->m_num != acc.m_num) 
        {
            m_bal += acc.m_bal;

            acc.m_bal = 0;
        } return *this;
    }

    Account& Account::operator >>(Account& acc) 
    {
        if (!this->isInvalid() && !acc.isInvalid() && this->m_num != acc.m_num) 
        {
            acc.m_bal += m_bal;

            m_bal = 0;
        } return *this;
    }

    Account& Account::operator =(Account& acc) 
    {
        if (!isInvalid() && this->m_num == 0 && acc.m_num >= 10000 && acc.m_num <= 99999 && this->m_bal == 0.0) 
        {
            this->m_num = acc.m_num;
            acc.m_num = 0;

            this->m_bal = acc.m_bal;
            acc.m_bal = 0;
        } return *this;
    }

    Account& Account::operator +=(double val) 
    {
        if (!isInvalid() && val >= 0) 
        {
            m_bal += val;
        } return *this;
    }

    Account& Account::operator -=(double val) 
    {
        if (!isInvalid() && val >= 0 && m_bal >= val) 
        {
            m_bal -= val;
        } return *this;
    }

    Account& Account::operator =(int num) 
    {
        if (!isInvalid() && m_num == 0 && m_bal == 0.0) 
        {
            setEmpty();
            if (num >= 10000 && num <= 99999) 
            {
                m_num = num;
            }
        } return *this;
    }

    double operator +(const Account& acc1, const Account& acc2) 
    {
        if (bool(acc1) && bool(acc2)) 
        {
          return (double(acc1) + double(acc2));
        } 
        
        else
        {
            return 0;
        }
    }

    double operator +=(double& val, const Account& acc) 
    {
        val += double(acc);
        return val;
    }
}