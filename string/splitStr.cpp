/*
 * splitStr.c
 *
 *  Created on: Aug 25, 2014
 *      Author: ufo008ahw
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "myString.h"
using namespace std;

int strtok_split()
{
	char mainStr[] = "str1abcstr2abcstr3abc";
	char* splitStr = "abc";

	char *p = strtok(mainStr, splitStr);
	while(p != NULL)
	{
		cout << p << endl;
		p = strtok(NULL, splitStr);
	}
	cout << mainStr << endl;
	return 0;
}

int strstr_split()
{
	char mainStr[] = "str1abcstr2abcstr3abc";
	char* splitStr = "abc";

	char *bPos = mainStr;
	while(*bPos != '\0')
	{
		char *ePos = strstr(bPos, splitStr);
		for(;bPos != ePos;bPos++)
			putchar(*bPos);
		putchar('\n');
		bPos += strlen(splitStr);
	}
	return 0;
}

int find_split()
{
	string mainStr = "str1abcstr2abcstr3abc";
	string splitStr = "abc";

	int bPos = 0;
	while(bPos < mainStr.size())
	{
		int ePos = mainStr.find(splitStr, bPos);
		if (ePos == string::npos)
			ePos = mainStr.size();
		cout << mainStr.substr(bPos, ePos - bPos) << endl;
		bPos = ePos + splitStr.size();
	}
	return 0;
}

