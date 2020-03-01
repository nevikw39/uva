#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n && n)
    {
        long long r = 0, t, l = 0;
        while (n--)
        {
            cin >> t;
            r += abs(l);
            l += t;
        }
        cout << r << '\n';
    }
    return 0;
}