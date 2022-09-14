/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/29/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#include "Menu.h"
#include "Utils.h"

using namespace sdds;

namespace sdds
{
	MenuItem::MenuItem()
	{
		item = nullptr;
	}
	MenuItem::~MenuItem()
	{
		delete[] item;
	}
	void MenuItem::set(const char* it)
	{
		delete[] item;
		if (it != nullptr && strlen(it) > 0)
		{
			int j = strlen(it);
			item = new char[j + 1];
			strcpy(item, it);
		}
		else
		{
			item = nullptr;
		}
	}
	MenuItem::operator bool()
	{
		return item != nullptr;
	}
	MenuItem::operator const char* ()
	{
		return &item[0];
	}
	const char* MenuItem::displayItem() const
	{
		if (item != nullptr)
		{
			return item;
		}
		else
		{
			return  "";
		}
	}



	Menu::Menu()
	{
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
		{
			items[i] = nullptr;
		}
		count = 0;
	}
	Menu::Menu(const char* ti)
	{ 
		title.set(ti);
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
		{
			items[i] = nullptr;
		}
		count = 0;
	}
	Menu::~Menu()
	{
		for (unsigned int i = 0; i < count; i++)
		{
			delete items[i];
		}
	}
	const char* Menu::showTitle() const
	{
		return title.displayItem();
	}
	void Menu::displayMenu()
	{
		cout << showTitle();
		if (strlen(showTitle()) > 0)
		{
			cout << endl;
		}
		cout.fill(' ');
		for (unsigned int i = 0; i < count; i++)
		{
			cout.width(2);
			cout << i + 1 << "- " << items[i]->displayItem() << endl;
		}
		cout << " 0- Exit\n> ";
	}
	unsigned int Menu::run()
	{
		displayMenu();
		unsigned int i = inputIntRange(0, count);
		return i;
	}
	unsigned int Menu::operator~()
	{
		unsigned int i = run();
		return i;
	}
	Menu& Menu::operator<<(const char* menuitemConent)
	{
		if (count < MAX_MENU_ITEMS)
		{
			MenuItem* me;
			me = new MenuItem;
			me->set(menuitemConent);
			items[count] = me;
			count++;
		}
		return *this;
	}
	Menu::operator int()
	{
		return count;
	}
	Menu::operator unsigned int()
	{
		return count;
	}
	Menu::operator bool()
	{
		return count > 0;
	}
	ostream& operator<<(ostream& os, const Menu& m)
	{
		os << m.showTitle();
		return os;
	}
	const char* Menu::operator[](unsigned int i) const 
	{
		if (i + 1 > count)
		{
			i = 0;
		}
		return items[i]->displayItem();
	}
	
	void Menu::setTitle(const char* c)
	{
		title.set(c);
	}
}