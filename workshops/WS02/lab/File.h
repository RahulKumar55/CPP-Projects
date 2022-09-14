/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 05/25/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_




namespace sdds {
    

   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char *name);
   bool read(int &snum);
   bool read(char &grade);
}
#endif // !SDDS_FILE_H_
