#include "Projective.h"

/**
 * Illustration of Pappus' Theorem and its dual
 * and the use of near-equality testing
 * 
 * Theorem (Pappus). Let P1, P2, P3 be three distinct collinear points and
 * let Q1, Q2, Q3 be three other distinct collinear points. Let Xi be the
 * intersection of the lines PjQk and PkQj where i,j,k are distinct and
 * 1 <= i,j,k <= 3. Then the three points X1,X2,X3 are collinear.
 * 
 * Theorem (Dual to Pappus). Let L1, L2, L3, be three distinct concurrent
 * lines and let M1,M2,M3 be three other distinct concurrent lines. Let
 * Xi be the line through the points of intersection Lj^Mk and Lk^Mj
 * (^ here denotes intersection) where i,j,k are distinct and satisfy
 * 1 <= i,j,k <= 3. Then the three lines X1,X2,X3 are concurrent. 
 */

void pappus() {
    seed();

    // two random lines
    PLine L1, L2;
    L1.randomize();
    L2.randomize();
    std::cout << "The two lines are " << std::endl
        << L1 << " and " << L2 << std::endl;

    // get three points on L1
    PPoint P1 = L1.rand_point();
    PPoint P2 = L1.rand_point();
    PPoint P3 = L1.rand_point();

    std::cout << "Three points on the first line are " << std::endl
        << P1 << std::endl << P2 << std::endl << P3 << std::endl;

    // get three points on L2
    PPoint Q1 = L2.rand_point();
    PPoint Q2 = L2.rand_point();
    PPoint Q3 = L2.rand_point();

    std::cout << "Three points on the second line are " << std::endl
        << Q1 << std::endl << Q2 << std::endl << Q3 << std::endl;

    // find the three pairwise intersections
    PPoint X1 = (P2+Q3)*(P3+Q2);
    PPoint X2 = (P1+Q3)*(P3+Q1);
    PPoint X3 = (P1+Q2)*(P2+Q1);

    std::cout << "The three points constructed are " << std::endl;
        std::cout << X1 << std::endl << X2 << std::endl << X3 << std::endl;

    if (X1.is_invalid() || X2.is_invalid() || X3.is_invalid()) {
        std::cout << "TROUBLE! One of the points is invalid!" << std::endl;
    }
    else if (collinear(X1, X2, X3)) {
        std::cout << "They are collinear as guaranteed by Pappus' Theorem" << std::endl;
    }
    else {
        std::cout << "TROUBLE! The three points are not collinear!" << std::endl;
    }
}

void dual_pappus() {
    seed();

    // Two random points
    PPoint A, B;
    A.randomize();
    B.randomize();
    std::cout << "The two points are " << A << " and " << B << std::endl;

    // Three lines through A
    PLine L1 = A.rand_line();
    PLine L2 = A.rand_line();
    PLine L3 = A.rand_line();

    std::cout << "The three lines through the first point are " << std::endl
        << L1 << std::endl << L2 << std::endl << L3 << std::endl;
    
    // Three lines through B
    PLine M1 = B.rand_line();
    PLine M2 = B.rand_line();
    PLine M3 = B.rand_line();

    std::cout << "The three lines through the second point are " << std::endl
        << M1 << std::endl << M2 << std::endl << M3 << std::endl;

    // get the three dual Pappus lines
    PLine X1 = L2*M3 + L3*M2;
    PLine X2 = L1*M3 + L3*M1;
    PLine X3 = L1*M2 + L2*M1;

    std::cout << "The three lines constructed are " << std::endl;
    std::cout << X1 << std::endl << X2 << std::endl << X3 << std::endl;

    if (X1.is_invalid() || X2.is_invalid() || X3.is_invalid()) {
        std::cout << "TROUBLE! One of the lines is invalid!" << std::endl;
    }
    else if (concurrent(X1, X2, X3)) {
        std::cout << "They are concurrent, as guaranteed by Dual to Pappus' Theorem" << std::endl;
    }
    else {
        std::cout << "TROUBLE! The three lines are not concurrent!" << std::endl;
    }
}

int main() {
    double t;
    std::cout << "Enter desired tolerance --> ";
    std::cin >> t;
    PObject::set_tolerance(t);
    
    std::cout << "You set the tolerance to " << PObject::get_tolerance() << std::endl << std::endl;

    pappus();
    std::cout << std::endl;
    dual_pappus();

    return 0;
}