// Di chuyển trong mê cung bản dễ
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

inline void prepare()
{
}

int n, m, Cx, Cy, Dx, Dy;
int dis[maxN][maxN];
char board[maxN][maxN];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool isValid(int x, int y)
{
    return x > 0 && x <= n && y > 0 && y <= m;
}

int bfs()
{
    queue<pii> q;

    q.push({Cx, Cy});
    dis[Cx][Cy] = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        FOR(dir, 0, 3)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (isValid(nx, ny) && board[nx][ny] == '.')
            {
                dis[nx][ny] = dis[x][y] + 1;
                board[nx][ny] = '#';
                q.push({nx, ny});
            }
        }
    }

    return dis[Dx][Dy] - 1;
}

inline void _VanLam_()
{
    cin >> n >> m;
    cin >> Cx >> Cy >> Dx >> Dy;

    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            cin >> board[i][j];
        }
    }

    cout << bfs();
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