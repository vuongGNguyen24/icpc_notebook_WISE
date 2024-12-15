/**
 * Author: SnapDragon64
 * Source: https://github.com/SnapDragon64/ContestLibrary/blob/master/math.h
 * Description: funtion for checking a non negative integer number is a prime or not. It work with all number less than $2^{64}$
 * Usage: is_prime($n$)
 * Status: tested on many prime problem 
 * Time: 12 times the complexity of $a^b \mod c$.
 */
inline uint64_t mod_mult64(uint64_t a, uint64_t b, uint64_t m) {
    return __int128_t(a) * b % m;
}
uint64_t mod_pow64(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t ret = (m > 1);
    for (;;) {
        if (b & 1) ret = mod_mult64(ret, a, m);
        if (!(b >>= 1)) return ret;
        a = mod_mult64(a, a, m);
    }
}
bool is_prime(uint64_t n) {
    if (n <= 3) return (n >= 2);
    static const uint64_t millerrabin[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,};
    for (int i = 0; i < sizeof(millerrabin) / sizeof(uint64_t); i++)
    {
        if (n % millerrabin[i] == 0)
            return n == millerrabin[i];
    }
    uint64_t s = n-1, r = 0;
    while (s % 2 == 0) {
        s /= 2;
        r++;
    }
    for (size_t i = 0, j; i < sizeof(millerrabin) / sizeof(uint64_t); i++) {
        uint64_t md = mod_pow64(millerrabin[i], s, n);
        if (md != 1) {
            for (j = 1; j < r; j++) {
                if (md == n-1) break;
                md = mod_mult64(md, md, n);
            }
            if (md != n-1) return false;
        }
    }
    return true;
}