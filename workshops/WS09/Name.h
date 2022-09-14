/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/27/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>
namespace sdds
{
    class Name
    {
        char* m_value;
    public:
        Name();
        Name(const char* name);

        Name(const Name& n);
        virtual ~Name();
        Name& operator=(const Name& n);

        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);
    };
    std::ostream& operator<<(std::ostream& ostr, const Name& n);
    std::istream& operator>>(std::istream& istr, Name& n);
}
#endif // !SDDS_NAME_H
