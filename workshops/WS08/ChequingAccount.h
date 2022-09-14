#ifndef SDDS_CHEQUINGACCOUNT_H
#define SDDS_CHEQUINGACCOUNT_H
#include"Account.h"

namespace sdds
{
	class ChequingAccount : public Account
	{
		double t_fee;
		double m_fee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
	
#endif