// Author: ufo008ahw
// Last modified: 2013-09-15 22:15

#include <vector>
using namespace std;

//////////////////////////
// prime

/*
 * Get primes 1 ~ n.
 * Input: n.
 * Output: vetor<long long>primes.
 * Return: primes number.
 * Complexity: O(n * primesNum)
 */
template<class T>
T getPrimes(T n, vector<T>& primes);

/*
 * Check p is a prime.
 * Note: capable for small int.
 * Return: true or false.
 * Complexity: O(n * primesNum)
 */
template<class T>
bool isPrime(T p);

/*
 * Euler function, find how many number is co-primes with n, that smaller
 * that n.
 * Note: EulerF = ∏(1 / p * (p - 1)), p is a prime.
 * Compleixty: O(n).
 */
template<class T>
T euler_phi(T n);

/*
 * Euler function, find how many number is co-primes with n, that smaller
 * that n.
 * Note: EulerF = ∏(1 / p * (p - 1)), p is a prime.
 * Output: phi[], contains Euler function from 1 to n.
 * Compleixty: O(n).
 */
template<class T>
void all_phi(T n, T phi[]);

//////////////////////////////
// group theory

/*
 * Greatest Common Divisor, it works even x, y are negative
 * complexity: O(log n)s
 */
template<class T>
T gcd(T x, T y);

/*
 * Extended GCD, get solution (x, y) of d = a * x + b * y.
 * Note: d must be common divisor of a and b, and the general solution
 * is (x + kb,y - ka), k is intergar variable.
 * Complexity: O(log n)
 */
template<class T>
void extgcd(T a, T b, T &d, T &x, T &y);

/*
 * Inverse a in group n.
 * Note: a and n must be co-prime, -1 means no inverse.
 * Complexity: O(log n).
 */
template<class T>
T inv(T a, T n);

/*
 * General mod solution, find x in a * x == b(mod n).
 * Note: b must be divisor of a and n.
 * Output: sol[], contain all solution.
 * Complexity: O(n).
 */
template<class T>
T mod_eq(T a, T b, T n, T sol[]);


/////////////////////////////
// fast

/*
 * FastMod, get a^b mod n.
 * Complexity O(log n).
 */
template<class T>
T fastMod(T a, T p, T m);
