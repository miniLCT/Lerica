#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#include <cassert>
using namespace std;
typedef long long LL;
//#define int long long
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(), c.end()), c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define CASET           \
    int ___T;           \
    scanf("%d", &___T); \
    for (int __CS = 1; __CS <= ___T; __CS++)
typedef long long ll, LL;
typedef vector<int> vi;
typedef pair<int, int> pii;
LL bin(LL x, LL n, LL MOD)
{
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1)
            ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
const int maxn = 1e7 + 110;
const int p_max = 1e7 + 110;
int mu[p_max];
bool vis[p_max];
int prime[p_max], p_sz, d, zz[maxn];
void get_mu()
{
    mu[1] = 1;
    FOR(i, 2, p_max)
    {
        if (!vis[i])
        {
            prime[p_sz++] = i;
            mu[i] = -1;
        }
        for (LL j = 0; j < p_sz && (d = i * prime[j]) < p_max; ++j)
        {
            vis[d] = 1;
            if (i % prime[j] == 0)
            {
                mu[d] = 0;
                break;
            }
            else
                mu[d] = -mu[i];
        }
    }
}
int sum[p_max];
void pre()
{
    get_mu();
    for (int i = 0; i < p_sz; i++)
    {
        for (int j = 1; prime[i] * j < p_max; j++)
        {
            zz[j * prime[i]] += mu[j];
        }
    }
    for (int i = 1; i < p_max; i++)
    {
        sum[i] = zz[i] + sum[i - 1];
    }
}
ll fenkuai(int n, int m)
{
    if (n > m)
        swap(n, m);
    ll ret = 0;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = min(n / (n / l), m / (m / l));
        ret += 1ll * (sum[r] - sum[l - 1]) * (n / l) * (m / l);
    }
    return ret;
}
inline ll read()
{
    ll X = 0, w = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        X = (X << 3) + (X << 1) + c - '0', c = getchar();
    return X * w;
}
int32_t main()
{
    pre();
    CASET
    {
        ll ans = 0;
        ll a, b;
        a = read(), b = read();
        ans = fenkuai(a, b);
        printf("%lld\n", ans);
    }
    return 0;
}