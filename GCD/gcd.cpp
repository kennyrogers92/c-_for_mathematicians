#include "gcd.h"
#include <iostream>
/**
 * @brief Computation of gcd. Note that gcd(a, b) = gcd(b, c)
 * where c = a(mod b). Computes the gcd recursively or iteratively.
 * By default, we compute iteratively. For this generic function,
 * we handle all corner cases before gcd is computed for a, b > 0.
 * If a=b=0, a warning will be printed and 0 will be returned.
 * @param a the first integer
 * @param b the second integer
 * @param version Recursive or Iterative
 * @return long the gcd of a and b
 */
long gcd(long& a, long& b, GCDVersion version=Iterative) {
	// Make sure a and b are nonnegative
	if (a<0) a = -a;
	if (b<0) b = -b;
	
	// If a=b=0, print an error
	if ( (a==0) && (b==0) ) {
		std::cerr << "WARNING: gcd called with both arguments equal to zero." << std::endl;
		return 0;
	}
	
	switch (version) {
	case Recursive:
		return gcdRecursive(a, b);
	default:
		return gcdIterative(a, b);
	}
}

long gcdIterative(long a, long b) {
	while (b!=0) {
		long temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

long gcdRecursive(long a, long b) {
	// If b = 0, gcd(a, b) = a
	if (b==0) return a;
	if (a==0) return b;
	long c = a % b;
	return gcdRecursive(b, c);
}