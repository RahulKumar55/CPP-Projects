/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/29/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;

	class Menu;
	class MenuItem
	{
	private:
		char* item;
		MenuItem();
		~MenuItem();
		void set(const char* it);
		operator bool();
		operator const char* ();
		const char* displayItem() const;
		friend class Menu;
	};

	class Menu
	{
		MenuItem title;
		MenuItem* items[MAX_MENU_ITEMS];
		unsigned int count;
	public:
		Menu();
		Menu(const char* ti);
		~Menu();
		const char* showTitle() const;
		void displayMenu();
		unsigned int run();
		unsigned int operator~();
		Menu& operator<<(const char* menuitemConent);
		operator int();
		operator unsigned int();
		operator bool();
		const char* operator[](unsigned int i) const;
		void setTitle(const char* c);
	};
	std::ostream& operator<<(std::ostream& os, const Menu& m);
}
#endif // !SDDS_MENU_H
