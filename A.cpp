// A - Ma trận 3x3
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
const int maxN = 30;

int A, B, C, D, E, F, res, board[9];

void backTrack(int pos)
{
    if (pos == 9)
    {
        res++;
        return;
    }

    FOR(num, 1, maxN)
    {
        board[pos] = num;

        if (pos == 2)
        {
            if (board[0] + board[1] + board[2] == A)
            {
                backTrack(pos + 1);
            }
        }
        else if (pos == 5)
        {
            if (board[3] + board[4] + board[5] == B)
            {
                backTrack(pos + 1);
            }
        }
        else if (pos == 6)
        {
            if (board[0] + board[3] + board[6] == D)
            {
                backTrack(pos + 1);
            }
        }
        else if (pos == 7)
        {
            if (board[1] + board[4] + board[7] == E)
            {
                backTrack(pos + 1);
            }
        }
        else if (pos == 8)
        {
            if (board[6] + board[7] + board[8] == C && board[2] + board[5] + board[8] == F)
            {
                backTrack(pos + 1);
            }
        }
        else
        {
            backTrack(pos + 1);
        }
    }
}

inline void prepare()
{
}

inline void _VanLam_()
{
    cin >> A >> B >> C >> D >> E >> F;
    backTrack(0);
    cout << res;
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