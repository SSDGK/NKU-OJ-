#include<bits/stdc++.h>
using namespace std;

#define test solve()
#define testm int T; cin >> T; while(T--) solve()

#define rep(i, k, n) for(int i = (k);i <= (n);i++) 
#define srep(i, k, n) for(int i = (k); i >= n; i--)
#define ump unordered_map
#define ust unordered_set
#define ms(a, b) memset(a, (b), sizeof(a))
using ll = long long;
using pii = pair<int, int>;


#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

const int MOD = 998244353;
const int MAXN = 1e5 + 5;
const int MAXF = MAXN << 2;

ll fib[MAXF];
auto init = [] {
    fib[0] = 0, fib[1] = 1;
    rep(i, 2, MAXF - 1)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    return 0;
}();
int arr[MAXN];

vector<vector<ll>> plusm(vector<vector<ll>> a, vector<vector<ll>> b) {
    int n = a.size(), m = b[0].size(), k = a[0].size();
    vector<vector<ll>> ans(n, vector<ll>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans[i][j] = (a[i][j] + b[i][j]) % MOD;
        }
    }
    return ans;
}

vector<vector<ll>> multiply(vector<vector<ll>> a, vector<vector<ll>> b) {
    int n = a.size(), m = b[0].size(), k = a[0].size();
    vector<vector<ll>> ans(n, vector<ll>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int p = 0; p < k; p++) {
                ans[i][j] += a[i][p] * b[p][j] % MOD;
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}

vector<vector<ll>> prof[MAXN << 2];
vector<vector<ll>> pref[MAXN << 2];
vector<vector<ll>> suff[MAXN << 2];
ll all[MAXN << 2];

vector<vector<ll>> ES = {{1, 0}, {0, 1}};

void up(int i) {
    prof[i] = multiply(prof[i << 1], prof[i << 1 | 1]);
    pref[i] = plusm(pref[i << 1], multiply(prof[i << 1], pref[i << 1 | 1]));
    suff[i] = plusm(suff[i << 1 | 1], multiply(suff[i << 1], prof[i << 1 | 1]));
    all[i] = ((all[i << 1] + all[i << 1 | 1]) % MOD + multiply(suff[i << 1], pref[i << 1 | 1])[0][1]) % MOD;
}

void build(int l, int r, int i) {
    if(l == r) {
        int t = arr[l] * 2;
        vector<vector<ll>> M = {{fib[t + 1], fib[t]}, {fib[t], fib[t - 1]}};
        M = plusm(ES, M);
        prof[i] = pref[i] = suff[i] = M;
        all[i] = M[0][1];
    } else {
        int mid = (l + r) / 2;
        build(l, mid, i << 1);
        build(mid + 1, r, i << 1 | 1);
        up(i);
    }
}

void update(int jobl, int jobv, int l, int r, int i) {
    if(l == r) {
        int t = jobv * 2;
        vector<vector<ll>> M = {{fib[t + 1], fib[t]}, {fib[t], fib[t - 1]}};
        M = plusm(ES, M);
        prof[i] = pref[i] = suff[i] = M;
        all[i] = M[0][1];
    } else {
        int mid = (l + r) / 2;
        if(jobl <= mid)
            update(jobl, jobv, l, mid, i << 1);
        else
            update(jobl, jobv, mid + 1, r, i << 1 | 1);
        up(i);
    }
}

struct Info {
    ll all;
    vector<vector<ll>> prof, pref, suff;
    Info(ll a, vector<vector<ll>> b, vector<vector<ll>> c, vector<vector<ll>> d) : all(a), prof(b), pref(c), suff(d) {}
};

Info query(int jobl, int jobr, int l, int r, int i) {
    if(jobl <= l && jobr >= r) {
        return Info(all[i], prof[i], pref[i], suff[i]);
    } else {
        int mid = (l + r) / 2;
        if(jobl > mid) {
            return query(jobl, jobr, mid + 1, r, i << 1 | 1);
        }
        else if(jobr <= mid) {
            return query(jobl, jobr, l, mid, i << 1);
        } else {
            auto li = query(jobl, jobr, l, mid, i << 1), ri = query(jobl, jobr, mid + 1, r, i << 1 | 1);
            auto cprof = multiply(li.prof, ri.prof);
            auto cpref = plusm(li.pref, multiply(li.prof, ri.pref));
            auto csuff = plusm(ri.suff, multiply(li.suff, ri.prof));
            auto call = ((li.all + ri.all) % MOD + multiply(li.suff, ri.pref)[0][1]) % MOD;
            return Info(call, cprof, cpref, csuff);
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    rep(i, 1, n) {
        cin >> arr[i];
    }
    build(1, n, 1);
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int t, v;
            cin >> t >> v;
            update(t, v, 1, n, 1);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(l, r, 1, n, 1).all << endl;
        }
    }

}

int main() {
    IOS;
    test;
}