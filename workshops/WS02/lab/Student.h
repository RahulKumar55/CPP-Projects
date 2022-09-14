/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 05/25/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_


namespace sdds
{
    struct Student
    {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };
	
    void sort();
    bool load(Student&);
    bool load(const char*);
    void display(const Student&);
    void display();
    void deallocateMemory();

}




#endif