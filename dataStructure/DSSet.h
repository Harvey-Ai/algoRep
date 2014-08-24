#include <map>
#include <iostream>
#include <cstdlib>
using namespace std;

template<typename T>
class DSSet
{
	private:
		int setLen;
		int nextIndex;
		map<T, int> setMap;
		int *setNumP;

	public:
		explicit DSSet();
		explicit DSSet(int len);
		~DSSet();
		int intialize(int len);
		int insert(T element);
		int getFa(T element);
		int getSetNum(T element);
		int merge(T ele1, T ele2);
};

template<typename T>
DSSet<T>::DSSet()
{
	setLen = -1;
	nextIndex = -1;
	setNumP = NULL;
}

template<typename T>
DSSet<T>::DSSet(int len)
{
	setNumP = (int*)malloc(sizeof(int) * len);
	if (setNumP != NULL)
	{
		for(int i = 0;i < len;i++)
			setNumP[i] = -1;
		setLen = len;
		nextIndex = 0;
	}
	else
	{
		setLen = -1;
		nextIndex = -1;
	}
}

template<typename T>
DSSet<T>::~DSSet()
{
	if (setNumP != NULL)
		free(setNumP);
}

template<typename T>
int DSSet<T>::intialize(int len)
{
	setMap.clear();
	if (setNumP)
		free(setNumP);
	setNumP = (int *)malloc(sizeof(int) * len);
	if (setNumP != NULL)
	{
		for(int i = 0;i < len;i++)
			setNumP[i] = -1;
		setLen = len;
		nextIndex = 0;
		return len;
	}
	else
	{
		nextIndex = -1;
		setLen = -1;
		return -1;
	}
}

template<typename T>
int DSSet<T>::insert(T element)
{
	if (nextIndex == setLen)
		return -1;

	if (setMap.find(element) == setMap.end())
		setMap[element] = nextIndex++;
	return 0;
}

template<typename T>
int DSSet<T>::getFa(T element)
{
	if (setMap.find(element) == setMap.end())
		return -1;

	int id = setMap[element];
	while (setNumP[id] >= 0)
		id = setNumP[id];

	int faId = id;
	// compress path
	while (setNumP[id] >= 0)
	{
		int temp = setNumP[id];
		setNumP[id] = faId;
		id = temp;
	}
	return faId;
}

template<typename T>
int DSSet<T>::getSetNum(T Ele)
{
	int id = getFa(Ele);
	if (id == -1)
		return 0;

	else
		return -setNumP[id];
}

template<typename T>
int DSSet<T>::merge(T ele1, T ele2)
{
	int id1 = getFa(ele1);
	int id2 = getFa(ele2);

	if (id1 == -1 || id2 == -1)
		return -1;

	if (id1 == id2)
		return 0;

	if (setNumP[id1] < setNumP[id2])
	{
		setNumP[id1] += setNumP[id2];
		setNumP[id2] = id1;
	}
	else
	{
		setNumP[id2] += setNumP[id1];
		setNumP[id1] = id2;
	}
	return 0;
}
