/*
 * number_tester.cpp
 *
 *  Created on: Aug 29, 2014
 *      Author: ufo008ahw
 */

#include "number_tester.h"

void number_test()
{
	cout << "----------- number test -----------" << endl;
	cout << "fast mod" << "7 ^ 100 % 10 =" << fastMod(7, 100, 10) << ", " <<
			(fastMod(7, 100, 10) == 6 ? "YES" : "NO") << endl;
	cout << "gcd" << "gcd(16, 12) = " << gcd(16, 12) << ", " <<
			(gcd(16, 12) == 4 ? "YES" : "NO") << endl;
}
