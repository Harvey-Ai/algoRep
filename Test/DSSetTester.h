#include "../dataStruct/DSSet.h"
#include <iostream>
using namespace std;

static int DSSetTester()
{
	DSSet<int> dsSet1(100);
	dsSet1.insert(10);
	dsSet1.insert(20);
	//cout << "set(10): " << dsSet1.getSetNum(10) << endl;
	//cout << "set(20): " << dsSet1.getSetNum(20) << endl;
	dsSet1.merge(10, 20);
	//cout << "after merge, set(10): " << dsSet1.getSetNum(20) << endl;
	return 0;
}

