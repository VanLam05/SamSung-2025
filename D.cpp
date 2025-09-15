// D - Truy vấn với dãy ngoặc đúng
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
const int maxN = 1e6 + 5;

namespace internal
{
    int ceil_pow2(int n)
    {
        int x = 0;
        while ((1U << x) < (unsigned int)(n))
            x++;
        return x;
    }
    int bsf(unsigned int n)
    {
#ifdef _MSC_VER
        unsigned long index;
        _BitScanForward(&index, n);
        return index;
#else
        return __builtin_ctz(n);
#endif
    }
}
template <class S, S (*op)(S, S), S (*e)()>
struct SegmentTree
{
public:
    SegmentTree() : SegmentTree(0) {}
    SegmentTree(int n) : SegmentTree(std::vector<S>(n, e())) {}
    SegmentTree(const std::vector<S> &v) : _n(int(v.size()))
    {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++)
            d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--)
            update(i);
    }
    void set(int p, S x)
    {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++)
            update(p >> i);
    }
    S get(int p)
    {
        assert(0 <= p && p < _n);
        return d[p + size];
    }
    S prod(int l, int r)
    {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;
        while (l < r)
        {
            if (l & 1)
                sml = op(sml, d[l++]);
            if (r & 1)
                smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
    S all_prod() { return d[1]; }

private:
    int _n, size, log;
    std::vector<S> d;
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

struct S
{
    int o, c;
    S(int _o, int _c)
    {
        o = _o;
        c = _c;
    }
};

S op(S a, S b)
{
    int tmp = min(a.o, b.c);
    return S(a.o + b.o - tmp, a.c + b.c - tmp);
}

S e()
{
    return S(0, 0);
}

inline void prepare()
{
}

inline void _VanLam_()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "#" + s;

    SegmentTree<S, op, e> segTree(n + 5);
    FOR(i, 1, n)
    {
        segTree.set(i, S(s[i] == '(', s[i] == ')'));
    }

    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1)
        {
            swap(s[l], s[r]);
            segTree.set(l, S(s[l] == '(', s[l] == ')'));
            segTree.set(r, S(s[r] == '(', s[r] == ')'));
        }
        else
        {
            S res = segTree.prod(l, r + 1);
            if (res.o == 0 && res.c == 0)
                YesNo;
        }
    }
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