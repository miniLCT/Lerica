#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define int long long 
#define maxn 1010000
#define maxb 1010
int aa[maxn], cnt[maxn], belong[maxn];
int n, m, size, bnum, now, ans[maxn];
struct query {
	int l, r, id;
} q[maxn];
int cmp(query a, query b) { //玄学奇偶排序
	return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : ((belong[a.l] & 1) ? a.r < b.r : a.r > b.r);
}
/*int cmp(query a,query b)
{
    return (belong[a.l]^belong[b.l])?(a.l<b.l):(belong[a.l]&1)?a.r<b.r:a.r>b.r;
}*/
#define isdigit(x) ((x) >= '0' && (x) <= '9')
int read() {
	int res = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) res = (res << 1) + (res << 3) + c - 48, c = getchar();
	return res;
}
void printi(int x) {
	if(x / 10) printi(x / 10);
	putchar(x % 10 + '0');
}
void add(int x){now+=(2*cnt[aa[x]]+1)*aa[x];cnt[aa[x]]++;}
void del(int x){cnt[aa[x]]--;now-=(2*cnt[aa[x]]+1)*aa[x];}
signed main() {
	freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	n = read(), m = read();
	size = sqrt(n);
	bnum = ceil((double)n / size);
	for(int i = 1; i <= bnum; ++i) 
		for(int j = (i - 1) * size + 1; j <= i * size; ++j) {
			belong[j] = i;
		}
	for(int i = 1; i <= n; ++i) aa[i] = read(); 
	for(int i = 1; i <= m; ++i) {
		q[i].l = read(), q[i].r = read();
		q[i].id = i;
	}
	sort(q + 1, q + m + 1, cmp);
	int l = 1, r = 0;
    /*auto add = [&](int pos){
        now -= aa[pos]*cnt[aa[pos]]*cnt[aa[pos]];
        cnt[aa[pos]]++;
        now += aa[pos]*cnt[aa[pos]]*cnt[aa[pos]];
    };*/
    /*auto del = [&](int pos){
		now -= aa[pos]*cnt[aa[pos]]*cnt[aa[pos]];
        cnt[aa[pos]]--;
        now += aa[pos]*cnt[aa[pos]]*cnt[aa[pos]];
    };*/
	for(int i = 1; i <= m; ++i) {
		int ql = q[i].l, qr = q[i].r;
        //移动指针的常数压缩 玄学优化
        // while(l>ql) add(--l);
        // while(r<qr) add(++r);
        // while(l<ql) del(l++);
        // while(r>qr) del(r--);
		// printf("l == %lld  r == %lld  now == %lld\n", l, r, now);
		if(r<qr){for(r++;r<=qr;r++)add(r);r--;}
		if(r>qr){for(;r>qr;r--)del(r);}
		if(l<ql){for(;l<ql;l++)del(l);}
		if(l>ql){for(l--;l>=ql;l--)add(l);l++;}
		// printf("l == %lld  r == %lld  now == %lld\n", l, r, now);
		
		ans[q[i].id] = now;
	}
	for(int i = 1; i <= m; ++i) printi(ans[i]), putchar('\n');
	return 0;
}