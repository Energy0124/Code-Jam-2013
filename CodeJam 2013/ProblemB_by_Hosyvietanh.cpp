#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
#define PII pair <int, int>
#define VI vector<int>

using namespace std;

#define PI acos(-1.0)
#define oo 1000000000
#define maxn 111
#define PIII pair<int,PII>

int f[maxn][maxn];
vector<PII> a[maxn];
int n, q;
bool vis[maxn];

void dp(int u) {
    vis[u] = true;
    f[u][0] = 0;
    REP(i, a[u].size()) {
        int v = a[u][i].F;
        int w = a[u][i].S;
        if (vis[v]) continue;
        dp(v);
        FORD(i, q, 0) FOR(j, 0, i - 1) {
            f[u][i] = max(f[u][i], f[u][i - j - 1] + f[v][j] + w);
        }        
    }
}

int main () {
    //freopen("test.in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n >> q;
    FOR(i, 1, n) FOR(j, 1, q) f[i][j] = -oo;
    REP(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].PB(MP(v, w));
        a[v].PB(MP(u, w));
    }
    dp(1);
    cout << f[1][q] << endl;
    return 0;
}