/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/15/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Hero.h"

using namespace std;
using namespace sdds;

namespace sdds
{
	Hero::Hero()
	{
		h_name[0] = '\0';
		pow = nullptr;
		num_pow = 0;
		pow_level = 0;
	}

	Hero::Hero(const char* name, const Power* power, int count)
	{
		if (name[0] != '\0' && power != nullptr && count > 0)
		{
			strcpy(h_name, name);
			num_pow = count;
			pow = new Power[num_pow];
			for (int i = 0; i < num_pow; i++)
			{
				if (!power[i].isEmpty())
				{
					pow[i].createPower(power[i].checkName(), power[i].checkRarity());
				}
			}

			int sumrar = 0;
			for (int i = 0; i < num_pow; i++)
			{
				sumrar += pow[i].checkRarity();
			}

			pow_level = sumrar * num_pow;
		}

	}

	Hero::~Hero()
	{
		delete[] pow;
	}

	int Hero::checkpower() {
		return pow_level;
	}


	std::ostream& Hero::display()const
	{
		cout << "Name: ";
		cout << h_name << endl;
		cout.unsetf(ios::left);
		cout << "List of available powers: " << endl;
		for (int i = 0; i < num_pow; i++)
		{
			cout << "  Name: " << pow[i].checkName() << ", Rarity: " << pow[i].checkRarity() << endl;
		}
		cout << "Power Level: " << pow_level;
		return cout;
	}

	Hero& Hero::operator+=(Power& new_pow)
	{
		Power* temp;
		temp = new Power[num_pow];
		for (int i = 0; i < num_pow; i++)
		{
			temp[i].createPower(pow[i].checkName(), pow[i].checkRarity());
		}
		delete[] pow;

		pow = new Power[num_pow + 1];
		for (int i = 0; i < num_pow; i++)
		{
			pow[i].createPower(temp[i].checkName(), temp[i].checkRarity());
		}
		delete[] temp;
		temp = nullptr;

		pow[num_pow].createPower(new_pow.checkName(), new_pow.checkRarity());
		num_pow++;

		int sumrar = 0;
		for (int i = 0; i < num_pow; i++)
		{
			sumrar += pow[i].checkRarity();
		}

		pow_level = sumrar * num_pow;
		return *this;
	}

	Hero& Hero::operator-=(int reduce)
	{
		pow_level = pow_level - reduce;
		return *this;
	}

	bool operator<(Hero& h1, Hero& h2)
	{
		bool ret = false;
		if (h1.checkpower() < h2.checkpower())
		{
			ret = true;
		}
		return ret;
	}

	bool operator>(Hero& h1, Hero& h2)
	{
		bool ret = false;
		if (h1.checkpower() > h2.checkpower())
		{
			ret = true;
		}
		return ret;
	}

	Hero& operator>>(Power& new_pow, Hero& h1)
	{
		h1 += new_pow;
		return h1;
	}

	Hero& operator<<(Hero& h1, Power& new_pow)
	{
		h1 += new_pow;
		return h1;
	}

	std::ostream& operator<<(std::ostream& os, const Hero& h)
	{
		h.display();
		return os;
	}
}