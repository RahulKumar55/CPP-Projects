/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/29/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#include "Publication.h"
#include "Lib.h"
using namespace sdds;

namespace sdds
{
	Publication::Publication()
	{
		setEmpty();
	}

	Publication::~Publication()
	{
		
	}

	void Publication::set(int member_id)
	{
		if (member_id < 10000 || member_id > 99999)
		{
			m_membership = 0;
		}
		else
		{
			m_membership = member_id;
		}
	}

	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	void Publication::resetDate()
	{
		m_date.setToToday();
	}

	char Publication::type() const
	{
		return 'P';
	}

	bool Publication::onLoan() const
	{
		return m_membership != 0;
	}

	Date Publication::checkoutDate()const
	{
		return m_date;
	}

	bool Publication::operator==(const char* title)const
	{
		bool ret = false;
		const char* t = strstr(m_title, title);
		if (t)
		{
			ret = true;
		}
		return ret;
	}

	Publication::operator const char* ()const
	{
		return m_title;
	}

	int Publication::getRef()const
	{
		return m_libRef;
	}

	Publication::operator bool()
	{
		bool ret = false;
		if (strlen(m_title)>0)
		{
			if (strlen(m_shelfId) == 4)
			{
				ret = true;
			}
		}
		return ret;
	}

	bool Publication::conIO(std::ios& io) const
	{
		bool ret = false;
		if ((addressof(io) == addressof(cin)) || (addressof(io) == addressof(cout)))
		{
			ret = true;
		}
		return ret;
	}

	ostream& Publication::write(ostream& os) const
	{
		if (conIO(os))
		{
			os << "| " << m_shelfId << " | ";
			os.setf(ios::left);
			if (strlen(m_title) > SDDS_TITLE_WIDTH)
			{
				for (int i = 0; i < SDDS_TITLE_WIDTH; i++)
				{
					os << m_title[i];
				}
			}
			else
			{
				os.fill('.');
				os.width(SDDS_TITLE_WIDTH);
				os << m_title;
			}
			os << " | ";
			os.unsetf(ios::left);
			os.setf(ios::fixed);
			os.fill(' ');
			os.width(5);
			if (m_membership == 0)
			{
				os << " N/A ";
			}
			else
			{
				os << m_membership;
			}
			os << " | " << m_date << " |";
		}
		else
		{
			os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
		}
		return os;
	}

	istream& Publication::read(istream& istr)
	{
		setEmpty();

		char ltitle[255];
		char lsid[20];
		int lmem = 0, lref = -1;
		Date ldate;
		ldate.set(0, 0, 0);

		if (conIO(istr))
		{
			cout << "Shelf No: ";
			istr >> lsid;
			if (strlen(lsid) != 4)
			{
				istr.setstate(ios::failbit);
				cout << "Title: ";
				cout << "Date: ";
			}
			else
			{
				cout << "Title: ";
				cin.ignore(1000, '\n');
				cin.get(ltitle, 255, '\n');
				cin.ignore(1000, '\n');
				cout << "Date: ";
				istr >> ldate;
			}
		}
		else
		{
			istr >> lref;
			istr.ignore();
			istr >> lsid;
			istr.ignore();
			istr.get(ltitle, 255, '\t');
			istr.ignore();
			istr >> lmem;
			istr.ignore();
			istr >> ldate;
		}
		if (!ldate)
		{
			istr.setstate(ios::failbit);
		}

		if (!istr.fail())
		{
			strcpy(m_title, ltitle);
			strcpy(m_shelfId, lsid);
			m_membership = lmem;
			m_date.set(ldate.getyear(), ldate.getmon(), ldate.getday());
			m_libRef = lref;
		}
		return istr;
	}

	void Publication::setEmpty(){
		strcpy(m_title, "");
		strcpy(m_shelfId, "");
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();
	}


	std::ostream& operator<<(std::ostream& os, Publication& p)
	{
		if (p)
		{
			p.write(os);
		}
		return os;
	}
	std::istream& operator>>(std::istream& istr, Publication& p)
	{
		p.read(istr);
		return istr;
	}
}