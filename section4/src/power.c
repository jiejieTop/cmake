/*
 * @Author: jiejie
 * @Github: https://github.com/jiejieTop
 * @Date: 2019-11-27 00:11:33
 * @LastEditTime: 2019-11-28 10:05:14
 * @Description: the code belongs to jiejie, please keep the author information and source code according to the license.
 */

double power(double base, int exponent)
{
    int result = base;
    int i;

    if (exponent == 0) {
        return 1;
    }
    
    for(i = 1; i < exponent; ++i){
        result = result * base;
    }

    return result;
}
