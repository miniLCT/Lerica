// @DateTime:    2021-01-01 19:24:38
//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <cassert>
#include <bits/stdc++.h>
#include <functional>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define endl '\12'
#define eb emplace_back
#define SZ(a) int32_t(a.size())
#define ALL(x) (x).begin(),(x).end()
#define trav(a,x) for (auto& a: x)
#define LOG(FMT...) fprintf(stderr, FMT)
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr),cout<<fixed<<setprecision(10)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; cin>>___T; for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
constexpr int mod = 1e9+7;
constexpr int Erica = 998244353;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll ex_gcd(ll a, ll b, ll& x, ll& y){if(!b){x=1;y=0;return a;}ll ret=ex_gcd(b,a%b,y,x);y-=a/b*x;return ret;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
int norm(int x) { return x >= mod ? (x - mod) : x; }
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
inline ll get_inv(ll a) { ll x, y; ex_gcd(a, mod, x, y); return norm(x + mod);}
template<class T>inline void umin(T &x, T y) {x = x > y ? y : x;}
template<class T>inline void umax(T &x, T y) {x = x < y ? y : x;}
template<class T>inline void dec(T &x, T y) {x -= y; if(x < 0) x += mod;}
template<class T>inline void add(T &x, T y) {x += y; if(x >= mod) x -= mod;}
const double PI = acos(-1.0);
constexpr int INF = 1e6;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base=2333, P_1=19260817, P_2=999998639;
constexpr int maxn = 510; // remember to calculate. if tle, check maxn first.
int n, a[maxn], dp[maxn][maxn];
int main() {
    close;
    cin >> n;
    vi ans(n+10);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = -INF;
        }
        dp[i][i] = 0;
    } 
    dp[n][n] = 0;
    for(int len = 3; len <= n; len += 3) {
        for(int i = 0; i + len <= n; i++) {
            int j = i + len;
            for(int k = 0; k <= 3; k++) {
                int v = 0;
                for(int l = 0; l < 3; l++){
                    if(l < k) v += a[i+l];
                    else v += a[j-(3-l)];
                }
                umax(v , 0);
                umax(dp[i][j], dp[i+k][j-3+k] + v);
            }
            for (int k = i + 1; k < j - 1; k++)
                dp[i][j] = max (dp[i][j], dp[i+1][k] + dp[k+1][j-1] + max (0, a[i] + a[k] + a[j-1]));
            for (int k = i + 1; k < j-1; k++)
                umax (dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
    for (int i = 0; i <= n; i++)
        ans[i] = -1e7;
    ans[0] = 0;
    for (int i = 0; i < n; i++)
    {
        //cout << ans[i] << "\n";
        for (int j = i + 1; j <= n; j++)
            ans[j] = max (ans[j], ans[i] + max (dp[i][j], 0));
    }
    cout << ans[n] << "\n";
    return 0; 
}