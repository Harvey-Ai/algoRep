/*
 * Hash.h
 *
 *  Created on: Aug 25, 2014
 *      Author: ufo008ahw
 */

#ifndef HASH_H_
#define HASH_H_

#include <iostream>
#include <cassert>

namespace hash
{
	const int MAXLEN = 49999;
}

template<class T>
class hash
{
	struct bucket
	{
		int value;
		bucket* nextP;
	};

	private:
		int maxLen;
		bucket **hashList;

	public:
		void hash(int maxLen = MAXLEN);
		void insertV(T vlaue);
		void deleteV(T value);
		bool testV(T value);
};

void hash::hash(int maxLen)
{
	assert(maxLen > 0);
	hashList = (int **)malloc(sizeof(int*) * maxLen);

	for(int i = 0;i < maxLen;i++)
		hashList[0] = NULL;
}

template<class T>
void insertV(T vlaue)
{

}




#endif /* HASH_H_ */
