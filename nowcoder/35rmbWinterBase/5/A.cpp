/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-13 13:02:14
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int main()
{
    int n , m ;
    string s , t;
    cin >> n >> m;
    cin >> s >> t;
    int ans = 0;
    for(int i = 0; i < min(n, m ); i++){
        if(s[i]!=t[i])ans++;
    }ans+=abs(n-m);cout << ans << endl;
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/