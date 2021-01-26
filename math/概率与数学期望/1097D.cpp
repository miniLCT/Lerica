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
#define int LL
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
constexpr int mod = 1e9+7; // 998244353
// mt19937 dlsrand(random_device{}());
// mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
// int rnd(int x) { return mrand() % x;}
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
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base=2333, P_1=19260817, P_2=999998639;
constexpr int maxn = 1e5+10; // remember to calculate. if tle, check maxn first.
ll dp[maxn][100], p[maxn][100], m , n , k , inv[maxn], val[maxn], num[maxn];
int32_t main()
{
    cin >> n >> k;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0) n /= i, cnt++;
            num[++m] = cnt;
            val[m] = i;
        }
    }
    if(n != 1){
        num[++m] = 1;
        val[m] = n % mod;
    }
    for(int i = 1; i <= 64; i++) {
        inv[i] = get_inv(i);
        cerr << "i === " << i << "  " << get_inv(i) << "   " << get_inv(i , mod) << endl;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= k; j++) {
            for(int l = 0; l <= num[i]; l++){
                dp[j][l] = 0;
            }
        }
        dp[0][num[i]] = 1;
        for(int j = 1; j <= k; j++){
            for(int l = 0; l <= num[i]; l++){
                for(int o = 0; o <= l; o++){
                    add(dp[j][o], 1ll * dp[j - 1][l] * inv[l + 1] % mod);
                }
            }
        }
        for(int j = 0; j <= num[i]; j++){
            p[i][j] = dp[k][j];
        }
    }
    ll ans = 0;
    function<void (int , int , int )> getans = [&](int pos , int sum , int pre){
        if(pos == m + 1) {
            return add(ans , 1ll * sum * pre % mod), void();
        }
        for(int i = 0; i <= num[pos]; i++){
            getans(pos+1, sum, 1ll * pre * p[pos][i] % mod);
            sum = 1ll * sum * val[pos] % mod;
        }
    };
    getans(1, 1, 1);
    cout << ans << endl;
    return 0;
}