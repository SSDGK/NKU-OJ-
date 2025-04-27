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
using pli = pair<ll, int>;


#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

vector<vector<pii>> graph;
int high[10001];
int a, b;

ll check(int k, int n) {
    vector<ll> dis(n + 1, LLONG_MAX);
    vector<bool> vis(n + 1, false);
    dis[a] = 0;
    priority_queue<pli, vector<pli>, greater<>> pq;
    pq.push({0, a});
    while(!pq.empty()) {
        auto [d, x] = pq.top();
        pq.pop();
        if(vis[x])
            continue;
        vis[x] = true;
        for(auto [v, w]: graph[x]) {
            if(high[v] >= k && d + w < dis[v]) {
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
    return dis[b];
}

void solve() {
    int n, m, rr, k, c;
    cin >> n >> m >> rr >> k >> c;
    graph.resize(n + 1);
    rep(i, 1, n)
        cin >> high[i];
    vector<vector<int>> line(m, vector<int>(3));
    rep(i, 0, m - 1) {
        cin >> line[i][0] >> line[i][1] >> line[i][2];
    }
    vector<ust<int>> rs(n + 1);
    while(rr--) {
        int x, y;
        cin >> x >> y;
        rs[x].insert(y);
    }
    cin >> a >> b;
    for(auto& ed: line) {
        int x = ed[0], y = ed[1], w = ed[2];
        if(!rs[x].count(y))
            graph[x].push_back({y, w});
        if(!rs[y].count(x))
            graph[y].push_back({x, w});
    }
    if(high[a] >= k && high[b] >= k && check(k, n) <= c) {
        cout << "OK";
        return;
    }
    int l = 0, r = min({k - 1, high[a], high[b]});
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(check(mid, n) <= c)
            l = mid;
        else
            r = mid - 1;
    }
    if(l == 0) {
        cout << "nkuImpact";
    } else {
        cout << l;
    }
}

int main() {
    IOS;
    test;
}