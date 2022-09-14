/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/30/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include <iostream>
namespace sdds
{
	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};

	class Basket
	{
		Fruit* m_fruits;
		int m_cnt;
		double m_price;
	public:
		Basket();
		Basket(Fruit* f1, int c1, double p1);
		Basket(Basket& bas1);
		Basket& operator=(Basket& bas1);
		~Basket();
		void setPrice(double price);
		operator bool() const;
		Basket& operator+=(Fruit fru);

		//////////////////
		//Extra functions

		void setEmpty();
		void set(Fruit* f1, const int c1, double p1);
		void display(std::ostream& os);
	};

	std::ostream& operator<<(std::ostream& os, Basket& bas);
}
#endif // !SDDS_BASKET_H
