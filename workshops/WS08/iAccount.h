#ifndef SDDS_IACCOUNT_H
#define SDDS_IACCOUNT_H
#include <iostream>
namespace sdds
{
	class iAccount
	{
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount()
		{

		}
	};
	iAccount* CreateAccount(const char*, double);
}
#endif // !SDDS_IACCOUNT_H
