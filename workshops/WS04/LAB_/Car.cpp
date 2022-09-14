/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/08/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;
using namespace sdds;

namespace sdds
{
	Car::Car()
	{
		resetInfo();
	}

	Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		bool k = true;
		if ((type != nullptr) && (brand != nullptr) && (model != nullptr))
		{
			m_type = new char[11];
			m_brand = new char[17];
			m_model = new char[17];
			strcpy(m_type, type);
			strcpy(m_brand, brand);
			strcpy(m_model, model);
		}
		else
		{
			resetInfo();
			k = false;
		}

		if (k)
		{
			if ((year < 1990) || (code < 100 || code > 999) || (price <= 0))
			{
				delete[] m_type;
				delete[] m_brand;
				delete[] m_model;
				resetInfo();
			}
			else
			{
				m_year = year;
				m_code = code;
				m_price = price;
			}
		}

	}

	Car::~Car()
	{

		if (m_type != nullptr)
		{
			delete[] m_type;
		}

		if(m_brand != nullptr){
			delete[] m_brand;
		}

		if (m_model != nullptr)
		{
			delete[] m_model;
		}
		
	}

	//////////////

	Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		if (m_type != nullptr)
		{
			delete[] m_type;
		}

		if (m_brand != nullptr)
		{
			delete[] m_brand;
		}

		if (m_model != nullptr)
		{
			delete[] m_model;
		}
		
		
		bool k = true;
		if ((type != nullptr) && (brand != nullptr) && (model != nullptr))
		{
			m_type = new char[11];
			m_brand = new char[17];
			m_model = new char[17];
			strcpy(m_type, type);
			strcpy(m_brand, brand);
			strcpy(m_model, model);
		}
		else
		{
			resetInfo();
			k = false;
		}

		if (k)
		{
			if ((year < 1990) || (code < 100 || code > 999) || (price <= 0))
			{
				delete[] m_type;
				delete[] m_brand;
				delete[] m_model;
				resetInfo();
			}
			else
			{
				m_year = year;
				m_code = code;
				m_price = price;
			}
		}

		return *this;
	}

	void Car::printInfo() const
	{
		if (isValid())
		{
			cout << "| ";
			cout.width(10);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_type << " | ";
			cout.width(16);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_brand << " | ";
			cout.width(16);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_model;
			cout << " | " << m_year;
			cout << " |  " << m_code << " |  ";
			
			cout.width(8);
			cout.fill(' ');
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_price << " |" << endl;
			cout.unsetf(ios::right);
			cout.unsetf(ios::left);

		}
	}

	bool Car::isValid() const
	{
		bool v = true;
		if ((m_type != nullptr ) && (m_brand != nullptr) && (m_model != nullptr))
		{
			if ((m_year < 1990) || (m_code < 100 || m_code > 999) || (m_price <= 0))
			{
				v = false;
			}
		}
		else
		{
			v = false;
		}

		return v;
	}

	bool Car::isSimilarTo(const Car& car) const
	{
		int i = 0;
		if (isValid() && car.isValid())
		{

			if (strcmp(m_type, car.m_type) == 0)
			{
				i++;
			}

			if (strcmp(m_brand, car.m_brand) == 0)
			{
				i++;
			}

			if (strcmp(m_model, car.m_model) == 0)
			{
				i++;
			}

			if (m_year == car.m_year)
			{
				i++;
			}
		}

		return i == 4;
	}

	////////////

	bool has_similar(const Car car[], const int num_cars)
	{
		int k = 0;
		for (int i = 0; i < num_cars; i++)
		{
			for (int j = i + 1; j < num_cars; j++)
			{
				if (car[i].isSimilarTo(car[j]))
				{
					k++;
				}
			}
		}

		return k != 0;
	}

	bool has_invalid(const Car car[], const int num_cars)
	{
		int inv = 0;
		for (int i = 0; i < num_cars; i++)
		{
			if (!(car[i].isValid()))
			{
				inv++;
			}
		}
		return inv != 0;
	}

	void print(const Car car[], const int num_cars)
	{
		for (int i = 0; i < num_cars; i++)
		{
			car[i].printInfo();
		}
	}

}