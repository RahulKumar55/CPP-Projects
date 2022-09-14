/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/12/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "MemberParliament.h"
using namespace std;
using namespace sdds;
namespace sdds
{
	MemberParliament::MemberParliament()
	{
		strcpy(m_pid, "\0");
		strcpy(m_district, "\0");
		m_age = 0;
	}
	MemberParliament::MemberParliament(const char* id, int age)
	{
		strcpy(m_pid, id);
		strcpy(m_district, "Unassigned");
		m_age = age;
	}
	void MemberParliament::NewDistrict(const char* district)
	{
		cout.setf(ios::right);
		cout << "|";
		cout.width(8);
		cout << m_pid << "| |";
		cout.width(20);
		cout << m_district << " ---> ";
		strcpy(m_district, district);
		cout.unsetf(ios::right);
		cout.setf(ios::left);
		cout.width(23);
		cout << m_district << "|" << endl;
	}
	void MemberParliament::setmp(const char* id, const char* district, int age)
	{
		strcpy(m_pid, id);
		strcpy(m_district, district);
		m_age = age;
	}

	std::ostream& MemberParliament::write(std::ostream& os) const
	{
		os << "| " << m_pid << " | " << m_age << " | " << m_district << "";
		return os;
	}
	std::istream& MemberParliament::read(std::istream& in)
	{
		cout << "Age: ";
		in >> m_age;
		cout << "Id: ";
		in >> m_pid;
		cout << "District: ";
		in >> m_district;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const MemberParliament& m)
	{
		m.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& in, MemberParliament& m)
	{
		m.read(in);
		return in;
	}
}