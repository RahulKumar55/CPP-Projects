/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/29/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"

namespace sdds
{
	class Book : public Publication
	{
		char m_author[257];
	public:
		Book();
		~Book();;
		virtual char type()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		virtual void set(int member_id);
		operator bool();
		bool conIO(std::ios&) const;

		friend std::ostream& operator<<(std::ostream& os, Book& b);
		friend std::istream& operator>>(std::istream& istr, Book& b);
	};
}
#endif // !SDDS_BOOK_H

