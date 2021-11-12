# Homework #7

## 0. Goal

This project is to generate a 11x11 symmetric matrix A by using random number generator(Gaussian distribution with mean = 0 and standard deviation = 1.0).
Then compute all eigenvalues and eigenvectors of A using jacobi() and eigsrt() in numerical recipes.

## 1. Environment

- language: C
- OS: Linux
- Compile: gcc version 9.3.0

## 2. Implementation

1) Declaration 

For matrix, I declared 'float** a','float** b' and I used 'float** matrix' function in nrtuil.c
'float** a' is used for symmetric matrix A, and 'float** b' is used for containing eigen vectors.
Also, for random numer genration, gaussian distribution should be used, so gasdev() and time function are used to generate random number in matrix.

For the buffer of eigen values, I declared 'float* d' and used the function 'float* vector' in nrtuil.c.

Also, I declared 'const int n = 11' for the size of matrix, 'int nrot' for jacobi( ), and 'long idum' for random number generation.

2) Compute eigenvalues

To compute eigenvalues, I used 'void eigsrt(float* d, float** v, int n)' function, and put the results into d[].

3) Compute eigenvectors

To compute eigenvectors, I used 'void jacobi(float** a, int n, float* d, float** v, int* nrot)' function, and put the rsults into v[][].


## 3. Result

The result is in the image. 