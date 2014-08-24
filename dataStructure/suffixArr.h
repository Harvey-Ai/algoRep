/*
 * suffixArr.h
 *
 *  Created on: Aug 7, 2014
 *      Author: ufo008ahw
 */

#ifndef SUFFIXARR_H_
#define SUFFIXARR_H_

#include <iostream>
#include <vector>
using namespace std;

struct suffixArr
{
// private:
	string rawStr;
	vector<int> rank, sa;
	vector<int> height;
	int strLen;
	void ordinalSort(int shiftLen);

// public:
	suffixArr(char *str);
	void getSA();
	void getHeight();
};

suffixArr::suffixArr(char *str)
{
	rawStr = string(str);
	rank.resize(rawStr.size());
	sa.resize(rawStr.size() + 1);
	height.resize(rawStr.size());
	strLen = rawStr.size();
}

void suffixArr::ordinalSort(int shiftLen)
{
	// need rank;
	vector<int> indexSum;
	indexSum.resize(rawStr.size() + 1);

	vector<int> temp;
	for(int i = rawStr.size() - shiftLen;i < rawStr.size();i++)
		temp.push_back(i);
	for(int i = 1;i < sa.size();i++)
		if (sa[i] >= shiftLen)
			temp.push_back(sa[i] - shiftLen);

	for(int i = 0;i < indexSum.size();i++)
		indexSum[i] = 0;
	for(int i = 0;i < temp.size();i++)
		indexSum[rank[temp[i]]]++;

	for(int i = 1;i < indexSum.size();i++)
		indexSum[i] += indexSum[i - 1];

	vector<int> oldRank = rank;
	for(int i = temp.size() - 1;i >= 0;i--)
		rank[temp[i]] = indexSum[rank[temp[i]]]--;

	for(int i = 1;i < temp.size();i++)
	{
		int index1 = temp[i - 1], index2 = temp[i];
		if (oldRank[index1] != oldRank[index2])
			continue;

		int rank1 = -1;
		if (index1 + shiftLen < rawStr.size())
			rank1 = oldRank[index1 + shiftLen];
		int rank2 = -1;
		if (index2 + shiftLen < rawStr.size())
			rank2 = oldRank[index2 + shiftLen];
		if (rank1 == rank2)
			rank[index1] = rank[index2];
	}
	for(int i = 0;i < rank.size();i++)
		sa[rank[i]] = i;
 }

void suffixArr::getSA()
{
	vector<int> indexSum;
	indexSum.resize(256);

	for(int i = 0;i < rawStr.size();i++)
		indexSum[rawStr[i]]++;
	for(int i = 1;i < indexSum.size();i++)
		indexSum[i] += indexSum[i - 1];
	for(int i = 0;i < rawStr.size();i++)
	{
		rank[i] = indexSum[rawStr[i]]--;
		sa[rank[i]] = i;
	}
	for(int j = 1;j < rawStr.size();j *= 2)
		ordinalSort(j);
}


void suffixArr::getHeight()
{
	int k = 0;
	for(int i = 0;i < sa.size();i++)
	{
		if (k) k--;
		if (rank[i] == 1)
		{
			height[i] = 0;
			continue;
		}
		while(i + k < rawStr.size() && sa[rank[i] - 1] + k < rawStr.size()
			&& rawStr[i + k] == rawStr[sa[rank[i] - 1] + k])
			k++;
		height[i] = k;
	}
}



#endif /* SUFFIXARR_H_ */
