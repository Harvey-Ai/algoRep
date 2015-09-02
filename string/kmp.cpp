#include "myString.h"

static void getNext(const string &str, vector<int> &next)
{
	int k = -1;
	next.push_back(-1);

	for(int i = 1;i < str.size();i++)
	{
		while(k >= 0 && str[i] != str[k + 1])
			k = next[k];

		if (str[i] == str[k + 1])
			k++;
		next.push_back(k);
	}
}

int kmp(const string &mStr, const string &tStr, vector<int> &hint)
{
	vector<int> next
	getNext(tStr, next);
	hint.resize(0);

	int k = -1;
	for(int i = 0;i < mStr.size();i++)
	{
		while(k >= 0 && tStr[k + 1] != mStr[i])
			k = next[k];

		if (mStr[i] == tStr[k + 1])
			k++;

		if (k == tStr.size())
		{
			hint.push_back(i);
			k = next[tStr.size() - 1];
		}
	}

	return hint.size();
}
