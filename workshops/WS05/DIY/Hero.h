/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/15/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include <iostream>
#include "Power.h"

namespace sdds{
	class Hero
	{
		char h_name[MAX_NAME_LENGTH];
		Power* pow;
		int num_pow;
		int pow_level;
	public:
		Hero();
		Hero(const char* name, const Power* power, int count);
		~Hero();
		std::ostream& display()const;
		Hero& operator+=(Power& new_pow);
		Hero& operator-=(int reduce);

		int checkpower();
	};
	
	bool operator<(Hero& h1, Hero& h2);
	bool operator>(Hero& h1, Hero& h2);
	Hero& operator>>(Power& new_pow, Hero& h1);
	Hero& operator<<(Hero& h1, Power& new_pow);

	std::ostream& operator<<(std::ostream& os, const Hero& h);
}

#endif