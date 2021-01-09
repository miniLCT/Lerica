// @DateTime:    2021-01-08 12:41:38
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
#define int unsigned long long 
template <typename T>
void read(T &x) {
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    x *= f;
    return;
}
template <typename T>
void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    return;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &x : v) is >> x;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    if (!v.empty()) {
        os << v.front();
        for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];
    }
    return os;
}
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
#define CASET int ___T; read(___T); for(int __CS=1;__CS<=___T;__CS++)
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
constexpr int maxn = 1e6+10; // remember to calculate. if tle, check maxn first.
//ecnu F
struct Mat {
    static const LL M = 110;
    LL v[M][M];
    Mat() { memset(v, 0, sizeof v); }
    void eye() { FOR (i, 0, M) v[i][i] = 1; }
    LL* operator [] (LL x) { return v[x]; }
    const LL* operator [] (LL x) const { return v[x]; }
    Mat operator * (const Mat& B) {
        const Mat& A = *this;
        Mat ret;
        FOR (k, 0, M)
            FOR (i, 0, M) if (A[i][k])
                FOR (j, 0, M)     
                    ret[i][j] = (ret[i][j] + A[i][k] * B[k][j]);
        return ret;
    }
    Mat pow(LL n) const {
        Mat A = *this, ret; ret.eye();
        for (; n; n >>= 1, A = A * A)
            if (n & 1) ret = ret * A;
        return ret;
    }
    Mat operator + (const Mat& B) {
        const Mat& A = *this;
        Mat ret;
        FOR (i, 0, M)
            FOR (j, 0, M)
                 ret[i][j] = (A[i][j] + B[i][j]);
        return ret;
    }
    void prt() const {
        FOR (i, 0, M)
            FOR (j, 0, M)
                 printf("%lld%c", (*this)[i][j], j == M - 1 ? '\n' : ' ');
    }
};

int n , EX , k;
int32_t main()
{
//     freopen("data.in","r",stdin);
//     freopen("out.txt","w",stdout);
    close;
    cin >> k;
    // read(k);
    CASET{
        // cout << "___CS == " << __CS << endl;
        cin >> n >> EX >> k;
        // read(n), read(EX), read(k);
        Mat m, tp;
        tp.eye();
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            // read(x);
            m[0][i] = x;
        }
        while(k--){
            int x, y;
            // read(x), read(y);
            cin >> x >> y;
            x--, y--;
            for(int j = 0; j < n; j++){
                swap(tp[j][x], tp[j][y]);
            }
        }
        Mat ans = m*tp.pow(EX);

        for(int i = 0; i < n; i++){
            // write(ans[0][i]);
            // cout << " \n"[i == n-1];
            cout << ans[0][i] << " \n"[i == n-1];
        }
    }
    return 0;
}