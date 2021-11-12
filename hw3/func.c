#include "hw3.h"

float p1(float x) {
    return 10 * exp(-x) * sin(2 * M_PI * x) - 2;
}

float p2(float x) {
    return x * x - 2 * x * exp(-x) + exp(-2 * x);
}

float p3(float x) {
    return cos(x + sqrt(2)) + x * (x / 2 + sqrt(2));
}

float p4(float x) {
    return 2* x * x - 8 * x + 5;
}

void p1d(float x, float* y, float* dy) {
    *y = p1(x);
    *dy = 10 * exp(-x) * (2 * M_PI * cos(2 * M_PI * x) - sin(2 * M_PI * x));
}

void p2d(float x, float* y, float* dy) {
    *y = p2(x);
    *dy = 2 * x * exp(-x) - 2 * exp(-x) - 2 * exp(-2 * x) + 2 * x;
}

void p3d(float x, float* y, float* dy) {
    *y = p3(x);
    *dy = x - sin(x + sqrt(2)) + sqrt(2);
}

void p4d(float x, float* y, float* dy) {
    *y = p4(x);
    *dy = 4 * x - 8;
}
