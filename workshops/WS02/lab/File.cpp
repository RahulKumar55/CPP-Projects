/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 05/25/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

using namespace sdds;

namespace sdds {

   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(char* name)
   {
       return fscanf(fptr, "%[^,],", name) == 1;
   }
   bool read(int &snum){
       
       return fscanf(fptr, "%d,", &snum) == 1;
   }
   bool read(char &grade){
       return fscanf(fptr, "%c\n", &grade) == 1;
   }

}