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

void getNextNumber(tint n, tint &currentNumber, tint &currentDivisor)
{
    // find the first number that has a different remainder that currentNumber
    tint a = currentDivisor, b = n + 1, it = 0;
    while (b - a > 1)
    {
        tint mid = (a + b) / 2;
        if ((n / mid) != currentNumber)
            b = mid;
        else
            a = mid;
    }
    currentDivisor = a + 1, currentNumber = n / currentDivisor;
}

vi findRemainders(tint n)
{
    vi ret;
    tint currentNumber = n, currentDivisor = 1;
    while (currentNumber != 0)
    {
        getNextNumber(n, currentNumber, currentDivisor);
        ret.push_back(currentNumber);
    }
    return ret;
}

int main()
{
    fastIO();
    tint t;
    cin >> t;
    while (t--)
    {
        tint n;
        cin >> n;
        vi v = findRemainders(n);
        sort(all(v));
        cout << sz(v) + 1 << "\n";
        for (auto &x : v)
            cout << x << " ";
        cout << n << "\n";
    }
}