#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int prime[MAXN],phi[MAXN],miu[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
void genphi(int n)
{
    int p=0;
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {p++; phi[i]=i-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
            if(i%prime[j]==0) break;
        }
    }
}
void genmiu(int n)
{
    int p=0;
    memset(miu,0,sizeof(miu));
    miu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {p++; miu[i]=-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            miu[i*prime[j]]=i%prime[j]?-miu[i]:0;
            if(i%prime[j]==0) break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0),cout.tie(0);
    sieve(100000);
    // genphi(100000);
    // genmiu(100000);
    // for(int i=1;i<=10;i++)
    //     printf("%d\n",prime[i]);
    int ps;
    cin >> ps;
    vector<int> b1(ps,-1),a1(ps,-1);
    for(int i = 0; i < ps; i++){
        int x;
        cin >> x;
        int a = -1, b = -1;
        int pp = x;
        for(int i = 0;prime[i] * prime[i] <= x ;i++){
            if(x % prime[i])continue;
            a = 1;
            while(x % prime[i] == 0){
                x /= prime[i];
                a *= prime[i]; 
            }
            break;
        }
        if(x > 1 && a!=-1){
            b = x;
        }else{
            a = -1;
        }
        a1[i] = a, b1[i] = b;
    }
    for(int i = 0; i < ps; i++) cout << a1[i] << " \n"[i == ps-1];
    for(int i = 0; i < ps; i++) cout << b1[i] << " \n"[i == ps-1];
    return 0;
}