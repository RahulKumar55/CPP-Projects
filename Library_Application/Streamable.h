/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/29/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_h
#include <iostream>

namespace sdds
{
	class Streamable
	{
	public:
		virtual std::ostream& write(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual bool conIO(std::ios&) const = 0;
		virtual operator bool() = 0;
		virtual ~Streamable();
		std::ostream& operator<<(std::ostream& os) const;
		std::istream& operator>>(std::istream& istr);
	};
	
}

#endif // !SDDS_STREAMABLE_H

