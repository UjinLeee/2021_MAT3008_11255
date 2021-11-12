HW5: linear-eqaution 1
=================

# 0. Environment

- OS: Windows
- Compiler : gcc version 8.1.0
- platform: x86_64-posix-seh-rev( )

# 1. 결과

- lineq1.dat

By Gauss-Jordan Elimination,,,
nerror,,, Gaussj: Singular Matrix,,,
1.666667 -1.666667 0.000000 -0.666667

By LU Decomposition,,,

1.000000 -3.000000 2.000000 0.000000

By Singular Value Decomposition,,,

1.293531-2.4129381.119406-0.293531

By Iterative Improvement,,,
-59604641775616.000000-119209308717056.000000178813950492672.00000059604645969920.000000

Determinant of lineq1 is,,,The det of lineq1 is 0.
 SO, the inverse of lineq1 does not exist.

- lineq2.dat

By Gauss-Jordan Elimination,,,
-2.873567 -0.612357 0.976277 0.635819 -0.553441

By LU Decomposition,,,

-2.873566 -0.612357 0.976277 0.635819 -0.553441

By Singular Value Decomposition,,,

-2.873566-0.6123570.9762780.635819-0.553441

By Iterative Improvement,,,
-2.873566-0.6123570.9762770.635819-0.553441

Determinant of lineq2 is,,,3835.999512.

The inverse is,,,
0.354536 0.035454 -0.138686 -0.052138 0.149114 0.766945 0.126695 -0.098540 -0.303962 0.459333 0.207769 0.195777 -0.096715 -0.023201 0.051356 -0.595412 -0.159541 0.124088 0.234619 -0.171011 0.253128 0.050313 0.016423 -0.044578 0.042492


- lineq3.dat

By Gauss-Jordan Elimination,,,
-0.326608 1.532293 -1.044825 -1.587447 2.928480 -2.218931

By LU Decomposition,,,

-0.326608 1.532292 -1.044826 -1.587447 2.928480 -2.218930

By Singular Value Decomposition,,,

-0.3266091.532292-1.044825-1.5874472.928479-2.218929


By Iterative Improvement,,,
-0.3266081.532292-1.044826-1.5874472.928480-2.218930

Determinant of lineq3 is,,,16178.401367.

The inverse is,,,
-0.162205 0.169407 -0.011636 0.105669 -0.053026 -0.062341 0.122801 -0.041117 0.122745 -0.051726 -0.042362 -0.064694 0.024068 0.228313 -0.117407 -0.108916 0.160508 -0.234216 -0.016431 -0.087624 -0.180981 0.299774 -0.224034 0.351126 -0.022840 0.180306 0.015910 0.000859 0.161811 -0.364828 0.046132 -0.395655 0.186766 -0.190541 0.015024 0.434633

lineq2와 lineq3은 어떤 방법을 이용하여 풀든 같은 해가 나왔지만, lineq1은 다른 결과가 나온다.
이는 Gauss-Jordan Elimination을 이용하여 본 결과, lineq1이 무수히 많은 해를 가지고 있는 경우이기 때문이다.

또한, 각 data의 determinant를 구하였을때, lineq1의 determinant는 0이 나오므로, inverse matrix가 나오지 않는다는 것을 알 수 있다.

# 2. 분석

## 1) Gauss-Jordan Elimination (gaussj())
 
Gauss-Jordan Elimination은 recipes 중 gaussj()함수 등을 이용하여 구현하였다.
lineq1.dat에 경우, Gauss-jordan Elimination을 한 결과 무수히 많은 해가 나오게 되고, 기존 함수로는 nerror가 호출되어 프로그램이 종료된다. 이를 방지하기 위하여, nerror 호출 시 프로그램이 종료되지 않고, 에러문을 호출 후 return하는 코드로 바꿔주었다.
하지만, inverse matrix를 구하는데에는 유용하다.
 
## 2) LU Decomposition (ludcmp())

 LU Decomposition은 Upper trianglular matrix와 Lower triangular matrix를 이용하여, Ax=b를 푸는 방법이다. 
recipes 중 ludcmp() 와 lubksb() 함수를 이용하여 구현하였다.
LU decomposition은 gaussj( ) 보다 더 적은 operation을 사용하는 장점이 있지만, inverse matrix를 구하지 못한다는 단점이 있다.

## 3) Singular Value Decomposition (svdcmp())

 SVD 함수는 recipes 중 svdcmp()함수와 svbksb() 함수를 이용하여 구현하였다. 
SVD는 Gauss elimination과 LU decompostion이 풀지 못하는 많은 case를 풀 수 있는 강력한 함수이다.
그러나, 많은 용량을 차지하는 단점이 있다.

## 4) Iterative improvement(mprove())

 Iterative improvement는 recipes 중 lubksb() 함수를 이용하여 구현하였으며, 상대적으로 적은 operation을 실행한다.
하지만, 위의 다른 방법과 비교하였을 때, 무수히 많은 해를 가지는 lineq1.dat를 제외한 나머지와 동일한 결과를 도출해야 하지만, lineq2.dat는 다른 결과가 나왔다.
이로 미루어보아, Iterative improvement는 오차가 발생할 수 있다는 결과가 나온다.

