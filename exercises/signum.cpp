#include <iostream>
using namespace std;

int sgn(double x) {
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}


int main() {
	long n;
	cout << " What is the signum of --> " ; cin >> n;
	cout << " The signum of " << n << " is " << sgn(n) << endl;
	return 0;
}
