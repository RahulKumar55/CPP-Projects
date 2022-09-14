#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
#include"iAccount.h"

namespace sdds
{
	class Account : public iAccount
	{
		double m_bal;
	public:
		Account();
		Account(double);
		bool credit(double);
		bool debit(double);
	protected:
		double balance() const;
	};
}

#endif // !SDDS_ACCOUNT_H