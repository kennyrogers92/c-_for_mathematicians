#include "Mod.h"

int main() {
    Mod x, y, z;

    x.set_default_modulus(11);

    x = Mod(17, 10);
    y = Mod(24);
    z = -3;

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl << std::endl;

    std::cout << "y+z = " << y+z << std::endl;
    std::cout << "y-z = " << y-z << std::endl;
    std::cout << "y*z = " << y*z << std::endl;
    std::cout << "y/z = " << y/z << std::endl << std::endl;

    std::cout << "x+3 = " << x+3 << std::endl;
    std::cout << "x-3 = " << x-3 << std::endl;
    std::cout << "x*3 = " << x*3 << std::endl;
    std::cout << "x/3 = " << x/3 << std::endl << std::endl;

    std::cout << "4+x = " << 4+x << std::endl;
    std::cout << "4-x = " << 4-x << std::endl;
    std::cout << "4*x = " << 4*x << std::endl;
    std::cout << "4/x = " << 4/x << std::endl << std::endl;

    std::cout << "-x = " << -x << std::endl << std::endl;

    std::cout << "x^9 = " << x.pow(9) << std::endl;
    std::cout << "x^(-9) = " << x.pow(-9) << std::endl << std::endl;

    std::cout << "-1+y^10 = " << -1+y.pow(10) << std::endl;
    std::cout << "y^2 = " << y.pow(2) << std::endl;
    std::cout << "y^(-2)+1 = " << y.pow(-2)+1 << std::endl << std::endl;

    std::cout << "x == 17\t" << (x == 17) << std::endl;
    std::cout << "x != 17\t" << (x != 17) << std::endl << std::endl;

    std::cout << "17 == x\t" << (17 == x) << std::endl;
    std::cout << "17 != x\t" << (17 != x) << std::endl << std::endl;

    std::cout << "crt(x, y) = " << crt(x, y) << std::endl;
    return 0;
}