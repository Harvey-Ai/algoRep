#include <vector>
#include <string>
#include "DSSetTester.h"
#include "SegTreeTester.h"
#include "suffixArrTester.h"
using namespace std;

typedef int (*testerFunType)();
static vector<testerFunType> testFunc;
static vector<string> testFuncStr;

int loadTester()
{
	testFunc.push_back(DSSetTester);
	testFuncStr.push_back("DSSetTester");
	testFunc.push_back(SegTreeTester);
	testFuncStr.push_back("SegTreeTester");
	testFunc.push_back(suffixArrTester);
	testFuncStr.push_back("suffixArrTester");
	return 0;
}

int runTester()
{
	for(int i = 0;i < testFunc.size();i++)
	{
		if (testFunc[i]() != 0)
			cout << testFuncStr[i] << " error" << endl;
	}
	return 0;
}
