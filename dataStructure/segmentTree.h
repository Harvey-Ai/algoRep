#include <iostream>
#include <cstdio>
using namespace std;

int addFunc(int v1, int num1, int v2, int num2)
{
	//cout << v1 * num1 + v2 * num2 << endl;
	return v1 * num1 + v2 * num2;
}

template<typename T>
class segTree
{
	typedef T (*aggFuncType)(T v1, int num1, T v2, int num2);
	aggFuncType aggFunc;
	private:
		segTree *leftTree, *rightTree;
		T aggValue;
		T value;
		int lazyOp;
		int LRange, RRange, midRange;
	public:
		segTree(int leftR, int rightR, T v, aggFuncType fun = addFunc);
		int insert(int leftR, int rightR, T v);
		T query(int leftR, int rightR);
};

template<typename T>
segTree<T>::segTree(int leftR, int rightR, T v, aggFuncType fun)
{
	leftTree = rightTree = NULL;
	LRange = leftR, RRange = rightR;
	midRange = (LRange + RRange) / 2;
	if (LRange != RRange)
	{
		leftTree = new segTree(LRange, midRange, v, fun);
		rightTree = new segTree(midRange + 1, RRange, v, fun);
	}
	value = v;
	aggFunc = fun;
	aggValue = aggFunc(v, RRange - LRange + 1, 0, 0);
	lazyOp = 0;
}

template<typename T>
int segTree<T>::insert(int leftR, int rightR, T v)
{
	if (leftR < LRange)
		leftR = LRange;
	if (rightR > RRange)
		rightR = RRange;

	if (leftR == LRange && rightR == RRange)
	{
		value = v;
		aggValue = aggFunc(v, RRange - LRange + 1, 0, 0);
		lazyOp = 1;
		return 0;
	}
	else if (leftR > midRange)
		rightTree->insert(leftR, rightR, v);
	else if (rightR <= midRange)
		leftTree->insert(leftR, rightR, v);
	else
	{
		leftTree->insert(leftR, midRange, v);
		rightTree->insert(midRange + 1, rightR, v);
	}

	T leftAggValue = query(LRange, midRange);
	T rightAggValue = query(midRange + 1, RRange);
	aggValue = aggFunc(leftAggValue, 1, rightAggValue, 1);
	lazyOp = 0;
	return 0;
}

template<typename T>
T segTree<T>::query(int leftR, int rightR)
{
	if (leftR < LRange)
		leftR = LRange;
	if (rightR > RRange)
		rightR = RRange;

	if (leftR == LRange && rightR == RRange)
		return aggValue;

	if (lazyOp)
	{
		insert(LRange, RRange, value);
		lazyOp = 0;
	}

	if (rightR <= midRange)
		aggValue = leftTree->query(leftR, rightR);
	else if (leftR > midRange)
		aggValue = rightTree->query(leftR, rightR);
	else
	{
		T leftAggValue = leftTree->query(leftR, midRange);
		T rightAggValue = rightTree->query(midRange + 1, rightR);
		aggValue = aggFunc(leftAggValue, 1, rightAggValue, 1);
	}
	return aggValue;
}

