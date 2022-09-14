/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/27/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Name.h"
using namespace std;
using namespace sdds;
namespace sdds
{
    Name::Name()
    {
        m_value = nullptr;
    }
    Name::Name(const char* name)
    {
        if (name)
        {
            m_value = new char[strlen(name) + 1];
            strcpy(m_value, name);
        }
        else
        {
            m_value = nullptr;
        }
    }
    Name::Name(const Name& n)
    {
        *this = n;
    }
    Name::~Name()
    {
        delete[] m_value;
        m_value = nullptr;
    }
    Name& Name::operator=(const Name& n)
    {
        if (this != &n)
        {
            delete[] m_value;
            if (n.m_value)
            {
                
                m_value = new char[strlen(n.m_value) + 1];
                strcpy(m_value, n.m_value);
            }
            else
            {
                m_value = nullptr;
            }
        }
        return *this;
    }

    Name::operator const char* ()const
    {
        return m_value;
    }
    Name::operator bool()const
    {
        return m_value != nullptr;
    }
    std::ostream& Name::display(std::ostream& ostr)const
    {
        if (*this)
        {
            ostr << m_value;
        }
        return ostr;
    }
    std::istream& Name::read(std::istream& istr)
    {
        delete[] m_value;
        char c[255];
        istr.get(c, 255, ' ');
        if (istr)
        {
            istr.ignore();
        }
        m_value = new char[strlen(c) + 1];
        strcpy(m_value, c);
        return istr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Name& n)
    {
        n.display(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Name& n)
    {
        n.read(istr);
        return istr;
    }
}