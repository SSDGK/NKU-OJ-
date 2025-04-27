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

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;

ll prod[MAXN << 2];
ll bkt[MAXN << 2];
ll kt[MAXN << 2];
ll lazy_p[MAXN << 2];

void up(int i) {
    int l = i << 1, r = i << 1 | 1;
    prod[i] = prod[l] * prod[r] % MOD;
    bkt[i] = (bkt[l] * prod[r] % MOD + bkt[r]) % MOD;
    kt[i] = (kt[l] * prod[r] % MOD + kt[r]) % MOD;
}

void lazy(int i, int jobp) {
    lazy_p[i] += jobp;
    bkt[i] = (bkt[i] + jobp * kt[i] % MOD) % MOD;
}

void down(int i) {
    if(lazy_p[i]) {
        lazy(i << 1, lazy_p[i]);
        lazy(i << 1 | 1, lazy_p[i]);
        lazy_p[i] = 0;
    }
}

void add(int jobl, int jobr, int jobv, int l, int r, int i) {
    if(jobl <= l && jobr >= r) {
        lazy(i, jobv);
    } else {
        int mid = (l + r) / 2;
        down(i);
        if(jobl <= mid)
            add(jobl, jobr, jobv, l, mid, i << 1);
        if(jobr > mid)
            add(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
        up(i);
    }
}

void multi(int jobl, int jobv, int l, int r, int i) {
    if(l == r) {
        prod[i] = prod[i] * jobv % MOD;
        bkt[i] = bkt[i] * jobv % MOD;
    } else {
        int mid = (l + r) / 2;
        down(i);
        if(jobl <= mid)
            multi(jobl, jobv, l, mid, i << 1);
        else
            multi(jobl, jobv, mid + 1, r, i << 1 | 1);
        up(i);
    }
}


pair<ll, ll> query(int jobl, int jobr, int l, int r, int i) {
    if(jobl <= l && jobr >= r) {
        return {prod[i], bkt[i]};
    } else {
        int mid = (l + r) / 2;
        down(i);
        if(jobr <= mid)
            return query(jobl, jobr, l, mid, i << 1);
        if(jobl > mid)
            return query(jobl, jobr, mid + 1, r, i << 1 | 1);
        auto li = query(jobl, jobr, l, mid, i << 1);
        auto ri = query(jobl, jobr, mid + 1, r, i << 1 | 1);
        ll cprod = li.first * ri.first % MOD;
        ll cbkt = (li.second * ri.first % MOD + ri.second) % MOD;
        return {cprod, cbkt};
    }
}

int fk[MAXN];
int fb[MAXN];

void build(int l, int r, int i) {
    if(l == r) {
        prod[i] = fk[l];
        bkt[i] = fb[l];
        kt[i] = 1;
        lazy_p[i] = 0;
    } else {
        int mid = (l + r) / 2;
        build(l, mid, i << 1);
        build(mid + 1, r, i << 1 | 1);
        up(i);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) {
        int x;
        cin >> x;
        if(x > 0) {
            fk[i] = 1;
            fb[i] = x;
        } else {
            fk[i] = -x;
            fb[i] = 0;
        }
    }
    build(1, n, 1);
    int cnt = 1;
    while(m--) {
        int op, l, r, v;
        cin >> op >> l >> r >> v;
        if(op == 1) {
            add(l, r, v, 1, n, 1);
        }
        else if(op == 2) {
            multi(l, v, 1, n, 1);
        } else {
            auto [pr, bk] = query(l, r, 1, n, 1);
            cout << (cnt * pr % MOD + bk) % MOD << endl;
            cnt++;
        }
    }

}

int main() {
    IOS;
    test;
}