/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/30/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include"Basket.h"
using namespace sdds;
using namespace std;
namespace sdds
{
	Basket::Basket(){ 
		setEmpty();
	}
	Basket::Basket(Fruit* f1, int c1, double p1){ 
		setEmpty();
		if (f1 != nullptr && (c1 > 0 && p1 > 0))
		{
			set(f1, c1, p1);
		}
	}
	Basket::Basket(Basket& bas1){
		setEmpty();
		*this = bas1;
	}
	Basket& Basket::operator=(Basket& bas1){
		if (*this)
		{
			delete[] m_fruits;
		}
		setEmpty();
		if (bas1)
		{
			set(bas1.m_fruits, bas1.m_cnt, bas1.m_price);
		}
		return *this;
	}
	Basket::~Basket(){

		delete[] m_fruits;
	}
	void Basket::setPrice(double price)
	{
		m_price = price;
	}
	Basket::operator bool() const
	{
		return m_fruits != nullptr;
	}
	Basket& Basket::operator+=(Fruit fru){
		Fruit* temp;
		temp = new Fruit[m_cnt + 1];
		for (int i = 0; i < m_cnt; i++)
		{
			temp[i] = m_fruits[i];
		}
		temp[m_cnt] = fru;
		delete[] m_fruits;
		m_cnt++;
		m_fruits = new Fruit[m_cnt];
		for (int i = 0; i < m_cnt; i++)
		{
			 m_fruits[i] = temp[i];
		}
		delete[] temp;
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, Basket& bas)
	{
		bas.display(os);
		return os;
	}

	///////////////
	// Extra Functions
	void Basket::setEmpty()
	{
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0;
	}

	void Basket::set(Fruit* f1, const int c1, double p1)
	{
		m_cnt = c1;
		m_price = p1;
		m_fruits = new Fruit[m_cnt];
		for (int i = 0; i < c1; i++)
		{
			m_fruits[i] = f1[i];
		}
	}

	void Basket::display(std::ostream& os)
	{
		if (m_fruits != nullptr)
		{
			os.setf(ios::fixed);
			os.precision(2);
			os << "Basket Content:" << endl;
			for (int i = 0; i < m_cnt; i++)
			{
				os.width(10);
				os << m_fruits[i].m_name << ": " << m_fruits[i].m_qty << "kg" << endl;
			}
			os << "Price: " << m_price << endl;
		}
		else
		{
			os << "The basket is empty!" << endl;
		}
	}
}