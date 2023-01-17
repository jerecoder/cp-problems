#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forsn(i, s, n) for (int i = s; i < int(n); i++)
#define dforn(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= s; i--)
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;
using tint = long double;
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
    // Input
    tint n, a, d;
    cin >> n >> a >> d;
    vector<pair<tint, tint>> buses(n);
    forn(i, n) cin >> buses[i].first >> buses[i].second;
    // Sort by starting time
    sort(all(buses));
    // Calculate finishing time for each
    tint lastStartingTime = -1, lastVelocity = -1, lastFinishingTime = -1;
    // Function to update the values of the last batch
    auto newLast = [&lastStartingTime, &lastVelocity, &lastFinishingTime](tint lastStartingTime_, tint lastVelocity_, tint lastFinishingTime_) mutable
    {
        lastStartingTime = lastStartingTime_, lastVelocity = lastVelocity_, lastFinishingTime = lastFinishingTime_;
    };
    // Computes distance moved given time and acceleration
    auto constAcceleration = [](tint acceleration, tint time)
    {
        return 0.5 * acceleration * time * time;
    };
    // Computes time to reach a distance with constant acceleration
    auto twca = [](tint acceleration, tint distance)
    {
        return sqrt(2 * acceleration * distance) / acceleration;
    };
    // Computes time to reach a distance with constant velocity
    auto twcv = [](tint velocity, tint distance)
    {
        return distance / velocity;
    };
    // Computes the finishing time of a bus
    auto finishingTime = [&d, &a, &constAcceleration, &twca, &twcv](pair<tint, tint> bus)
    {
        tint start = bus.first, velocity = bus.second;
        tint timeToReachFinalVelocity = velocity / a;
        if (constAcceleration(a, timeToReachFinalVelocity) > d)
            return start + twca(a, d);
        return (tint)(start + timeToReachFinalVelocity + twcv(velocity, d - constAcceleration(a, timeToReachFinalVelocity)));
    };
    // Computes if the current bus reaches the last batch in time
    auto reaches = [&finishingTime, &lastFinishingTime](pair<tint, tint> bus)
    {
        return finishingTime(bus) < lastFinishingTime;
    };
    // Process each bus
    forn(i, n)
    {
        if (lastStartingTime == -1 || !reaches(buses[i])) // base case
            newLast(buses[i].first, buses[i].second, finishingTime(buses[i]));
        cout << setprecision(10) << fixed << lastFinishingTime << "\n";
    }
}