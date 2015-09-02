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


/////////////////////////////
// combination

/*
 *  The first Stirling number.
 *  Divide N objects to M circles without empty circle, and the circles
 *  have no indexes. And the objects in circle have indexes.
 *  S1[n, m] = (n - 1) * S1[n - 1, m] + S1[n - 1, m - 1].
 */
int Stirling1(int n, int m);

/*
 *  The second Stirling number.
 *  The only different with the first stirling is that circles are replaced by boxes.
 *  It means objects in boxes have no indexes.
 */
int Stirling2(int n, int m);

/*
 * The catalan number.
 * Catalan number is a special sequence of number.
 * H[n] = H[0] * H[n - 1] + H[1] * H[n - 2] + ... + H[n - 1] * H[0]
 * Usage: 括号化, 出栈种类数，凸多边形三角剖分，二叉树种类
 *
 */

int Catalan(int n);

/*
 * Put N objects into M boxes, including empty boxes.
 * M1: F(n, m) = F(n - m, m) + F(n, m - 1);
 * M2: C(m + n,n - 1), 搁板法
 *
 */
int divide(int n, m);
