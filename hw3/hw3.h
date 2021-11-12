#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include<time.h>
#include <stddef.h>
#include <stdlib.h>

float rtbis(float (*func)(float), float x1, float x2, float xacc);
float rtflsp(float (*func)(float), float x1, float x2, float xacc);
float rtsec(float (*func)(float), float x1, float x2, float xacc);
float rtnewt(void (*funcd)(float, float*, float*), float x1, float x2,
	float xacc);
float rtsafe(void (*funcd)(float, float*, float*), float x1, float x2,
	float xacc);

float p1(float x);
float p2(float x);
float p3(float x);
float p4(float x);

void p1d(float x, float* y, float* dy);
void p2d(float x, float* y, float* dy);
void p3d(float x, float* y, float* dy);
void p4d(float x, float* y, float* dy);


void nrerror(char error_text[]);
void zbrak(float (*fx)(float), float x1, float x2, int n, float xb1[], float xb2[], int* nb);
float bessj0(float x);
float bessj1(float x);
void bessj0d(float x, float* y, float* dy);


void run_1(float(*method)(float(*func)(float), float, float, float),
	float(*func)(float),
	float* xb1,
	float* xb2,
	int num_roots,
	float xacc);
void run_2(float(*method)(void(*func)(float, float*, float*), float, float, float),
	void(*func)(float, float*, float*),
	float* xb1,
	float* xb2,
	int num_roots,
	float xacc);

float muller(float (*func)(float), float p0, float p2, float xacc);