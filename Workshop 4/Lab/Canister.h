#ifndef SDDS_CANISTER_H
#define SDDS_CANISTER_H
#include <iostream>
namespace sdds {
   class Canister {
      char* m_contentName; // points to a dynamically allocated Cstring.
      double m_diameter; // in centimeters 
      double m_height;   // in centimeters
      double m_contentVolume;  // in CCs
      bool m_usable; // a flag to identify if the Canister is usable or unusable
      void setToDefault();
      bool isEmpty()const;
      bool hasSameContent(const Canister& C)const;
      void setName(const char* Cstr);
   public:
      Canister();
      Canister(const char* contentName);
      Canister(double height, double diameter,const char* contentName = nullptr);
      void clear();
      double capacity()const;
      double volume()const;
      Canister& setContent(const char* contentName);
      Canister& pour(double quantity);
      Canister& pour(Canister&);
      std::ostream& display()const;
      ~Canister();
   };
}

#endif // !SDDS_BOX_H
