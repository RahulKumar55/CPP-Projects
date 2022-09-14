//Name: Rahul Kumar
//ID: 157197211
//Email: rkumar141@myseneca.ca
// Date: 06/08/2022
//Section: NKK

#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"
using namespace std;
namespace sdds {
	//Find with 3 parameters
	/* == overloaded operator is required for this function*/
	template<typename T, typename U>
	bool find(T arr[], int in, U key)
	{
		return arr[in] == key;
	}

	//Find with 4 parameters
	/* == overloaded operator is required for this function*/
	template<typename T, typename U, typename K>
	int find(T arr[], int num, U key1, K key2)
	{
		int in = -1;
		for (int i = 0; i < num && in == -1; i++)
		{
			if (arr[i] == key1 && arr[i] == key2)
			{
				in = i;
			}
		}
		return in;
	}

	//Insertion operator
	/* size() member function and [] overloaded operator of collection class is required for this operator overload*/
	template <typename T>
	ostream& operator<<(ostream& os, Collection<T>& c)
	{
		for (int i = 0; i < c.size(); i++)
		{
			os << c[i] << endl;
		}
		return os;
	}

	//Load Collection
	/* += member function of collection class is required for this function*/
	template <typename T>
	const Collection<T>& loadCollection(Collection<T>& c, T t)
	{
		c += t;
		return c;
	}

}
#endif // !SDDS_SEARCH_H_

