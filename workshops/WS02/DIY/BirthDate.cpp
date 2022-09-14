/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 05/26/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <iostream>
#include "BirthDate.h"

using namespace std;
using namespace sdds;

namespace sdds
{
    FILE* fptr =  NULL; 

	int noOfEmployees;
	Employee* employees;
	int foundbirthdays;
	int tmonth;


	bool beginSearch(const char* filename)
	{
		fptr = fopen(filename, "r");
		if (fptr != NULL)
		{
			cout << "Birthdate search program" << endl;
			loadData();
			return true;
		}
		else
		{
			cout << "Data file " << filename << " not found!" << endl;
			return false;
		}
	}

	bool readBirthDate(int month)
	{
		int i;
		bool found = false;
		foundbirthdays = 0;
		tmonth = month;
		for ( i = 0; i < noOfEmployees; i++)
		{
			if (employees[i].date.month == month)
			{
				found = true;
				foundbirthdays++;
			}
		}
		return found;
	}

	void sort()
	{
		int i, j;
		Employee temp;
		for (i = noOfEmployees - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (employees[j].date.year > employees[j + 1].date.year)
				{
					temp = employees[j];
					employees[j] = employees[j + 1];
					employees[j + 1] = temp;
				}
			}
		}
	}

	void displayBirthdays()
	{
		int i, j = 0;
		cout << foundbirthdays << " birthdates found:" << endl;

		for ( i = 0; i < noOfEmployees; i++)
		{
			if (employees[i].date.month == tmonth)
			{
				j++;
				cout << j << ") " << employees[i].name << ":\n"
					<< employees[i].date.year << '-' << employees[i].date.month << '-'
					<< employees[i].date.day << '\n' << "===================================" << endl;
			}
		}
	}

	void deallocate()
	{
		int i;
		for ( i = 0; i < noOfEmployees; i++)
		{
			delete[] employees[i].name;
		}
		delete[] employees;
	}

	void endSearch()
	{
		if (fptr) fclose(fptr);
		cout << "Birthdate Search Program Closed." << endl;
	}



	//Extra Functions


	bool load(Employee &em)
	{
		char ename[30];
		int i = 0;
		if (readNames(ename))
		{
			em.name = new char[strlen(ename) + 1];
			strcpy(em.name, ename);
			i++;
		}
		if (readDate(em.date.month, em.date.day, em.date.year))
		{
			i++;
		}

		return i == 2;
	}

	void loadData()
	{
		int i;
		noOfEmployees = noOfRecords();
		employees = new Employee[noOfEmployees];
		for (i = 0; i < noOfEmployees && load(employees[i]); i++);
		if (i != noOfEmployees)
		{
			cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
			
		}
	}


	int noOfRecords()
	{
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1)
		{
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}

	bool readNames(char* name)
	{
		return fscanf(fptr, "%[^,],", name) == 1;
	}

	bool readDate(int& month, int& day, int& year)
	{
		return fscanf(fptr, "%d/%d/%d\n", &month, &day, &year) == 3;
	}

}