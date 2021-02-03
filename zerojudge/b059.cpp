#include <iostream>
#include <queue>
#include <set>
#define endl '\n'
using namespace std;
struct node
{
    short x, y, d;
    node(short _x, short _y, short _d)
    {
        x = _x;
        y = _y;
        d = _d;
    }
};
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    short n;
    set<pair<short, short>> s;
    while (cin >> n)
    {
        short min = 9999;
        while (n--)
        {
            short x, y;
            cin >> x >> y;
            s.insert({x, y});
        }
        short sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        queue<node> q;
        q.push(node(sx, sy, 0));
        while (q.size())
        {
            node tmp = q.front();
            q.pop();
            if (tmp.x == dx && tmp.y == dy && min > tmp.d)
            {
                min = tmp.d;
                break;
            }
            if (tmp.x + 1 < 100 && !s.count({tmp.x + 1, tmp.y}))
            {
                if (tmp.x + 3 < 100 && tmp.y + 1 < 100 && !s.count({tmp.x + 3, tmp.y + 1}))
                    q.push(node(tmp.x + 3, tmp.y + 1, tmp.d + 1));
                if (tmp.x + 3 < 100 && tmp.y - 1 >= 0 && !s.count({tmp.x + 3, tmp.y - 1}))
                    q.push(node(tmp.x + 3, tmp.y - 1, tmp.d + 1));
            }
            if (tmp.y - 1 >= 0 && !s.count({tmp.x, tmp.y - 1}))
            {
                if (tmp.x + 1 < 100 && tmp.y - 3 >= 0 && !s.count({tmp.x + 1, tmp.y - 3}))
                    q.push(node(tmp.x + 1, tmp.y - 3, tmp.d + 1));
                if (tmp.x - 1 >= 0 && tmp.y - 3 >= 0 && !s.count({tmp.x - 1, tmp.y - 3}))
                    q.push(node(tmp.x - 1, tmp.y - 3, tmp.d + 1));
            }
            if (tmp.x - 1 >= 0 && !s.count({tmp.x - 1, tmp.y}))
            {
                if (tmp.x - 3 >= 0 && tmp.y - 1 >= 0 && !s.count({tmp.x - 3, tmp.y - 1}))
                    q.push(node(tmp.x - 3, tmp.y - 1, tmp.d + 1));
                if (tmp.x - 3 >= 0 && tmp.y + 1 < 100 && !s.count({tmp.x - 3, tmp.y + 1}))
                    q.push(node(tmp.x - 3, tmp.y + 1, tmp.d + 1));
            }
            if (tmp.y + 1 < 100 && !s.count({tmp.x, tmp.y + 1}))
            {
                if (tmp.x - 1 >= 0 && tmp.y + 3 < 100 && !s.count({tmp.x - 1, tmp.y + 3}))
                    q.push(node(tmp.x - 1, tmp.y + 3, tmp.d + 1));
                if (tmp.x + 1 < 100 && tmp.y + 3 < 100 && !s.count({tmp.x + 1, tmp.y + 3}))
                    q.push(node(tmp.x + 1, tmp.y + 3, tmp.d + 1));
            }
        }
        cout << (min != 9999 ? to_string(min) : "impossible") << '\n';
    }
    return 0;
}
