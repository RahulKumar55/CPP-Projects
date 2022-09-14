/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/02/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "BarChart.h"

using namespace std;
using namespace sdds;


namespace sdds
{

	void BarChart::init(const char* title, int noOfSampels, char fill){
		int i;
		Title = new char[50];
		strcpy(Title, title);
		size = noOfSampels;
		bar = new Bar[size];
		cha = fill;
		count = 0;
		for ( i = 0; i < size; i++)
		{
			bar[i].setEmpty();
		}
	}

	void BarChart::add(const char* bar_title, int value){
		int i, k = 0;
		for ( i = 0; i < size && k == 0; i++)
		{
			if (!bar[i].isValid())
			{
				bar[i].set(bar_title, cha, value);
				k = 1;
			}
		}
	}
	void BarChart::draw() {
		int i;
		if (allValid())
		{
			cout << Title << endl;
			cout.width(71);
			cout.fill('-');
			cout.setf(ios::left);
			cout << "-" << endl;
			cout.unsetf(ios::left);

			for ( i = 0; i < size; i++)
			{
				bar[i].draw();
			}

			cout.width(71);
			cout.fill('-');
			cout.setf(ios::left);
			cout << "-" << endl;
			cout.unsetf(ios::left);
		}
		else
		{
			count = 0;
			cout << "Invalid Chart!" << endl;
		}
	}

	bool BarChart::allValid(){
		int i;
		for ( i = 0; i < size; i++)
		{
			if (bar[i].isValid())
			{
				count++;
				
			}
		}

		return count == size;
	}

	void BarChart::deallocate(){
		
		delete [] bar;
		delete[] Title;
		
	}

}