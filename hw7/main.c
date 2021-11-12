#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define ROTATE(a,i,j,k,l) g=a[i][j];h=a[k][l];a[i][j]=g-s*(h+g*tau);\
   a[k][l]=h+s*(g-h*tau);
 

#define IA 16807

#define IM 2147483647

#define AM (1.0/IM)

#define IQ 127773

#define IR 2836

#define MASK 123459876

#define NR_END 1

#define FREE_ARG char*

#define NTAB 32

#define NDIV (1+(IM-1)/NTAB)

 

#define EPS 1.2e-7 

#define RNMX (1.0-EPS) 

 

void nrerror(char error_text[])

 

/* Numerical Recipes standard error handler */

 

{

 

    void exit();

 

 

 

    fprintf(stderr, "Numerical Recipes run-time error...\n");

 

    fprintf(stderr, "%s\n", error_text);

 

    fprintf(stderr, "...now exiting to system...\n");

 

    exit(1);

 

}

 

 

float** matrix(long nrl, long nrh, long ncl, long nch) {

 

    long i, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;

    float** m;

 

    m = (float**)malloc((unsigned int)((nrow + NR_END) * sizeof(float*)));

    if (!m)nrerror("allocation failure 1 in matrix()");

    m += NR_END;

    m -= nrl;

 

    m[nrl] = (float*)malloc((unsigned int)((nrow * ncol + NR_END) * sizeof(float)));

    if (!m[nrl])nrerror("allocation failure 2 in matrix()");

    m[nrl] += NR_END;

    m[nrl] -= ncl;

 

    for (i = nrl + 1; i <= nrh; i++) m[i] = m[i - 1] + ncol;

 

    return m;

 

}

 

float* vector(long nl, long nh)

 

/* allocate a float vector with subscript range v[nl..nh] */

 

{

 

    float* v;

 

 

 

    v = (float*)malloc((unsigned int)((nh - nl + 1 + NR_END) * sizeof(float)));

 

    if (!v) nrerror("allocation failure in vector()");

 

    return v - nl + NR_END;

 

}

 

void free_vector(float* v, long nl, long nh)

 

/* free a float vector allocated with vector() */

 

{

 

    free((FREE_ARG)(v + nl - NR_END));

 

}

 

void eigsrt(float* d, float** v, int n)

 

{

 

    int k, j, i;

 

    float p;

 

 

 

    for (i = 1; i < n; i++) {

 

        p = d[k = i];

 

        for (j = i + 1; j <= n; j++)

 

            if (d[j] >= p) p = d[k = j];

 

        if (k != i) {

 

            d[k] = d[i];

 

            d[i] = p;

 

            for (j = 1; j <= n; j++) {

 

                p = v[j][i];

 

                v[j][i] = v[j][k];

 

                v[j][k] = p;

 

            }

 

        }

 

    }

 

}

 

 

 

void jacobi(float** a, int n, float* d, float** v, int* nrot)

{

 

    int j, iq, ip, i;

 

    float tresh, theta, tau, t, sm, s, h, g, c, * b, * z;

 

 

 

    b = vector(1, n);

 

    z = vector(1, n);

 

    for (ip = 1; ip <= n; ip++) {

 

        for (iq = 1; iq <= n; iq++) v[ip][iq] = 0.0;

 

        v[ip][ip] = 1.0;

 

    }

 

    for (ip = 1; ip <= n; ip++) {

 

        b[ip] = d[ip] = a[ip][ip];

 

        z[ip] = 0.0;

 

    }

 

    *nrot = 0;

 

    for (i = 1; i <= 50; i++) {

 

        sm = 0.0;

 

        for (ip = 1; ip <= n - 1; ip++) {

 

            for (iq = ip + 1; iq <= n; iq++)

 

                sm += fabs(a[ip][iq]);

 

        }

 

        if (sm == 0.0) {

 

            free_vector(z, 1, n);

 

            free_vector(b, 1, n);

 

            return;

 

        }

 

        if (i < 4)

 

            tresh = 0.2 * sm / (n * n);

 

        else

 

            tresh = 0.0;

 

        for (ip = 1; ip <= n - 1; ip++) {

 

            for (iq = ip + 1; iq <= n; iq++) {

 

                g = 100.0 * fabs(a[ip][iq]);

 

                if (i > 4 && (float)(fabs(d[ip]) + g) == (float)fabs(d[ip])

 

                    && (float)(fabs(d[iq]) + g) == (float)fabs(d[iq]))

 

                    a[ip][iq] = 0.0;

 

                else if (fabs(a[ip][iq]) > tresh) {

 

                    h = d[iq] - d[ip];

 

                    if ((float)(fabs(h) + g) == (float)fabs(h))

 

                        t = (a[ip][iq]) / h;

 

                    else {

 

                        theta = 0.5 * h / (a[ip][iq]);

 

                        t = 1.0 / (fabs(theta) + sqrt(1.0 + theta * theta));

 

                        if (theta < 0.0) t = -t;

 

                    }

 

                    c = 1.0 / sqrt(1 + t * t);

 

                    s = t * c;

 

                    tau = s / (1.0 + c);

 

                    h = t * a[ip][iq];

 

                    z[ip] -= h;

 

                    z[iq] += h;

 

                    d[ip] -= h;

 

                    d[iq] += h;

 

                    a[ip][iq] = 0.0;

 

                    for (j = 1; j <= ip - 1; j++) {

 

                        ROTATE(a, j, ip, j, iq)

 

                    }

 

                    for (j = ip + 1; j <= iq - 1; j++) {

 

                        ROTATE(a, ip, j, j, iq)

 

                    }

 

                    for (j = iq + 1; j <= n; j++) {

 

                        ROTATE(a, ip, j, iq, j)

 

                    }

 

                    for (j = 1; j <= n; j++) {

 

                        ROTATE(v, j, ip, j, iq)

 

                    }

 

                    ++(*nrot);

 

                }

 

            }

 

        }

 

        for (ip = 1; ip <= n; ip++) {

 

            b[ip] += z[ip];

 

            d[ip] = b[ip];

 

            z[ip] = 0.0;

 

        }

 

    }

 

    nrerror("Too many iterations in routine jacobi");

 

}

 

float ran1(long* idum)

{

    int j;

    long k;

    static long iy = 0;

    static long iv[NTAB];

    float temp;

 

    if (*idum <= 0 || !iy) {

        if (-(*idum) < 1) *idum = 1;

        else *idum = -(*idum);

        for (j = NTAB + 7; j >= 0; j--) {

            k = (*idum) / IQ;

            *idum = IA * (*idum - k * IQ) - IR * k;

            if (*idum < 0) *idum += IM;

            if (j < NTAB) iv[j] = *idum;

        }

        iy = iv[0];

    }

    k = (*idum) / IQ;

    *idum = IA * (*idum - k * IQ) - IR * k;

    if (*idum < 0) *idum += IM;

    j = iy / NDIV;

    iy = iv[j];

    iv[j] = *idum;

    if ((temp = AM * iy) > RNMX) return RNMX;

    else return temp;

}

float gasdev(long* idum)

{

    float ran1();

    static int iset = 0;

    static float gset;

    float fac, rsq, v1, v2;

 

    if (*idum < 0) iset = 0;

    if (iset == 0) {

        do {

            v1 = 2.0 * ran1(idum) - 1.0;

            v2 = 2.0 * ran1(idum) - 1.0;

            rsq = v1 * v1 + v2 * v2;

        } while (rsq >= 1.0 || rsq == 0.0);

        fac = sqrt(-2.0 * log(rsq) / rsq);

        gset = v1 * fac;

        iset = 1;

        return v2 * fac;

    }

    else {

        iset = 0;

        return gset;

    }

  } 

 

int main() { 
    const int n = 11; 
    float** a = matrix(1, n, 1, n);
    float** v = matrix(1, n, 1, n);
    float* d = vector(1, n);
    int nrot;
    long idum = time(NULL);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            //            idum = time(NULL);

            a[i][j] = a[j][i] = gasdev(&idum);

        }

    } //create 11*11 symmetric matrix;

//    a[0][0] = v[0][0] = d[0] = 0;

    printf("Matrix,,,\n");

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%f  ", a[i][j]);
        }
        printf("\n");
    } //print the matrix

    jacobi(a, 11, d, v, &nrot);

    //    printf("jacobi success\n");

    eigsrt(d, v, n);

    //    printf("eigsrt success\n");
    printf("\nEigen values,,,\n");
    for (int i = 1; i <= 11; i++) {

        printf("%f  ", d[i]);

    }
    printf("\n");

   printf("\nEigen vectors,,,\n");

    for (int i = 1; i <= 11; i++) {
        for (int j = 1; j <= 11; j++) {

            printf("%f  ", v[i][j]);
        }
    }

    printf("\n");

    return 0;

}

 

#undef ROTATE

#undef IA

#undef IM

#undef AM

#undef IQ

#undef IR

#undef MASK

#undef EPS

#undef NTAB

#undef NDIV

#undef RNMX

