/*
 * SegTreeTester.h
 *
 *  Created on: Aug 6, 2014
 *      Author: ufo008ahw
 */

#ifndef SEGTREETESTER_H_
#define SEGTREETESTER_H_

#include "../dataStruct/SegTree.h"
int aggFunc(int v1, int num1, int v2, int num2)
{
	//cout << v1 * num1 + v2 * num2 << endl;
	return v1 * num1 + v2 * num2;
}

static int SegTreeTester()
{
	segTree<int> st(1, 10, 1, aggFunc);
//	cout << st.query(1, 10) << endl;
	st.insert(1, 3, 20);
	st.insert(6, 9, 5);
//	cout << st.query(1, 10) << endl;
	return 0;
}

#endif /* SEGTREETESTER_H_ */
