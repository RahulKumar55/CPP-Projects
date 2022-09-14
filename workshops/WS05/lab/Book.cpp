/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/13/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters=0;
		m_num_pages=0;
	}

	Book::Book() {
		init_book();
	}

	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_) {
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

	// Print a book summary
	void Book::summary() {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}

	///////////////////////////////////
	//Code Written by me
	///////////////////////////////////
	
	Book Book::operator++(int){
		Book bk = *this;
		m_num_chapters += 1;
		return bk;
	}

	int Book::add_chapter(Chapter* chapter)
	{
		for (int i = 0; i <MAX_NUM_CHAPTERS; i++)
		{
			if (strlen((const char*)chapter) > 0)
			{
				if (strlen((const char*)m_chapters[i]) == 0)
				{
					m_chapters[i] = *chapter;
					m_num_pages += (int)m_chapters[i];
					(* this)++;
					i = MAX_NUM_CHAPTERS;
				}
			}
			
		}
		return m_num_chapters;
	}

	std::ostream& Book::display(std::ostream& os)const
	{
		os << "Title:'" << (const char*)*this << "'\n";
		os << "Author: '" << m_author << "'\n";
		for (int i = 0; i < m_num_chapters; i++)
		{
			os << m_chapters[i];
		}
		return os;
	}

	Book::operator int() const{ 
		return m_num_chapters;
	}

	Book::operator bool() const{ 
		int res = 1;
		if (strlen(m_title) != 0 && strlen(m_author) !=0 && m_num_chapters !=0)
		{
			res = 1;
		}
		for (int i = 0; i < MAX_NUM_CHAPTERS && res == 1; i++)
		{
			if ((int)m_chapters[i] > 0)
			{
				res = 2;
			}
		}
		return res == 2;
	}

	Book::operator double() const{
		return m_price;
	}

	Book::operator const char* () const{ 
		return m_title;
	}

	bool Book::operator !() const{ 
		bool res = true;
		if (*this)
		{
			res = false;
		}
		return res;
	}

	Book& Book::operator +=(Chapter& cha){
		add_chapter(&cha);
		return *this;
	}

	Book& Book::operator -=(double dis){ 
		m_price -= dis;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Book& bo)
	{
		bo.display(os);
		return os;
	}
}
