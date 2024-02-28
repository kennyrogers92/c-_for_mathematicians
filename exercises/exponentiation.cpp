#include <iostream>
#include <cmath>
using namespace std;

int main () 
{
	double e = exp(1.) ;
	double pi = M_PI;

	cout << "e to the pi is " << exp(pi) << endl;
	cout << "pi to the e is " << pow(pi,e) << endl;

	return 0;
}
