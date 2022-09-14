/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/08/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef CLEANERBOT_H
#define CLEANERBOT_H

namespace sdds
{
	class CleanerBot
	{
		char* loc;
		double batt;
		int bru;
		bool act;
	public:
		CleanerBot();
		CleanerBot(const char* location, double battery, int brush, bool active);
		~CleanerBot();
		void set(const char* location, double battery, int brush, bool active);
		void setLocation(const char* location);
		void setActive(bool active);
		char* getLocation()const;
		double getBattery()const;
		int getBrush()const;
		bool isActive()const;
		bool isValid()const;
		void display()const;
	};

	int report(CleanerBot* bot, const short num_bots);

	// Extra functions
	void sort(CleanerBot* bot, const short num_bots);
	void swap(CleanerBot* bot1, CleanerBot* bot2);
}

#endif // !CLEANERBOT_H

