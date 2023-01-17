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

const tint MOD = 1e9 + 7;

bool isExcellent(string &num, tint a, tint b)
{
    bool ret = 1;
    forn(i, sz(num)) ret &= (num[i] == (a + '0') || num[i] == (b + '0'));
    return ret;
}

tint binPow(tint num, tint exp)
{
    if (exp == 0)
        return 1;
    tint mid = binPow(num, exp / 2);
    tint ret = (mid * mid) % MOD;
    if (exp % 2 == 0)
        return ret;
    return (ret * num) % MOD;
}

tint MODInv(tint num)
{
    return binPow(num, MOD - 2);
}

tint nchoosek(tint factorial[], tint n, tint k)
{
    tint ans = factorial[n];
    tint denominator = (factorial[n - k]) * factorial[k];
    denominator %= MOD;
    ans *= MODInv(denominator);
    return ans;
}

int main()
{
    fastIO();
    tint a, b, c;
    cin >> a >> b >> c;
    // precalculate factorial numbers (MOD)
    tint factorial[c + 1];
    factorial[0] = 1;
    forsn(i, 1, c + 1) factorial[i] = (factorial[i - 1] * i) % MOD;
    // for each possible amount of a's and b's, check if it is excellent and multiply by the ways to get it
    tint ans = 0;
    forn(i, c + 1)
    {
        tint number = i * a + (c - i) * b;
        string param = to_string(number);
        if (isExcellent(param, a, b))
            ans = (ans + nchoosek(factorial, c, i)) % MOD;
    }
    cout << ans;
}