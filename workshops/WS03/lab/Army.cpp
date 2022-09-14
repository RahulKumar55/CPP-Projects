/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 05/31/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Army.h"

using namespace std;
using namespace sdds;

namespace sdds
{

	// member functions
	void Army::setEmpty()
	{
		noOfUnits = 0;
		strcpy(nationality, "\0");
		
	}

	void Army::createArmy(const char* country, double pow, int troops)
	{
		if (pow > 0 && troops > 0)
		{
			if (country != nullptr && strlen(country) > 0)
			{
				noOfUnits = troops;
				power = pow;
				strcpy(nationality, country);
			}
			else
			{
				setEmpty();
			}
		}
		else
		{
			setEmpty();
		}

	}

	void Army::updateUnits(int troops)
	{
		noOfUnits += troops;
		power += (troops * 0.25);
	}

	const char* Army::checkNationality() const{
		return nationality;
	}

	int Army::checkCapacity() const{
		return noOfUnits;
	}
	double Army::checkPower() const{
		return power;
	}
	bool Army::isEmpty() const{
		bool res;
		if (strcmp(nationality, "\0") == 0 || noOfUnits == 0)
		{
			res = true;
		}
		else
		{
			res = false;
		}
		return res;
	}

	bool Army::isStrongerThan(const Army& army) const{
		bool res;
		if (power > army.checkPower())
		{
			res = true;
		}
		else
		{
			res = false;
		}
		return res;
	}

	// Global functions
	void battle(Army& arm1, Army& arm2)
	{
		bool win1;
		if (!arm1.isEmpty() && !arm2.isEmpty())
		{
			if (arm1.isStrongerThan(arm2))
			{
				arm2.updateUnits((int)(-(arm2.checkCapacity() * 0.5)));
				win1 = true;
			}
			else
			{
				arm1.updateUnits((int)(-(arm1.checkCapacity() * 0.5)));
				win1 = false;
			}

			cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", ";
			if (win1)
			{
				cout << arm1.checkNationality() << " is victorious!" << endl;
			}
			else
			{
				cout << arm2.checkNationality() << " is victorious!" << endl;
			}
		}
	}
	void displayDetails(const Army* armies, int size)
	{
		int i;
		cout << "Armies reporting to battle: " << endl;
		cout.setf(ios::fixed);
		cout.precision(1);
		for ( i = 0; i < size; i++)
		{
			if (!armies[i].isEmpty())
			{
				cout << "Nationality: " << armies[i].checkNationality()
					<< ", Units Count: " << armies[i].checkCapacity()
					<< ", Power left: " << armies[i].checkPower() << endl;
			}
		}
		
	}
}