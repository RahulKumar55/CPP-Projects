/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/02/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H

#include "Bar.h"

namespace sdds
{
	class BarChart
	{
		char* Title;
		Bar* bar;
		char cha;
		int size;
		int count;
	public:
		void init(const char* title, int noOfSampels, char fill);
		void add(const char* bar_title, int value);
		void draw();
		bool allValid();
		void deallocate();
	};

	
}

#endif // !SDDS_BARCHART_H
