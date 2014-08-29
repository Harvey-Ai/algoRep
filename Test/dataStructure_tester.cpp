/*
 * dataStructure_tester.cpp
 *
 *  Created on: Aug 29, 2014
 *      Author: ufo008ahw
 */


#include "dataStructure_tester.h"
using namespace std;

static int disjointSetTester();
static int segmentTreeTester();
static int suffixArrTester();

void dataStructure_test()
{
	cout << "----------- data structure test -----------" << endl;
	disjointSetTester();
	segMentTreeTester();
	suffixArrTester();
}

int disjointSetTester()
{
	cout << endl;
	cout << "Testing disjoint set:" << endl;
	disjointSet<int> mySet(100);
	mySet.insert(10);
	cout << "After insert 10, set 10 contains " << mySet.getSetNum(10)
			<< ", " << (mySet.getSetNum(10) == 1 ? "YES" : "NO") << endl;
	mySet.insert(20);
	cout << "After insert 20, set 20 contains " << mySet.getSetNum(20)
			<< ", " << (mySet.getSetNum(20) == 1 ? "YES" : "NO") << endl;
	mySet.merge(10, 20);
	cout << "After merge 10 and 20, set 10 contains " << mySet.getSetNum(10)
			<< ", " << (mySet.getSetNum(10) == 2 ? "YES" : "NO") << endl;
	return 0;
}

int segmentTreeTester()
{
	cout << endl;
	cout << "Testing segmentTree:" << endl;
	segTree<int> st(1, 10, 1);
	cout << "Initialize 1-10 by value 1, the sum is " << st.query(1, 10) << ", "
			<< (st.query(1, 10) == 10 ? "YES" : "NO") << endl;
	st.insert(1, 3, 20);
	cout << "After insert 1-3 by value 20, the sum is " << st.query(1, 10) << ", "
				<< (st.query(1, 10) == 67 ? "YES" : "NO") << endl;
	st.insert(6, 9, 5);
	cout << "After insert 6-9 by value 5, the sum is " << st.query(1, 10) << ", "
				<< (st.query(1, 10) == 83 ? "YES" : "NO") << endl;
	return 0;
}


int suffixArrTester()
{
	cout << endl;
	cout << "Testing suffixArr:" << endl;
	string str = "hahahawww";
	suffixArr oneSuffixArr((char *)str.c_str());
	oneSuffixArr.getSA();
	oneSuffixArr.getHeight();

	cout << "SA:" << endl;
	for(int i = 1;i <= str.size();i++)
		cout << oneSuffixArr.sa[i] << " " <<  str.substr(oneSuffixArr.sa[i]) << endl;
	cout << "Height:" << endl;
	for(int i = 0;i < oneSuffixArr.height.size();i++)
		cout << oneSuffixArr.height[i] << endl;
	return 0;
}
