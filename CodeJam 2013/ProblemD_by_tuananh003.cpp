#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <complex>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define sr(x) (int)x.size()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; For(_,a,b) cout << x[_] << ' '; cout << endl;}
#define Bit(s,i) ((s&(1<<i))>0)
#define Two(x) (1<<x)
const int modul = 1000000007;
const int nmax = 50;
const int e = 1e-8;
const int pi = acos(-1);
typedef long long ll;
typedef pair<int,int> pii;

int n,c[nmax][nmax],b[nmax][nmax],a[nmax][nmax],m;
int main()
{
 //   freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    For(i,1,n) For(j,1,m) cin >> a[i][j];
    For(i,1,n) For(j,1,m) if (a[i][j]!=0) {
        b[i][j]=a[i][j];
        a[i+1][j+1]-=b[i][j];
        a[i+1][j]-=b[i][j];
        a[i][j+1]-=b[i][j];
        a[i][j]-=b[i][j];
    }
    int k = min(n/2,m/2);
    For(i,1,k) {
        for (int u=i;u<=n-i+1;u+=2) {
            for(int v=i;v<=m-i+1;v+=2) {
                c[u][v]++;
                if (b[u][v]>=c[u][v]) {
                    cout << "R";
                } else {
                    cout << "W";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}









