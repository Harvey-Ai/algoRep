// Author: ufo008ahw
// Last modified: 2013-09-15 22:15


#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*
 * get primes 1 ~ n.
 * input: n.
 * output: vetor<long long>primes.
 * return: primes number.
 * complexity: O(n * primesNum)
 */
int getPrimes(int n, vector<int>& primes)
{
	primes.resize(0);

	int flag[n + 1];
	memset(flag, 0, sizeof(flag));

	for (int i = 2, int k = 4; i <= n; i++, k += i * 2 - 1)
		if (!flag[i])
		{
			primes.push_back(i);
			for (int j = k; j <= n; j += i)
				flag[j] = true;
		}

	return primes.size();
}

/*
 * get primes 1 ~ n.
 * input: n.
 * output: vetor<long long>primes.
 * return: primes number.
 * complexity: O(n * primesNum)
 */
long long getPrimes(long long n, vector<long long>& primes)
{
	primes.resize(0);
	primes.push_back(2);

	for(long long i = 3;i <= n;i += 2)
	{
		bool isPrime = true;
		for(long long j = 0;j < primes.size() && primes[j] * primes[j] <= i;j++)
			if (i % primes[j] == 0)
			{
				isPrime = false;
				break;
			}
		if (isPrimes)
		{
			primeNum++;
			primes.push_back(i);
		}
	}
	return primeNum;
}


/**********************************************************
 * Description: check if a number is a prime              *
 * Primeters: p                                           *
 * Return: false: p is not a prime, true: p is a prime.   *
 * Note:                                                  *
 * ********************************************************/
template<class T>
bool isPrime(T p)
{
	T i, j, k;
	if (p == 2 || p == 3)
		return true;
	else if (p % 2 == 0 || p % 3 == 0)
		return false;
	for (i = 5, j = 25, k = 4; j <= p; i += (k = 6 - k), j += i * 2 - 1)
		if (!(p % i))	return false;
	return true;
}

// Miller_Rabin
template<>
bool isPrime(string p)
{

}


/**********************************************************
 * Description: Get greatest common divisor               *
 * Primeters: 1. x(int) 2.y(int)                          *
 * Return: return greatest common divisor                 *
 * Note: function works even x, y are negative            *
 * ********************************************************/
/*
 * Greatest Common Divisor
 * complexity: O(log n)
 */

int gcd(int x, int y)
{
	if (!x || !y) return x > y ? x : y; // if exist 0, return bigger number
	for (int t; t = x % y; x = y, y = t);
	return y;
}

/**********************************************************
 * Description: Extended GCD, get solution (x, y) satisfy *
 *              equation d = a * x + b * y where d, a, b  *
 *              are constant.                             * 
 * Primeters: 1. a(int) 2.b(int) 3.d(int) 4.x(quote int)  *
 *            5.y(quote int)                              *
 * Return: void                                           *
 * Note: Fisrtly d must be GCD(a, b), and genearl         *
 *		solution is (x + kb,y - ka), k is arbitrary       *
 *		integer.                                          *
 * ********************************************************/
void extgcd(int a, int b, int &d, int &x, int &y)
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

/**********************************************************
 * Description: Get Inverse of a in mod n, satisfying     *
 *              ax = 1(mod n)                             *
 * Primeters: 1. a(int) 2.n(int)                          *
 * Return: Inverse of a, in range (0 ~ n - 1)             *
 * Note: a and n must relatively-prime.                   * 
 * ********************************************************/
#define MOD(x, y)  (((x) % (n) + (n)) % n);
int inv(int a, int n)
{
	int d, x, y;
	extgcd(a, n, d, x, y);
	return d == 1 ? MOD(x, n) : -1;
}

/**********************************************************
 * Description: Euler's totient function(single version), *
 *              that is to find how many number smaller   *
 *              than n which and n are coprime.           *
 * Primeters: 1. n(int)                                   *
 * Return: 1. phi(int), number count that are smaller     *
 *         than  n and coprime with n.                    *
 * Note:                                                  *
 * ********************************************************/
int euler_phi(int n)
{
	int i, j, phi = n;
	for (i = 2, j = 4; j <= n; i++, j += i + i - 1)
		if (!(n % i))
		{
			phi = phi / i * (i - 1);
			while (!(n % i))	n /= i;
		}
	if (n > 1)	phi = phi / n * (n - 1);
	return phi;
}


/************************************************************
 * Description: Euler's totient function(multiple version), *
 *              that is to find how many number smaller     *
 *              than n which and n are coprime.             *
 * Primeters: 1. n(int), 2. phi(int array) to be filled     *
 *            with coprime number count.                    *
 * Return: 1. phi(int), number count that are smaller than  *
 *			 n and coprime with n.                          *
 * Note:                                                    *
 * **********************************************************/
void all_phi(int n, int phi[])
{
	int i, j;
	phi[1] = 1;
	for (i = 2; i <= n; i++)
		if (!phi[i])
			for (j = i; j <= n; j += i)
			{
				if (!phi[j])	phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
}

/************************************************************
 * Description: Big number mod, Get result of b^p mod n.    *
 * Primeters: 1. a(int) 2.b(int) 3.n(int)                   *
 * Return: mod result                                       *
 * Note:                                                    *
 * **********************************************************/
int modN(int a, int p, int m)
{
	if (p == 0)
	{
		if (m != 1)
			return 1;
		else
			return 0;
	}
	int r = a % m;
	int k = 1;
	while (p > 1)
	{
		if ((p & 1) != 0)
			k = (k * r) % m;
		r = (r * r) % m;
		p /= 2;
	}
	return (r * k) % m;
}

/************************************************************
 * Description: General mod function sulution, get x        * 
 *				satisfying a * x == b(mod n), in this       *
 *				equation, b must divide exactly GCD(a, n).  *
 * Primeters: 1.a(int) 2.b(int) 3.n(int) 4.sol(int array)   *
 *				to be filled with solutions.                *
 * Return: 0 for no solution.                               *
 * Note: b must divide exactly GCD(a, n).                   *
 * **********************************************************/
int mod_eq(int a, int b, int n, int sol[])
{
	int d, x, y;
	extgcd(a, n, d, x, y);
	if (b % d)
		return 0;                      //no solution
	else
	{
		sol[0] = x * (b / d) % n;      //第一个解
		for (int i = 1; i < d; i++)
			sol[i] = (sol[i-1] + n / d) % n;    //还原剩余系解
	}
	return 1;
}
