#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = s; i < int(n); i++)
#define dforn(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= s; i--)
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;
using tint = long long;
using vi = vector<tint>;

inline void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

template <typename T>
inline void chmax(T &lhs, T rhs)
{
    lhs = max(lhs, rhs);
}

template <typename T>
inline void chmin(T &lhs, T rhs)
{
    lhs = min(lhs, rhs);
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)
{
    os << "[";
    forn(i, sz(v))
    {
        if (i > 0)
            os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

int main()
{
    fastIO();
    tint n, m;
    cin >> n >> m;
    vi v(n);
    forn(i, n) cin >> v[i];
    if (n > m)
    {
        cout << 0;
        return 0;
    }
    tint ret = 1;
    forn(i, n)
    {
        forsn(j, i + 1, n)
        {
            ret = ret * abs(v[i] - v[j]) % m;
            ret %= m;
        }
    }
    cout << ret;
}