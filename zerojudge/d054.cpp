#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
template <typename T>
using heap = __gnu_pbds::priority_queue<T>;
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<long long> v(41);
    v[0] = 1;
    v[1] = 1;
    v[2] = 5;
    for (int i = 3; i < 41; i++)
        v[i] = v[i - 1] + (v[i - 2] << 2LL) + (v[i - 3] << 1LL);
    while (t--)
    {
        int n;
        cin >> n;
        cout << v[n] << '\n';
    }
    return 0;
}