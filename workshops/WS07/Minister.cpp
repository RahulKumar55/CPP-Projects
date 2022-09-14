/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/12/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Minister.h"
using namespace std;
using namespace sdds;
namespace sdds
{
	Minister::Minister() : MemberParliament() {
		strcpy(m_pm, "\0");
		m_year = 0;
	}
	Minister::Minister(const char* id, int age, int year, const char* pm, const char* district) : MemberParliament(id, age)
	{
		NewDistrict(district);
		strcpy(m_pm, pm);
		m_year = year;
	}
	void Minister::changePM(const char* pm){
		strcpy(m_pm, pm);
	}
	void Minister::assumeOffice(double year){
		m_year = year;
	}
	std::ostream& Minister::write(std::ostream& os) const {
	
		MemberParliament::write(os) << " | " << m_pm << "/" << m_year << "";
		return os;
	}
	std::istream& Minister::read(std::istream& in){
		char id[32], district[64];
		int age;
		cout << "Age: ";
		in >> age;
		cout << "Id: ";
		in >> id;
		cout << "District: ";
		in >> district;
		setmp(id, district, age);

		cout << "Reports TO: ";
		in >> m_pm;
		cout << "Year Assumed Office: ";
		in >> m_year;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const Minister& m)
	{
		m.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& in, Minister& m)
	{
		m.read(in);
		return in;
	}
}