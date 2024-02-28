#include "Polynomial.h"
#include "../Mod/Mod.h"

const long max_bits = 31;

Polynomial<Mod> long2poly(long m) {
    Polynomial<Mod> ans;

    long j = 0;
    while (m != 0) {
        ans.set(j, Mod(m, 2));
        m /= 2;
        j++;
    }
    return ans;
}

/**
 * Program to investigate gcd problem in case of polynomials
 * with coefficients from Z2
 */
int main() {
    long d;
    std::cout << "Enter degree bound --> ";
    std::cin >> d;

    if ( (d<1) || (d>max_bits) ) {
        std::cerr << "Please choose d between 1 and " << max_bits << std::endl;
    return 0;
    }

    long bound = 1<<d;

    Polynomial<Mod>* list;

    list = new Polynomial<Mod>[bound];

    std::cerr << "Generating polynomials ... ";
    for (long k = 0; k < bound; k++) {
        list[k] = long2poly(k);
    }
    std::cerr << "done! " << std::endl << bound 
        << " polynomials of degree less than "  
        << d << " generated" << std::endl;

    long count = 0;
    const Polynomial<Mod> one(Mod(1, 2));

    for (long i = 0; i < bound-1; i++) {
        for (long j = i+1; j < bound; j++) {
            if ( gcd(list[i], list[j]) == one) count++;
        }
    }
    
    count = 2*count + 1;

    std::cout << count << " out of " << bound*bound
        << " pairs are relatively prime" << std::endl;

    std::cout << count / double(bound*bound) << std::endl;

    return 0;
}