#include "hw3.h"
# define MAX 1e8;


int main() {

	const float x1 = 1.0;
	const float x2 = 10.0;
	const float xacc = 1e-6;
	const int max_roots = 100;
	const int num_brackets = MAX;
	int num_roots = max_roots;
	float xb1[100], xb2[100];

	zbrak(bessj0, x1, x2, num_brackets, xb1, xb2, &num_roots);

	//Bisection
	printf("---Bisection---\n");
	run_1(rtbis, bessj0, xb1, xb2, num_roots, xacc);

	//Linear Interpolation
	printf("---Linear Interpolation---\n");
	run_1(rtflsp, bessj0, xb1, xb2, num_roots, xacc);

	//Secant
	printf("---Secant---\n");
	run_1(rtsec, bessj0, xb1, xb2, num_roots, xacc);

	//Newton-Raphson
	printf("---Newton-Raphson---\n");
	run_2(rtnewt, bessj0d, xb1, xb2, num_roots, xacc);

	//Newton with Bracketing
	printf("---Newton with Bracketing---\n");
	run_2(rtsafe, bessj0d, xb1, xb2, num_roots, xacc);

	//Muller
	printf("---Muller---\n");
	run_1(muller, bessj0, xb1, xb2, num_roots, xacc);

	printf("\n\n---Equations---\n\n");

	// Equation1

	printf("Equation 1 ,,, \n");
	const float e1_1 = 0.1;
	const float e1_2 = 1.0;
	float e1_xb1[100], e1_xb2[100];

	num_roots = 10;
	zbrak(p1, e1_1, e1_2, num_brackets, e1_xb1, e1_xb2, &num_roots);
	run_2(rtsafe, p1d, e1_xb1, e1_xb2, num_roots, xacc);

	// Equation2

	printf("Equation 2 ,,, \n");

	const float e2_1 = 0.0;
	const float e2_2 = 1.0;
	float e2_xb1[100], e2_xb2[100];

	num_roots = 10;
	zbrak(p2, e2_1, e2_2, num_brackets, e2_xb1, e2_xb2, &num_roots);
	run_2(rtsafe, p2d, e2_xb1, e2_xb2, num_roots, xacc);

	// Equation3

	printf("Equation 3 ,,, \n");

	const float e3_1 = -2.0;
	const float e3_2 = -1.0;
	float e3_xb1[100], e3_xb2[100];

	num_roots = 10;
	zbrak(p3, e3_1, e3_2, num_brackets, e3_xb1, e3_xb2, &num_roots);
	run_2(rtsafe, p3d, e3_xb1, e3_xb2, num_roots, xacc);

	// Equation4

	printf("Equation 4 ,,, \n");

	const float e4_1 = 0.0;
	const float e4_2 = 1.0;
	float e4_xb1[100], e4_xb2[100];

	num_roots = 10;
	zbrak(p4, e4_1, e4_2, num_brackets, e4_xb1, e4_xb2, &num_roots);
	run_2(rtsafe, p4d, e4_xb1, e4_xb2, num_roots, xacc);


	return 0;
}