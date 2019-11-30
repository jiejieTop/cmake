/*
 * @Author: jiejie
 * @Github: https://github.com/jiejieTop
 * @Date: 2019-11-26 23:54:34
 * @LastEditTime: 2019-11-30 20:06:38
 * @Description: the code belongs to jiejie, please keep the author information and source code according to the license.
 */
#include <stdio.h>
#include <stdlib.h>
#include "power.h"

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    double result = power(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, result);
    return 0;
}
