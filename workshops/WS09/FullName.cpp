/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/27/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "FullName.h"
using namespace std;
using namespace sdds;
namespace sdds
{
    FullName::FullName()
    {
        m_value = nullptr;
    }
    FullName::FullName(const char* name, const char* lastName) : Name(name)
    {
        if (lastName)
        {
            m_value = new char[strlen(lastName) + 1];
            strcpy(m_value, lastName);
        }
        else
        {
            m_value = nullptr;
        }
    }
    FullName::FullName(const FullName& n)
    {
        (Name&)*this = n;
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
    FullName::~FullName()
    {
        delete[] m_value;
        m_value = nullptr;
    }
    FullName& FullName::operator=(const FullName& n)
    {
        (Name&)*this = n;
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

    FullName::operator const char* ()const
    {
        return m_value;
    }
    FullName::operator bool()const
    {
        bool ret = false;
        if (Name::operator bool())
        {
            if (m_value != nullptr)
            {
                ret = true;
            }
        }
        return ret;
    }
    std::ostream& FullName::display(std::ostream& ostr)const
    {
        if (*this)
        {
            Name::display(ostr);
            ostr << " " << m_value;
        }
        return ostr;
    }
    std::istream& FullName::read(std::istream& istr)
    {
        Name::read(istr);
        delete[] m_value;
        char c[255];
        istr.get(c, 255, '\n');
        if (istr)
        {
            istr.ignore();
        }
        m_value = new char[strlen(c) + 1];
        strcpy(m_value, c);
        return istr;
    }

    std::ostream& operator<<(std::ostream& ostr, const FullName& n)
    {
        n.display(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, FullName& n)
    {
        n.read(istr);
        return istr;
    }
}