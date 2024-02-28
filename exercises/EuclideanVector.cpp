#include "EuclideanVector.h"

/**
 * To test the EuclideanVector class
 */
int main() {
    EuclideanVector U;
    EuclideanVector V(3);
    
    std::cout << "The vectors U and V are " << U << " and ";
        std::cout << V  << " respectively with dimensions ";
        std::cout << U.get_dim() << " and " << V.get_dim();
        std::cout << " respectively." << std::endl;

    for (int k = 0; k < V.get_dim(); k++) V.set(k, k+1);
    std::cout << "Now V is " << V << std::endl;
    
    EuclideanVector W = V;
    for (int k = 0; k < W.get_dim(); k++) W.set(k, V.get(W.get_dim() - 1 - k));
    std::cout << "Define W as " << W << std::endl;
    std::cout << "Is V = W? ";
    if (V == W) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }
    return 0;
}