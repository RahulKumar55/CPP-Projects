/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 05/26/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_BIRTHDATE_H
#define SDDS_BIRTHDATE_H 

namespace sdds
{
	struct Date
	{
		int month;
		int day;
		int year;
	};

	struct Employee
	{
		char* name;
		struct Date date;
	};

	bool beginSearch(const char* filename);
	bool readBirthDate(int month);
	void sort();
	void displayBirthdays();
	void deallocate();
	void endSearch();


	//Extra Functions

	bool load(Employee& em);
	void loadData();
	int noOfRecords();
	bool readNames(char* name);
	bool readDate(int& month, int& day, int& year);
}



#endif