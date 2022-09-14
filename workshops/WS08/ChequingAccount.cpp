#include "ChequingAccount.h"
using namespace std;
using namespace sdds;

namespace sdds
{
	ChequingAccount::ChequingAccount(double bal, double t, double m) : Account(bal)
	{
		if (t > 0)
		{
			t_fee = t;
		}
		else
		{
			t_fee = 0;
		}

		if (m > 0)
		{
			m_fee = m;
		}
		else
		{
			m_fee = 0;
		}
	}
	bool ChequingAccount::credit(double c)
	{
		bool ret = Account::credit(c);
		if (ret)
		{
			Account::debit(t_fee);
		}
		return ret;
	}
	bool ChequingAccount::debit(double c)
	{
		bool ret = Account::debit(c);
		if (ret)
		{
			Account::debit(t_fee);
		}
		return ret;
	}
	void ChequingAccount::monthEnd()
	{
		Account::debit(m_fee);
	}
	void ChequingAccount::display(std::ostream& os) const
	{
		os.setf(ios::fixed);
		os.precision(2);
		os << "Account type: Chequing" << endl;
		os << "Balance: $" << balance() << endl;
		os << "Per Transaction Fee: " << t_fee << endl;
		os << "Monthly Fee: " << m_fee << endl;
	}
}