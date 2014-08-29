// Author: ufo008ahw
// Last modified: 2013-09-15 22:15

// prime
extern int getPrimes(int n, vector<int>& primes);
extern long long getPrimes(long long n, vector<long long>& primes);
template<class T>
bool isPrime(T p);
template<class T>
T euler_phi(T n);
template<class T>
void all_phi(T n, T phi[]);

// group theory
template<class T>
extern T gcd(T x, T y);
template<class T>
extern void extgcd(T a, T b, T &d, T &x, T &y);
template<class T>
extern T inv(T a, T n);
template<class T>
extern T mod_eq(T a, T b, T n, T sol[]);

// fast
template<class T>
extern T fastMod(T a, T p, T m);
