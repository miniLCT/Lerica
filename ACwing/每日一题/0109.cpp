// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        v.pb(x);
    }
    sort(v.begin(), v.end());
    ll sum = 0, tp = v[n/2];
    for(auto x : v){
        sum += abs(x - tp);
    }
    cout << sum << endl;
    return 0;
}