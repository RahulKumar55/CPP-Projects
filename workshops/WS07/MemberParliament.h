/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/12/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H
#include <iostream>

namespace sdds
{
	class MemberParliament
	{
		char m_pid[32];
		char m_district[64];
		int m_age;
	public:
		MemberParliament();
		MemberParliament(const char* id, int age);
		void NewDistrict(const char* district);
		void setmp(const char* id, const char* district, int age);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& os, const MemberParliament& m);
	std::istream& operator>>(std::istream& in, MemberParliament& m);
}

#endif // !SDDS_MEMBERPARLIAMENT_H
