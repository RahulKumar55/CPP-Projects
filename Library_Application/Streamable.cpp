/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/29/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Streamable.h"
using namespace sdds;

namespace sdds
{
	Streamable::~Streamable()
	{

	}
	std::ostream& Streamable::operator<<(std::ostream& os) const
	{
		return os;
	}
	std::istream& Streamable::operator>>(std::istream& istr)
	{
		return istr;
	}
}