#include <iostream>
using namespace std;

long factorial(long n) {
	if (n<0) {
		std::cerr << "WARNING: negative number :" << n << std::endl;
		return -1;
	}
	if (n == 0) {return 1;}
	return n*factorial(n-1);
}

int main()
{
	long n;
	cout << " Compute the factorial of this number --> " ; cin >> n;

	cout << "The value of " << n << "! is " << factorial(n) << endl;
	return 0;
}
