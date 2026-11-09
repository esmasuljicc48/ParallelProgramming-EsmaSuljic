#ifndef SUM_ALGORITHMS_H
#define SUM_ALGORITHMS_H

/*
 * Standard double precision sum
 */
double do_sum(double* restrict var, long ncells);

// long double sum
long double do_ldsum(double* restrict var, long ncells);

// pair sum
double do_pair_sum(double* restrict var, long ncells);

//kahan sum
double do_kahan_sum(double* restrict var, long ncells);

// knuth
double do_knuth_sum(double* restrict var, long ncells);

#endif //SUM_ALGORITHMS_H
