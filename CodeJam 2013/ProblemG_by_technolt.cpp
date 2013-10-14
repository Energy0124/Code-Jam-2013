//Written by technolt~h
 
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
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()
 
#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << (a[_]) << ' '; cerr << endl;}
#define ll long long
using namespace std;
 
const double PI = 2.0 * acos (0.0);
 
typedef long long LL;
typedef pair <int, int> PII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

#define maxn 511

struct point {
    ll x,y,z;
} red[maxn],blue[maxn];

bool intersect(point a,point b,double r) {
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z))<r*2-(1e-8);
}

int n;

int low[maxn],num[maxn],com[maxn],cnt,ncom;
bool visited[maxn];
vector<int> a[maxn];
stack<int> s;

void dfs(int u) {
    low[u]=num[u]=++cnt;
    s.push(u);
    
    REP(i,a[u].size()) {
        int v=a[u][i];
        if(!visited[v]) {
            if(num[v]==0) {
                dfs(v);
                low[u]=min(low[u],low[v]);
            } else low[u]=min(low[u],num[v]);
        }
    }
    
    if(low[u]==num[u]) {
        ncom++;
        while(1) {
            int v=s.top();
            s.pop();
            com[v]=ncom;
            visited[v]=true;
            if(v==u) break;
        }
    }
}

int lab(int x) {
    if(x>0) return x;
    return n+abs(x);
}

void add(int x,int y) {
    a[lab(-x)].PB(lab(y));
    a[lab(-y)].PB(lab(x));
}

bool twoSat() {
    RESET(low,0);
    RESET(num,0);
    cnt=0;
    ncom=0;
    RESET(com,0);
    RESET(visited,false);
    
    FOR(i,1,2*n) if(!visited[i]) dfs(i);
    
    FOR(i,1,n) if(com[lab(i)]==com[lab(-i)]) return false;
    return true;
}

bool chk(double r) {
    FOR(i,1,2*n) a[i].clear();
    
    FOR(i,1,n) FOR(j,i+1,n) {
        if(intersect(red[i],red[j],r))
            add(-i,-j);
        
        if(intersect(red[i],blue[j],r))
            add(-i,j);
        
        if(intersect(blue[i],red[j],r))
            add(i,-j);
        
        if(intersect(blue[i],blue[j],r))
            add(i,j);
    }
    
    return twoSat();
}

int main() {
	//freopen("a.inp","r",stdin);
	while(cin >> n) {
        FOR(i,1,n) cin >> red[i].x >> red[i].y >> red[i].z >> blue[i].x >> blue[i].y >> blue[i].z;
        
        double low=0,high=1e8;
        
        FOR(z,1,40) {
            double mid=(low+high)/2;
            if(chk(mid)) low=mid;
            else high=mid;
        }
        printf("%.3lf\n",low-0.0005);
	}
}
