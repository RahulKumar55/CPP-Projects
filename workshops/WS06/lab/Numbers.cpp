/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/30/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {

  
   Numbers::Numbers() {
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
      
   }
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }



   /////////////////////////
   // Code written by me

   Numbers::Numbers(const Numbers& num1){
       setEmpty();
       m_isOriginal = false;
       *this = num1;
   }
   Numbers& Numbers::operator=(const Numbers& num1){
       
       delete[] m_numbers;
       m_numCount = num1.m_numCount;
       m_numbers = new double[m_numCount];
       for (int i = 0; i < m_numCount; i++)
       {
           m_numbers[i] = num1.m_numbers[i];
       }
       
       return *this;
   }
   int Numbers::numberCount(){
       int i = 0;
       char j;
       ifstream f(m_filename);
       
       while (f)
       {
           j = f.get();
           if (j == '\n')
           {
               i++;
           } 
       }
       
       return i;
   }
   bool Numbers::load(){
       int i = 0;
       if (m_numCount > 0)
       {
           m_numbers = new double[m_numCount];

           ifstream f(m_filename);
           while (f)
           {
               f >> m_numbers[i++];  
           }
           i--;
       }
       return i == m_numCount;
   }
   void Numbers::save(){
       if (m_isOriginal && !isEmpty())
       {
           ofstream t(m_filename);
           for (int i = 0; i < m_numCount; i++)
           {
               t << m_numbers[i] << "\n";
           }
       }
   }
   Numbers& Numbers::operator+=(double val)
   {
       if (!isEmpty())
       {
           double* temp;
           temp = new double[m_numCount + 1];
           for (int i = 0; i < m_numCount; i++)
           {
               temp[i] = m_numbers[i];
           }
           temp[m_numCount] = val;
           m_numCount++;
           delete[] m_numbers;
           m_numbers = new double[m_numCount];
           for (int i = 0; i < m_numCount; i++)
           {
               m_numbers[i] = temp[i];
           }
           delete[] temp;
           sort();
       }
       return *this;
   }
   ostream& Numbers::display(ostream& ostr) const{
       if (isEmpty())
       {
           ostr << "Empty list";
       }
       else
       {
           ostr << "=========================\n";
           if (m_isOriginal)
           {
               ostr << m_filename << "\n" << m_numbers[0];

           }
           else
           {
               ostr << "*** COPY ***\n" << m_numbers[0];
           }
           for (int i = 1; i < m_numCount; i++)
           {
               ostr << ", " << m_numbers[i];
           }
           ostr << "\n-------------------------\n";
           ostr << "Total of " << m_numCount << " number(s)\n";
           ostr.width(17);
           ostr.setf(ios::left);
           ostr << "Largest number: " << max() << endl;
           ostr.width(17);
           ostr << "Smallest number: " << min() << endl;
           ostr.width(17);
           ostr << "Average : " << average() << endl;
           ostr.unsetf(ios::left);
           ostr << "=========================";
       }
       return ostr;
   }

   ostream& operator<<(ostream& os, const Numbers& N){
       N.display(os);
       return os;
   }
   istream& operator>>(istream& istr, Numbers& N){
       double d;
       istr >> d;
       N += d;
       return istr;
   }


   
}
