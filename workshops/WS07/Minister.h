/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/12/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H
#include <iostream>
#include "MemberParliament.h"

namespace sdds
{
	class Minister : public sdds::MemberParliament
	{
		char m_pm[50];
		int m_year;
	public:
		Minister();
		Minister(const char* id, int age, int year, const char* pm, const char* district);
		void changePM(const char* pm);
		void assumeOffice(double year);
		std::ostream& write(std::ostream& os) const ;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Minister& m);
	std::istream& operator>>(std::istream& in, Minister& m);
}

#endif // !SDDS_MINISTER_H

