// B - Xâu không cân bằng
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<int, int>
#define mii map<int, int>
#define mib map<int, bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvc vector<vc>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sub(x, l, r) (x).begin() + l, (x).begin() + r
#define rsub(x, l, r) (x).rbegin() + l, (x).rbegin() + r
#define FOR(i, a, b) for (int i = a, _b = b; i <= _b; i++)
#define FORD(i, a, b) for (int i = a, _b = b; i >= _b; i--)

#define lcm(a, b) a / gcd(a, b) * b

#define Yes cout << "Yes\n";
#define No cout << "No\n";
#define YesNo Yes else No
#define NoYes No else Yes

template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

#ifdef VanLam
#include <VanLam.h>
#define cer(...) debug_out(__VA_ARGS__)
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define __gcd(a, b) gcd(a, b)
#else
#define cer(...) 20
#define debug(...) 12
#define gcd(a, b) __gcd(a, b)
#endif

// #define int ll

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int maxN = 1e3 + 5;
const int maxMask = 1024 + 5;

int n, k;
string s;
int dp[maxN][maxMask];

inline void prepare()
{
    FOR(i, 0, maxN - 1)
    {
        FOR(mask, 0, maxMask - 1)
        dp[i][mask] = -1;
    }
}

int getBit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

bool isValidMask(int pos, int mask)
{
    if (pos < k)
        return true;

    for (int i = 0; 2 * i < k; i++)
    {
        if (getBit(mask, i) != getBit(mask, k - i - 1))
            return true;
    }

    return false;
}

int DP(int pos, int mask)
{
    if (!isValidMask(pos, mask))
        return 0;

    if (pos == n)
    {
        return 1;
    }

    int &mem = dp[pos][mask];

    if (~mem)
        return mem;

    mem = 0;

    if (s[pos] != 'B')
    {
        int nMask = mask << 1;
        nMask &= (1 << k) - 1;

        mem += DP(pos + 1, nMask);
        mem %= MOD;
    }

    if (s[pos] != 'A')
    {
        int nMask = mask << 1 | 1;
        nMask &= (1 << k) - 1;

        mem += DP(pos + 1, nMask);
        mem %= MOD;
    }

    return mem;
}

inline void _VanLam_()
{
    cin >> n >> k;
    cin >> s;

    cout << DP(0, 0);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen("VanLam.inp", "r"))
    {
        freopen("VanLam.inp", "r", stdin);
        freopen("VanLam.out", "w", stdout);
    }

    prepare();

    int Case = 1;
    // cin >> Case;
    while (Case--)
    {
        cer("- - - -", Case, "- - - -");
        _VanLam_();
        cer("= = = = = = = = = =");
    }

    return 0;
}