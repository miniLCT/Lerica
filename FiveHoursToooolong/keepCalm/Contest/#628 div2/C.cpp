#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define close \
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c)         \
    (sort(c.begin(), c.end()), \
     c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define CASET           \
    int ___T;           \
    scanf("%d", &___T); \
    for (int __CS = 1; __CS <= ___T; __CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
int n, ANS[maxn], u[maxn], v[maxn], vis[maxn], zz[maxn];
int main() {
    close;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u[i] >> v[i];
        vis[u[i]]++;
        vis[v[i]]++;
        zz[u[i]] = i;
        zz[v[i]] = i;
    }
    int yz = 0, zb = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 1) {
            yz++;
            ANS[zz[i]] = ++zb;
            if (zb == 3) break;
        }
    }
    if (yz == 2) {
        for (int i = n - 2; i >= 0; i--) {
            cout << i << endl;
        }
        return 0;
    }
    for(int i = 1; i <= n-1;i++){
        if(!ANS[i]){
            cout << zb <<endl;
            zb++;
        }else {
            cout << ANS[i]-1<<endl;
        }
    }
}