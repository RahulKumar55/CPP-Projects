/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 07/29/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
#include "Utils.h"
namespace sdds {

    void clearInputBuffer(void)
    {
        // Discard all remaining char's from the standard input buffer:
        while (getchar() != '\n')
        {
            ; // do nothing!
        }
    }

    int inputInt(void)
    {
        int input;
        char a = 'a';

        do
        {
            
            scanf("%d%c", &input, &a);
            if (a != '\n')
            {
                clearInputBuffer();
                cout << "Invalid Selection, try again: ";
            }
        } while (a != '\n');
        return input;
    }

    int inputIntRange(int low, int high)
    {
        int irange;
        do
        {
            irange = inputInt();
            if (irange < low || irange > high)
            {
                cout << "Invalid Selection, try again: ";
            }
        } while (irange < low || irange > high);
        return irange;
    }
}