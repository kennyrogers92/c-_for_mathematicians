#include <iostream>

int fibonacci(int n) {
    /// Recursive implementation of fibonacci
    if (n < 0) {
        std::cerr << "WARNING: n is negative" << std::endl;
        return -1;
    }
    // Base cases
    if (n == 0 || n == 1) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);;
}

int fibonacci2(int n) {
    /// Iterative implementaion of fibonacci
    if (n < 0) {
        std::cerr << "WARNING: n is negative" << std::endl;
        return -1;
    }
    int val = 1;
    int r=1, s=0;
    for (int i = 1; i < n; i++) {
        s = r;
        r = val;
        val = r+s;
    }
    return val;
}

int main() {
    long n;
    std::cout << "nth Fibonacci number\nEnter a number-->: ";
    std::cin >> n;
    std::cout << "The nth Fibonacci number is " << fibonacci(n) << std::endl;
    return 0;
}
