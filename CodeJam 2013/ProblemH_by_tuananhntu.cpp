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
#define LL long long
#define PII pair <int, int>

using namespace std;
pair<int, int> a[6];


bool diff (int a, int  b, int c, int d, int e, int f) {
    int m[6];
    m[0] = a;
    m[1] = b;
    m[2] = c;
    m[3] = d;
    m[4] = e;
    m[5] = f;

    set <int> s;
    FOR (i, 0, 5)
        s.insert(m[i]);
    return (int) s.size() == 6;
}
bool check() {
    set <int> s;
        FOR (i, 1, 6) {
            s.insert(a[i].first);
            s.insert(a[i].second);
        }

    if (s.size() > 3) return false;

    FOR (i, 1, 6)
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);

    FOR (i, 2, 6)
        if (a[i] == a[1]) {
            int i2 = 2;
            if (i2 == i) i2 ++;

            bool ok = true;
            int c = a[i2].first;


            FOR (i3, 2, 6)
                if (i3 != i2 && i3 != i)
                    if (a[i3].first != c && a[i3].second != c) {
                        ok = false;
                        break;
                    }

            if (ok) {
                FOR (i3, 2, 6)
                    FOR (i4, i3 + 1, 6)
                        FOR (i5, 2, 6)
                            FOR (i6, i5 + 1, 6)
                                if (diff(1, i, i3, i4, i5, i6) && a[i3] == a[i4] && a[i5] == a[i6]) {
                                   // cerr << i3 << " " << i4 << " " << i5 << " " << i6 << endl;
                                    int d = a[i3].first;
                                    if (d == c) d = a[i3].second;

                                    int e = a[i4].first;
                                    if (e == c) e = a[i4].second;

                                    int f = a[i5].first;
                                    if (f == c) f = a[i5].second;

                                    int g = a[i6].first;
                                    if (g == c) g = a[i6].second;
                                    //cerr <<c <<" " << d << " " << g << endl;

                                    if (d == e && g == f) {
                                        if (d == a[1].first && g == a[1].second) return true;
                                        if (g == a[1].first && d == a[1].second) return true;
                                    }
                                }

            }

            ok = true;
            c = a[i2].second;

            FOR (i3, 2, 6)
                if (i3 != i2 && i3 != i)
                    if (a[i3].first != c && a[i3].second != c) {
                        ok = false;
                        break;
                    }

            if (ok) {
                FOR (i3, 2, 6)
                    FOR (i4, i3 + 1, 6)
                        FOR (i5, 2, 6)
                            FOR (i6, i5 + 1, 6)
                                if (diff(1, i, i3, i4, i5, i6)) {
                                    int d = a[i3].first;
                                    if (d == c) d = a[i3].second;

                                    int e = a[i4].first;
                                    if (e == c) e = a[i4].second;

                                    int f = a[i5].first;
                                    if (f == c) f = a[i5].second;

                                    int g = a[i6].first;
                                    if (g == c) g = a[i6].second;

                                    if (d == e && g == f) {
                                        if (d == a[1].first && g == a[1].second) return true;
                                        if (g == a[1].first && d == a[1].second) return true;
                                    }
                                }

            }
        }

    return false;
}
int main() {
    //freopen("a.in", "r", stdin);
    while (cin >> a[1].first >> a[1].second) {
        FOR (i, 2, 6)
            cin >> a[i].first >> a[i].second;

        if (check()) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}