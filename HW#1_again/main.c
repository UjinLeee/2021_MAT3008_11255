#include <stdio.h>
#include "machar.h"

float get_float_eps()
{

    float n = 1;

    while (1 + n != 1)
    {
        n = n / 2;
    } // 1+n=1¿œ∂ß break

    return n * 2;
}

double get_double_eps()
{

    double n = 1;

    while (1 + n != 1)
    {
        n = n / 2;
    }

    return n * 2;
}

int main()
{

    // By machar() (Method 1)

    //machar() _ float
    int ibeta, it, irnd, ngrd, machep, negep, iexp, minexp, maxexp;
    float float_eps_1, float_epsneg, float_xmin, float_xmax;

    machar(&ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp, &minexp, &maxexp,
        &float_eps_1, &float_epsneg, &float_xmin, &float_xmax); 

    //machar_double() - double

    double double_eps_1, double_epsneg, double_xmin, double_xmax;
    machar_double(&ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp, &minexp, &maxexp,
        &double_eps_1, &double_epsneg, &double_xmin, &double_xmax);


    printf("The result of Method 1,,,  \n");
    printf("The Epsilon of float by machar() : %g (%.23f)\n", float_eps_1, float_eps_1);
    printf("The Epsilon of double by machar_double(): %g (%.52f)\n", double_eps_1, double_eps_1);
    

    // By get_eps() Method 2

    float float_eps_2 = get_float_eps();
    double double_eps_2 = get_double_eps();
    
    printf("The result of Method 2,,,\n");
    printf("The Epsilon of float by get_float_eps() : %g (%.23f)\n", float_eps_2, float_eps_2);
    printf("The Epsilon of double by get_double_eps(): %g (%.52f)\n", double_eps_2, double_eps_2);

    return 0;
}