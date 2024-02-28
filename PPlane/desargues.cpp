#include "Projective.h"

/**
 * Illustration of Desargues' Theorem
 * 
 * Theorem (Desargues). Suppose that triangles ABC and DEF
 * are in perspective from a point O.(That is, the triples
 * OAD, OBE, and OCF are each collinear.) Then the three
 * poits of intersection of the lines AC and DF, 
 * lines AB and DE, and lines BC and EF are collinear.
 */

void desargues() {
    seed();
    // Point of perspectivity
    PPoint O;

    // Three distinct lines thru O
    PLine L1 = O.rand_line();
    PLine L2;
    do {
        L2 = O.rand_line();
    } while (L1 == L2);
    PLine L3;
    do {
        L3 = O.rand_line();
    } while (L1 == L2 || L1 == L2);

    // Generate vertices of triangles ABC and DEF;
    PPoint A = L1.rand_point();
    PPoint D;
    do {
        D = L1.rand_point();
    } while (A == D);
    PPoint B = L1.rand_point();
    PPoint E;
    do {
        E = L2.rand_point();
    } while (B == E);
    PPoint C = L3.rand_point();
    PPoint F;
    do {
        F = L3.rand_point();
    } while (C == F);

    std::cout << "The vertices of ABC are "; 
        std::cout << A << ", " << B << ", and " <<  C << std::endl;
    std::cout << "The vertices of DEF are "; 
        std::cout << D << ", " << E << ", and " <<  F << std::endl;

    // Generate the intersection of lines
    // AC and DF, AB and DE, and BC and EF
    PPoint X = (A+C)*(D+F);
    PPoint Y = (A+B)*(D+E);
    PPoint Z = (B+C)*(E+F);

    std::cout << "The constructed points are" << std::endl 
        << X << ", " << Y << ", and " << Z << std::endl;
    
    // Check if the X, Y, Z are collinear
    if ( (X+Y).has(Z) ) {
        std::cout << "Yes, the three constructed points are collinear";
        std::cout << " as guaranteed by Desargues' Theorem" << std::endl;
    }
    else {
        std::cout << "NO! the three constructed points are not collinear"
            << std::endl;
    }
}

int main() {
    PObject::set_tolerance(0);
    desargues();
    return 0;
}