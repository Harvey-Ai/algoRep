/*
 * Monte Carlo.cpp
 *
 *  Created on: Sep 9, 2014
 *      Author: ufo008ahw
 */


#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


/*
 * Note: calulate number influent the accurate, rectSize influence the expectation.
 */
double calPI(int calNum, int rectSize)
{
	time_t seed = time(&seed);
	srand((int)seed);

	int shotNum = 0;
	long long radius = rectSize;
	for(int i = 0;i < calNum;i++)
	{
		long long posX = random() % (radius + 1);
		long long posY = random() % (radius + 1);

		if (posX * posX + posY * posY <= radius * radius)
			shotNum++;
	}

	return shotNum * 4.0 / calNum;
}


/*
 * Monte carlo methond use the probability' theory: law of large numbers.
 * Description: More independent trails will result in a stable expectation.
 *
 */

int monteCarlo()
{
	const double PI = 3.1415926;
	const int itNum = 1000000000;
	const double rectSize = 10000;

	cout << endl;
	cout << "----------- Monte Carlo test -----------" << endl;
	cout << "Calculate PI = " << calPI(itNum, rectSize) << " in " << rectSize << "rectangle "
			<< "in "<< itNum << "times" << endl;

	return 0;
}
