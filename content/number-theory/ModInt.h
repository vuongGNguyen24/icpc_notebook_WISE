/**
 * Author: Vuong Nguyen
 * Description: namespace for modulo basic operations.
 * Status: unit tested 
 */
#include ".\template.h"

namespace ModInt
{
    const int MOD = 1e9 + 7;
    int add(int x, int y)
    {
        return (x + y) % MOD;
    }
    int sub(int x, int y)
    {
        return (x - y + MOD) % MOD;
    }
    int mul(int x, int y)
    {
        return 1ll * x * y % MOD;
    }
    int pow_mod(int x, int y)
    {
        if (y == 0)
            return 1;
        int tg = pow_mod(x, y / 2);
        if (y % 2 == 0)
            return mul(tg, tg);
        return mul(x, mul(tg, tg));
    }
    int inv(int x)
    {
        return pow_mod(x, MOD - 2);
    }
    int div_mod(int x, int y)
    {
        return mul(x, inv(y));
    }
}
using namespace ModInt;
