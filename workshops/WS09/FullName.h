/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/27/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef SDDS_FULLNAME_H
#define SDDS_FULLNAME_H
#include "Name.h"
namespace sdds
{
    class FullName : public Name
    {
        char* m_value;
    public:
        FullName();
        FullName(const char* name, const char* lastName);
        FullName(const FullName& n);
        virtual ~FullName();
        FullName& operator=(const FullName& n);

        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);
    };
    std::ostream& operator<<(std::ostream& ostr, const FullName& n);
    std::istream& operator>>(std::istream& istr, FullName& n);
}
#endif // !SDDS_FULLNAME_H