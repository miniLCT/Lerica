//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define endl '\12'
#define eb emplace_back
#define SZ(a) int(a.size())
#define ALL(x) (x).begin(), (x).end()
#define trav(a, x) for (auto &a : x)
#define LOG(FMT...) fprintf(stderr, FMT)
#define close \
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c)         \
    (sort(c.begin(), c.end()), \
     c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define CASET    \
    int ___T;    \
    cin >> ___T; \
    for (int __CS = 1; __CS <= ___T; __CS++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr int mod = 1e9 + 7;
constexpr int Erica = 998244353;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int ret = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return ret;
}
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
int norm(int x) { return x >= mod ? (x - mod) : x; }
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
inline ll get_inv(ll a) {
    ll x, y;
    ex_gcd(a, mod, x, y);
    return norm(x + mod);
}
template <class T>
inline void umin(T &x, T y) {
    x = x > y ? y : x;
}
template <class T>
inline void umax(T &x, T y) {
    x = x < y ? y : x;
}
template <class T>
inline void dec(T &x, T y) {
    x -= y;
    if (x < 0) x += mod;
}
template <class T>
inline void add(T &x, T y) {
    x += y;
    if (x >= mod) x -= mod;
}
const double PI = acos(-1.0);
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
constexpr int maxn =
    5000 + 10;  // remember to calculate. if tle, check maxn first.
const int N = 3e5 + 10;
struct Edge {
    int nxt, to, w;
} edge[N << 1];
int head[N], tot, n, u, v, w;
void add_edge(int u, int v, int w) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].w = w;
    head[u] = tot;
}
pii e[maxn];
int f[maxn][maxn], pre[maxn], suf[maxn], val[maxn], cnt;
void dfs(int u, int fa) {
    for (int i = 1; i <= cnt; i++) {
        f[u][i] = 0;
    }
    for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (fa == v) continue;
        dfs(v, u);
        for (int j = 1; j <= cnt; j++) {
            f[u][j] += f[v][j];
        }
    }
    int l = lower_bound(val + 1, val + 1 + cnt, e[u].fi) - val;
    int r = lower_bound(val + 1, val + 1 + cnt, e[u].se) - val;
    pre[0] = suf[cnt + 1] = INF;
    for (int i = 1; i <= cnt; i++) {
        pre[i] = min(pre[i - 1], ((i >= l && i <= r) ? f[u][i] : INF));
    }
    for (int i = cnt; i >= 1; i--) {
        suf[i] = min(suf[i + 1], ((i >= l && i <= r) ? f[u][i] : INF));
    }
    for (int i = 1; i <= cnt; i++) {
        f[u][i] = min(((i >= l && i <= r) ? f[u][i] : INF),
                      min(pre[i - 1], suf[i + 1]) + 1);
    }
}
void up() {
    tot = 0;
    cin >> n;
    memset(head, 0, sizeof head);
    memset(edge, 0, sizeof edge);
    memset(val, 0, sizeof val);
    memset(pre, 0, sizeof pre);
    memset(suf, 0, sizeof suf);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        add_edge(u, v, 1);
        add_edge(v, u, 1);
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> e[i].fi >> e[i].se;
        val[++cnt] = e[i].fi;
        val[++cnt] = e[i].se;
    }
    val[++cnt] = 0;
    sort(val + 1, val + 1 + cnt);
    cnt = unique(val + 1, val + cnt + 1) - (val + 1);
    dfs(1, 0);
    // cout << "---debug---\n";
    // for (int i = 1; i <= cnt; ++i) cout << val[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= cnt; ++j) cout << f[i][j] << " ";
    //     cout << endl;
    // }
    int pos = lower_bound(val + 1, val + 1 + cnt, 0) - val;
    cout << f[1][pos] << endl;
}
int main() {
    close;
    CASET { up(); }
    return 0;
}