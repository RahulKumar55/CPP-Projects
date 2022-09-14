/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/29/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef SDDS_LIBAPP_H__
#define SDDS_LIBAPP_H__
#include <iostream>
#include "Menu.h"
#include "Publication.h"
#include "Book.h"
#include "Lib.h"

namespace sdds
{
	class LibApp
	{
		char m_file[257];
		Publication* PPA[SDDS_LIBRARY_CAPACITY];
		int NOLP;
		int LLRN;
		Menu p_type;
		////////////////////////////
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		bool confirm(const char* message);
		void load();
		void save();
		int search(const int s);
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
		Publication* getPub(int libRef);
	public:
		LibApp();
		LibApp(const char* file);
		~LibApp();
		void run();
	};
}

#endif