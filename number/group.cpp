/*
 * divisor.cpp
 *
 *  Created on: Aug 29, 2014
 *      Author: ufo008ahw
 */

/*
 * Greatest Common Divisor, it works even x, y are negative
 * complexity: O(log n)s
 */
template<class T>
T gcd(T x, T y)
{
	if (!x || !y) return x > y ? x : y; // if exist 0, return bigger number
	for (T t; t = x % y; x = y, y = t);
	return y;
}

/*
 * Extended GCD, get solution (x, y) of d = a * x + b * y.
 * Note: d must be common divisor of a and b, and the general solution
 * is (x + kb,y - ka), k is intergar variable.
 * Complexity: O(log n)
 */
template<class T>
void extgcd(T a, T b, T &d, T &x, T &y)
{
	if (!b)
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		extgcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}

/*
 * Inverse a in group n.
 * Note: a and n must be co-prime, -1 means no inverse.
 * Complexity: O(log n).
 */
template<class T>
T inv(T a, T n)
{
	T d, x, y;
	extgcd(a, n, d, x, y);

	if (d == 1)
		return (x % n + n) % n;
	else
		return -1;
}

/*
 * General mod solution, find x in a * x == b(mod n).
 * Note: b must be divisor of a and n.
 * Output: sol[], contain all solution.
 * Complexity: O(n).
 */
template<class T>
T mod_eq(T a, T b, T n, T sol[])
{
	T d, x, y;
	extgcd(a, n, d, x, y);
	if (b % d)
		return 0;                      //no solution
	else
	{
		sol[0] = x * (b / d) % n;      //第一个解
		for (T i = 1; i < d; i++)
			sol[i] = (sol[i-1] + n / d) % n;    //还原剩余系解
	}
	return 1;
}
