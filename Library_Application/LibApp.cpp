/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/29/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "LibApp.h"
#include"PublicationSelector.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

namespace sdds
{
	bool LibApp::confirm(const char* message)
	{
		Menu me(message);
		me << "Yes";
		return me.run() == 1;
	}
	void LibApp::load()
	{
		cout << "Loading Data" << endl;
		ifstream inf(m_file);
		char type{};
		int i;
		for (i = 0; inf; i++)
		{
			inf >> type;
			inf.ignore();
			if (inf)
			{
				if (type == 'P')
					PPA[i] = new Publication;
				else if (type == 'B')
					PPA[i] = new Book;
				if (PPA[i])
				{
					inf >> *PPA[i];
					NOLP++;
				}
			}
		}
		LLRN = PPA[NOLP - 1]->getRef();
	}
	void LibApp::save()
	{
		cout << "Saving Data" << endl;
		ofstream ouf(m_file);
		for (int i = 0; i < NOLP; i++)
		{
			if (PPA[i]->getRef() != 0)
			{
				ouf << *PPA[i];
				ouf << endl;
			}
		}
	}
	int LibApp::search(const int s)
	{
		int ref = 0;
		PublicationSelector ps("Select one of the following found matches:", 15);
		char title[257];
		int j = p_type.run();
		cout << "Publication Title: ";
		cin.get(title, 256, '\n');
		cin.clear();
		cin.ignore(1000, '\n');
		char t = '0';

		if (j == 1)
		{
			t = 'B';
		}
		else if (j == 2)
		{
			t = 'P';
		}

		switch (s)
		{
		case 0:
			for (int i = 0; i < NOLP; i++)
			{
				if (PPA[i]->getRef() && PPA[i]->type() == t)
				{
					if (PPA[i]->operator==(title))
					{
						ps << PPA[i];
					}
				}
			}
			break;
		case 1:
			for (int i = 0; i < NOLP; i++)
			{
				if (PPA[i]->onLoan())
				{
					if (PPA[i]->getRef() && PPA[i]->type() == t)
					{
						if (PPA[i]->operator==(title))
						{
							ps << PPA[i];
						}
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < NOLP; i++)
			{
				if (!PPA[i]->onLoan())
				{
					if (PPA[i]->getRef() && PPA[i]->type() == t)
					{
						if (PPA[i]->operator==(title))
						{
							ps << PPA[i];
						}
					}
				}
			}
			break;
		default:
			break;
		}

		if (ps)
		{
			ps.sort(); // sort them based on date and title
			ref = ps.run(); // display the publications and select one
			if (!ref)
			{
				cout << "Aborted!" << endl;
			}
			else
			{
				for (int i = 0; i < NOLP; i++)
				{
					if (PPA[i]->getRef() == ref)
					{
						cout << *PPA[i] << endl;
					}
				}
			}
		}
		else
		{
			cout << "No matches found!\n";
		}
		return ref;
	}
	void LibApp::returnPub()
	{
		Date today;
		cout << "Return publication to the library" << endl;
		int j = search(1);
		if (j && confirm("Return Publication?"))
		{
			for (int i = 0; i < NOLP && j; i++)
			{
				if (PPA[i]->getRef() == j)
				{
					int late = today - PPA[i]->checkoutDate();
					if (late > 15)
					{
						double pen = (late - 15) * 0.5;
						cout.setf(ios::fixed);
						cout.precision(2);
						cout << "Please pay $"
							<< pen << " penalty for being "<< late - 15 <<" days late!\n";
					}
					PPA[i]->set(0);
					j = 0;
					cout << "Publication returned" << endl;
					m_changed = true;
				}
			}
		}
	}
	void LibApp::newPublication()
	{
		if (NOLP == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!" << endl;
		}
		else
		{
			cout << "Adding new publication to the library" << endl;
			int j = p_type.run();
			if (j != 0)
			{
				Publication* s{};
				switch (j)
				{
				case 1:
					s = new Book;
					break;
				case 2:
					s = new Publication;
				default:
					break;
				}
				cin >> *s;
				if (cin.fail())
				{
					cin.ignore(1000, '\n');
					cin.clear();
					cout << "Aborted!" << endl;
				}
				else
				{
					if (confirm("Add this publication to the library?"))
					{
						if (s)
						{
							LLRN++;
							s->setRef(LLRN);
							PPA[NOLP] = s;
							NOLP++;
							m_changed = true;
							cout << "Publication added" << endl;
						}
						else
						{
							cout << "Failed to add publication!" << endl;
							delete s;
						}
					}
					else
					{
						cout << "Aborted!" << endl;
					}
				}
			}
			else
			{
				cout << "Aborted!" << endl;
			}
		}
	}
	void LibApp::removePublication()
	{
		cout << "Removing publication from the library" << endl;
		int j = 0;
		j = search(0);
		if (j && confirm("Remove this publication from the library?"))
		{
			for (int i = 0; i < NOLP && j; i++)
			{
				if (PPA[i]->getRef() == j)
				{
					PPA[i]->setRef(0);
					j = 0;
					m_changed = true;
					cout << "Publication removed" << endl;
				}
			}
		}
	}
	void LibApp::checkOutPub()
	{
		int mem = 0;
		cout << "Checkout publication from the library\n";
		int j = search(2);
		if (j && confirm("Check out publication?"))
		{
			cout << "Enter Membership number: ";
			do
			{
				cin >> mem;
				if (mem < 10000 || mem > 99999)
				{
					mem = 0;
					cout << "Invalid membership number, try again: ";
				}
				else
				{
					for (int i = 0; i < NOLP && j; i++)
					{
						if (PPA[i]->getRef() == j)
						{
							PPA[i]->set(mem);
							j = 0;
							m_changed = true;
							cout << "Publication checked out" << endl;
						}
					}
				}
			} while (!mem);
		}
	}

	Publication* LibApp::getPub(int libRef)
	{
		int j = 0;
		for (int i = 0; i < NOLP && !j; i++)
		{
			if (libRef == PPA[i]->getRef())
			{
				j = i;
			}
		}
		return PPA[j];
	}

	LibApp::LibApp()
	{
		m_changed = false;
		m_mainMenu.setTitle("Seneca Library Application");
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		p_type.setTitle("Choose the type of publication:");
		p_type << "Book" << "Publication";
		strcpy(m_file, "");
		NOLP = 0;
		LLRN = 0;
		for (int i = 0; i < SDDS_LIBRARY_CAPACITY; i++)
		{
			PPA[i] = nullptr;
		}
		load();
	}

	LibApp::LibApp(const char* file)
	{
		strcpy(m_file, file);
		m_changed = false;
		m_mainMenu.setTitle("Seneca Library Application");
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		p_type.setTitle("Choose the type of publication:");
		p_type << "Book" << "Publication";
		NOLP = 0;
		LLRN = 0;
		for (int i = 0; i < SDDS_LIBRARY_CAPACITY; i++)
		{
			PPA[i] = nullptr;
		}
		load();
	}

	LibApp::~LibApp()
	{
		for (int i = 0; i < NOLP; i++)
		{
			if (PPA[i])
			{
				delete PPA[i];
			}
		}
	}

	void LibApp::run()
	{
		int i = -1;
		do
		{
			if (i != -1)
			{
				cout << endl;
			}
			i = m_mainMenu.run();
			switch (i)
			{
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			default:
				if (m_changed)
				{
					int j = m_exitMenu.run();
					switch (j)
					{
					case 0:
						confirm("This will discard all the changes are you sure?");
						break;
					case 1:
						save();
						break;
					default:
						i = 1;
						break;
					}
				}
				break;
			}

		} while (i);

		cout << "\n-------------------------------------------\n" << "Thanks for using Seneca Library Application" << endl;
	}
}