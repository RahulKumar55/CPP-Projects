#ifndef SDDS_SAVINGSACCOUNT_H
#define SDDS_SAVINGSACCOUNT_H
#include"Account.h"

namespace sdds
{
	class SavingsAccount : public Account
	{
		double m_int;
	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif