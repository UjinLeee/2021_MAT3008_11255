#include "hw3.h"

float muller(float (*func)(float), float p0, float p2, float xacc) {

	const int max_it = 40;
	float p1 = (p0 + p2) / 2;
	float max = p2;

	float f0, f1, f2, a, b, c;

	for (int i = 0; i < max_it; i++) {
	
		f0 = (*func)(p0);
		f1 = (*func)(p1);
		f2 = (*func)(p2);
		c = f2;

		float a1 = (p1 - p2) * (f0 - f2) - (p0 - p2) * (f1 - f2);
		float a2 = (p0 - p2) * (p1 - p2) * (p0 - p1);

		a = a1 / a2;


		float b1 = (p0 - p2) * (p0 - p2) * (f1 - f2) - (p1 - p2) * (p1 - p2) * (f0 - f2);
		float b2 = (p0 - p2) * (p1 - p2) * (p0 - p1);

		b = b1 / b2;

		int sgn;

		if (b >= 0) sgn = 1;
		else sgn = -1;

		float p3 = p2 - (2 * c) / (b + sgn * sqrt(b * b - 4 * a * c));

		p0 = p1;
		p1 = p2;

		if (p3 > max) break;

		p2 = p3;

		if (fabs(p2 - p1) < xacc)break;
	

	}

	return p2;

}