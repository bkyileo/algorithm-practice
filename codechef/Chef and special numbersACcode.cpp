#include <cstring>
#include <cstdio>
using namespace std;
 
const int MAXL = 19, LCM = 2520;
 
int K, N[MAXL], mods[MAXL];
long long res[MAXL][1 << 9][LCM];
 
long long calc(bool pref, int left, int mask, int mod)
{
    if (!pref && res[left][mask][mod] != -1)
        return res[left][mask][mod];
 
    long long cur = 0;
 
    if (left == 0) {
        int spec = 0;
        for (int d = 1; d <= 9; ++d)
            if (mod % d == 0 && (mask & (1 << (d - 1)))) ++spec;
        cur = (spec >= K);
    } else {
        for (int d = 0; d <= (pref ? N[left - 1] : 9); ++d) {
            bool new_pref = (pref && (d == N[left - 1]));
            int new_mask = (d == 0) ? mask : (mask | (1 << (d - 1)));
            int new_mod = (mod + d * mods[left - 1]) % LCM;
            cur += calc(new_pref, left - 1, new_mask, new_mod);
        }
    }
 
    if (!pref)
        res[left][mask][mod] = cur;
 
    return cur;
}
 
void sep(long long n)
{
    memset(N, 0, sizeof(N));
    int len = 0;
    while (n > 0) {
        N[len++] = n % 10;
        n /= 10;
    }
}
 
int main()
{
    mods[0] = 1;
    for (int i = 1; i < MAXL; ++i)
        mods[i] = (10 * mods[i - 1]) % LCM;
 
    int Q; scanf("%d", &Q);
    for (int q = 0; q < Q; ++q) {
        memset(res, -1, sizeof(res));
        long long L, R, answer = 0;
        scanf("%lld%lld%d", &L, &R, &K);
 
        sep(R);
        answer += calc(true, MAXL, 0, 0);
        sep(L - 1);
        answer -= calc(true, MAXL, 0, 0);
 
        printf("%lld\n", answer);
    }
 
    return 0;
}
