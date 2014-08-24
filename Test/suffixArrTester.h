/*
 * suffixArr.h
 *
 *  Created on: Aug 16, 2014
 *      Author: ufo008ahw
 */

#ifndef SUFFIXARRTESTER_H_
#define SUFFIXARRTESTER_H_

#include "../dataStruct/suffixArr.h"
#include <iostream>
#include <string>
using namespace std;

static int suffixArrTester()
{
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


#endif /* SUFFIXARR_H_ */
