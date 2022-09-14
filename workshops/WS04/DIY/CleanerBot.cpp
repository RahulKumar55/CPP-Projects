/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/08/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "CleanerBot.h"

using namespace std;
using namespace sdds;

namespace sdds
{
	CleanerBot::CleanerBot()
	{
		loc = nullptr;
		batt = -1;
		bru = 0;
		act = false;
	}

	CleanerBot::CleanerBot(const char* location, double battery, int brush, bool active)
	{
		if (location != nullptr && battery >= 0 && brush >= 1)
		{
			loc = new char[11];
			set(location, battery, brush, active);
		}
		else
		{
			loc = nullptr;
			batt = -1;
			bru = 0;
			act = false;
		}
	}

	CleanerBot::~CleanerBot()
	{
		if (loc != nullptr)
		{
			delete[] loc;
		}
	}

	void CleanerBot::set(const char* location, double battery, int brush, bool active)
	{
		if (loc != nullptr)
		{
			delete[] loc;
		}
		loc = new char[11];
		setLocation(location);
		batt = battery;
		bru = brush;
		setActive(active);
	}

	void CleanerBot::setLocation(const char* location)
	{
		strcpy(loc, location);
	}

	void CleanerBot::setActive(bool active)
	{
		act = active;
	}

	char* CleanerBot::getLocation()const
	{
		return loc;
	}

	double CleanerBot::getBattery()const
	{
		return batt;
	}

	int CleanerBot::getBrush()const
	{
		return bru;
	}

	bool CleanerBot::isActive()const
	{
		return act;
	}

	bool CleanerBot::isValid()const
	{
		bool i = false;
		if (loc != nullptr && batt >= 0 && bru >= 1)
		{
			i = true;
		}
		return i;
	}

	void CleanerBot::display()const 
	{
		
		string state = act ? "YES" : "NO";
		cout << "| ";
		cout.width(10);
		cout.fill(' ');
		cout.setf(ios::left);
		cout << loc << " | ";
		cout.width(7);
		cout.setf(ios::right);
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << batt << " | ";
		cout.width(18);
		cout << bru << " | ";
		cout.width(6);
		cout.unsetf(ios::right);
		cout.setf(ios::left);
		cout << state << " |" << endl;
		cout.unsetf(ios::left);
	}

	////////////////////////////////
	// Global Functions

	int report(CleanerBot* bot, const short num_bots)
	{
		int lowCharge = 0;
		cout << "         ------ Cleaner Bots Report -----\n"
			<< "     ---------------------------------------" <<endl;
		cout << "| Location   | Battery |  Number of Brushes | Active |\n" << "|------------+---------+--------------------+--------|" << endl;

		for (int i = 0; i < num_bots; i++)
		{
			if (bot[i].isValid())
			{
				bot[i].display();
			}
		}

		for (int i = 0; i < num_bots; i++)
		{
			if (bot[i].getBattery() < 30 && bot[i].isValid())
			{
				lowCharge++;
			}
		}

		if (lowCharge)
		{
			sort(bot, num_bots);
			cout << "\n|====================================================|\n" << "| LOW BATTERY WARNING:                               |\n" << "|====================================================|" << endl;

			cout << "| Number of robots to be charged: " << lowCharge << "                  |\n" << "| Sorting robots based on their available power:     |" << endl;
			cout << "| Location   | Battery |  Number of Brushes | Active |\n" << "|------------+---------+--------------------+--------|" << endl;

			for (int i = 0; i < num_bots; i++)
			{
				if (bot[i].isValid())
				{
					bot[i].display();
				}
			}

			cout << "|====================================================|" << endl;

		}

		return lowCharge;
	}

	///////////////////////////////
	//Extra Functions

	void sort(CleanerBot* bot, const short num_bots)
	{
		for (int i = 0; i < num_bots - 1; i++)
		{
			int maxpos = i;
			if (bot[i].isValid())
			{
				for (int j = i+1; j < num_bots; j++)
				{
					if (bot[j].isValid() && (bot[maxpos].getBattery() < bot[j].getBattery()))
					{
						maxpos = j;
					}
				}
			}

			if (maxpos != i)
			{
				swap(&bot[i] , &bot[maxpos]);
			}
		}
	}

	void swap(CleanerBot* bot1, CleanerBot* bot2)
	{
		CleanerBot temp = {};
		temp.set(bot1->getLocation(), bot1->getBattery(), bot1->getBrush(), bot1->isActive());
		bot1->set(bot2->getLocation(), bot2->getBattery(), bot2->getBrush(), bot2->isActive());
		bot2->set(temp.getLocation(), temp.getBattery(), temp.getBrush(), temp.isActive());
	}
	

}