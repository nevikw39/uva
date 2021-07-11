/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <bits/extc++.h>
#include <bits/stdc++.h>
#ifndef nevikw39
#define nevikw39      \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct _cerr
{
    template <typename T>
    _cerr &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

void dfs(const vector<vector<int64_t>> &t, const vector<int64_t> &c, _hash<int64_t, int64_t> &ht, int64_t &r, int64_t x)
{
    r = max(r, ++ht[c[x]]);
    for (const auto &i : t[x])
        dfs(t, c, ht, r, i);
    --ht[c[x]];
}

int main()
{
    nevikw39;
    int64_t n, r = 0;
    cin >> n;
    vector<vector<int64_t>> t(n);
    vector<int64_t> c(n);
    for (auto &i : c)
        cin >> i;
    for (int64_t i = 1; i < n; i++)
    {
        int64_t a, b;
        cin >> a >> b;
        t[a].push_back(b);
    }
    _hash<int64_t, int64_t> ht;
    dfs(t, c, ht, r, 0);
    cout << r << '\n';
    return 0;
}