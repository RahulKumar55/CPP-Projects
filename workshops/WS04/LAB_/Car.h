/*Name: Rahul Kumar
  Email: rkumar141@myseneca.ca
  Student ID: 157197211
  Section: NKK
  Date: 06/08/2022

  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds
{
	class Car
	{
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo()
		{
			
			m_type = nullptr;
			m_brand = nullptr;
			m_model = nullptr;
			m_year = 0;
			m_code = 0;
			m_price = 0;
		}
	public:
		Car();
		Car(const char* type,
			const char* brand,
			const char* model,
			int year = 2022,
			int code = 100,
			double price = 1);
		~Car();
		Car& setInfo(const char* type,
			const char* brand,
			const char* model,
			int year,
			int code,
			double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const Car& car) const;
	};

	bool has_similar(const Car car[], const int num_cars);
	bool has_invalid(const Car car[], const int num_cars);
	void print(const Car car[], const int num_cars);
}

#endif // !SDDS_CAR_H

