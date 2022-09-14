#include "Account.h"
using namespace sdds;

namespace sdds
{
	Account::Account(double d)
	{
		if (d > 0)
		{
			m_bal = d;
		}
		else
		{
			m_bal = 0;
		}
	}

	bool Account::credit(double c)
	{
		bool ret = false;
		if (c > 0)
		{
			m_bal = m_bal + c;
			ret = true;
		}
		return ret;
	}

	bool Account::debit(double c)
	{
		bool ret = false;
		if (c > 0)
		{
			m_bal = m_bal - c;
			ret = true;
		}
		return ret;
	}

	double Account::balance() const
	{
		return m_bal;
	}
}