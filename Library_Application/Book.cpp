/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/29/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"
using namespace std;
using namespace sdds;

namespace sdds
{
	Book::Book()
	{

	}
	Book::~Book()
	{

	}
	char Book::type()const
	{
		return 'B';
	}
	std::ostream& Book::write(std::ostream& os) const
	{
		Publication::write(os);
		if (conIO(os))
		{
			os << " ";
			if (strlen(m_author) > SDDS_AUTHOR_WIDTH)
			{
				for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++)
				{
					os << m_author[i];
				}
			}
			else
			{
				os.width(SDDS_AUTHOR_WIDTH);
				os.setf(ios::left);
				os << m_author;
				os.unsetf(ios::left);
			}
			os <<" |";
		}
		else
		{
			os << "\t" << m_author;
		}
		return os;
	}
	std::istream& Book::read(std::istream& istr)
	{
		Publication::read(istr);
		char aut[257];
		if (conIO(istr))
		{
			istr.ignore();
			cout << "Author: ";
			istr.get(aut, 256, '\n');
		}
		else
		{
			istr.ignore();
			istr.get(aut, 256, '\n');
		}

		if (!istr.fail())
		{
			strcpy(m_author, aut);
		}
		return istr;
	}
	void Book::set(int member_id)
	{
		Publication::set(member_id);
		resetDate();
	}
	Book::operator bool()
	{
		bool ret = false;
		if (m_author != nullptr)
		{
			if ((Publication)*this)
			{
				ret = true;
			}
		}
		return ret;
	}
	bool Book::conIO(std::ios& io) const
	{
		bool ret = false;
		if ((addressof(io) == addressof(cin)) || (addressof(io) == addressof(cout)))
		{
			ret = true;
		}
		return ret;
	}

	std::ostream& operator<<(std::ostream& os, Book& b)
	{
		if (b)
		{
			b.write(os);
		}
		return os;
	}
	std::istream& operator>>(std::istream& istr, Book& b)
	{
		b.read(istr);
		return istr;
	}
}