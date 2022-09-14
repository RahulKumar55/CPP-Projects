/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 05/25/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstring>
#include "Student.h"
#include "File.h"

using namespace sdds;
using namespace std;
 
namespace sdds
{
	int noOfStudents;
	Student* students;

    void sort()
    {
        int i, j;
        Student temp;
        for (i = noOfStudents - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (students[j].m_grade > students[j + 1].m_grade)
                {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }

    bool load(Student& stu)
    {
        char sname[128];
        int i = 0;
        if (read(sname))
        {
            stu.m_name = new char[strlen(sname) + 1];
            strcpy(stu.m_name, sname);
            i++;
        }

        if (read(stu.m_studentNumber))
        {
            i++;
        }

        if (read(stu.m_grade))
        {
            i++;
        }

        return i == 3;
    }

    bool load(const char* fname)
    {
        int i;
        openFile(fname);
        noOfStudents = noOfRecords();
        students = new Student[noOfStudents];
        for (i = 0; i < noOfStudents && load(students[i]); i++);
        if (i != noOfStudents)
        {
            cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
            return false;
        }
        else
        {
            return true;
        }
    }


    void display(const Student &stud)
    {
        cout << stud.m_name << ", " << stud.m_studentNumber << ": " << stud.m_grade << endl;
    }
    void display()
    {
        int i;
        sort();
        for ( i = 0; i < noOfStudents; i++)
        {
            cout << i + 1 << ": ";
            display(students[i]);
        }
    }

    void deallocateMemory()
    {
        int i;
        for (i = 0; i < noOfStudents; i++)
        {
            delete[] students[i].m_name;
            
        }
        delete[] students;
        closeFile();
    }
}