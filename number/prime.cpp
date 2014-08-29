/*
 * primes.cpp
 *
 *  Created on: Aug 29, 2014
 *      Author: ufo008ahw
 */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*
 * Get primes 1 ~ n.
 * Input: n.
 * Output: vetor<long long>primes.
 * Return: primes number.
 * Complexity: O(n * primesNum)
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
 * Get primes 1 ~ n.
 * Input: n.
 * Output: vetor<long long>primes.
 * Return: primes number.
 * Complexity: O(n * primesNum)
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


/*
 * Check p is a prime.
 * Note: capable for small int.
 * Return: true or false.
 * Complexity: O(n * primesNum)
 */
template<class T>
bool isPrime(T p)
{
	T i, j, k;
	if (p == 2 || p == 3)
		return true;
	else if (p % 2 == 0 || p % 3 == 0)
		return false;
	// j = i ^ 2, i += 2 or 4, because factor 3
	for (i = 5, j = 25, k = 4; j <= p; i += (k = 6 - k), j += i * 2 - 1)
		if (!(p % i))	return false;
	return true;
}

/*
 * Check p is a prime.
 *
 * Complexity: O(n * primesNum)
 */
// Miller_Rabin
template<>
bool isPrime(string p)
{

}

/*
 * Euler function, find how many number is co-primes with n, that smaller
 * that n.
 * Note: EulerF = ∏(1 / p * (p - 1)), p is a prime.
 * Compleixty: O(n).
 */
template<class T>
T euler_phi(T n)
{
	int phi = n;
	for (T i = 2, j = 4; j <= n; i++, j += i + i - 1)
		if (!(n % i))
		{
			// i is prime, do multiplication
			phi = phi / i * (i - 1);

			// remove factor i
			while (!(n % i))
				n /= i;
		}
	if (n > 1)	phi = phi / n * (n - 1);
	return phi;
}


/*
 * Euler function, find how many number is co-primes with n, that smaller
 * that n.
 * Note: EulerF = ∏(1 / p * (p - 1)), p is a prime.
 * Output: phi[], contains Euler function from 1 to n.
 * Compleixty: O(n).
 */
template<class T>
void all_phi(T n, T phi[])
{
	phi[1] = 1;
	for (T i = 2; i <= n; i++)
		if (!phi[i])
			for (T j = i; j <= n; j += i)
			{
				if (!phi[j])
					phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
}
