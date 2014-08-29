/*Fast
 	 Created on: Aug 29, 2014
     Author: ufo008ahw
*/

#include "number.h"
#include <iostream>
using namespace std;

/*
 * FastMod, get a^b mod n.
 * Complexity O(log n).
 */
template<class T>
T fastMod(T a, T p, T m)
{
	if (p < 0)
	{
		cout << "error" << endl;
		return -1;
	}

	T res = 1;
	T temp = 1;
	while(p)
	{
		if (p & 0x01)
			res = (res * a) % m;
		temp = (temp * a) % m;
		p /= 2;
	}
	return res;
}
