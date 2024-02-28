#ifndef UNIFORM_H
#define UNIFORM_H

/**
 * @brief Generate a random number between 0 and 1. 
 * @return double a uniform random number in [0, 1].
 */
double unif();

/**
 * @brief Generate a random number in a real interval.
 * @param a one end point of the interval
 * @param b the other end point of the interval
 * @return double a uniform random in [a, b].
 */
double unif(double a, double b);

/**
 * @brief Generate a random integer between 1 and a given value. 
 * @param n the largest value this procedure can product.
 * @return long a uniform random value in {1, 2, ..., n}.
 */
long unif(long a);

/**
 * @brief Reset the RNG based on the system clock.
 * 
 */
void seed();

#endif