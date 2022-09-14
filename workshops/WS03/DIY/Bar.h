/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/02/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_BAR_H
#define SDDS_BAR_H

namespace sdds{

	class Bar
	{
		char btitle[20];
		char fillc;
		int value;
	public:
		void setEmpty();
		void set(const char* title, char ch, int fvalue);
		bool isValid() const ;
		void draw() const;
	};


}

#endif // !SDDS_BAR_H

