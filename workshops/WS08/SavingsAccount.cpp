#include "SavingsAccount.h"
using namespace std;
using namespace sdds;

namespace sdds
{
	SavingsAccount::SavingsAccount(double bal, double inte) : Account(bal)
	{
		if (inte > 0)
		{
			m_int = inte * 100;
		}
		else
		{
			m_int = 0;
		}
	}
	void SavingsAccount::monthEnd()
	{
		double val = 0;
		val = balance() * (m_int / 100);
		credit(val);
	}
	void SavingsAccount::display(std::ostream& os) const
	{
		os.setf(ios::fixed);
		os.precision(2);
		os << "Account type: Savings" << endl;
		os << "Balance: $" << balance() << endl;
		os << "Interest Rate (%): " << m_int << endl;
	}
}