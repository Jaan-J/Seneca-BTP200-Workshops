// Workshop 3: Lab
// Date: Feb 4, 2021
// Author: Jaan Javed
// Student ID: 100131192
// I have done all the coding by myself and only
// copied the code that my professor provided
// to complete my workshops and assignments.
/////////////////////////////////////////////////
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
namespace sdds
{
   class Item
   {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char *name);

   public:
      void setEmpty();
      void set(const char *name, double price, bool taxed);
      double price() const;
      double tax() const;
      bool isValid() const;
      void display() const;
   };
} // namespace sdds

#endif
