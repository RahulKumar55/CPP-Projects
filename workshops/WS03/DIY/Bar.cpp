/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/02/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Bar.h"

using namespace std;
using namespace sdds;


namespace sdds
{

	void Bar::setEmpty(){
		strcpy(btitle,"\0");
		fillc = '\0';
		value = -1;
	}


	void Bar::set(const char* title, char ch, int fvalue) {
		if (fvalue > 100 || fvalue < 0)
		{
			setEmpty();
		}
		else
		{
			strcpy(btitle, title);
			fillc = ch;
			value = fvalue;
		}
	}

	bool Bar::isValid() const { 
		bool result;
		if (value > 100 || value < 0)
		{
			result = false;
		}
		else
		{
			result = true;
		}

		return result;
	}

	void Bar::draw() const{
		int i;
		if (isValid())
		{
			
			cout.width(20);
			cout.fill('.');
			cout.setf(ios::left);
			cout << btitle;
			cout.unsetf(ios::left);
			cout << "|";

			for ( i = 0; i < ((int)value/2); i++)
			{
				cout << fillc;
			}
			cout << endl;
		}

	}
}