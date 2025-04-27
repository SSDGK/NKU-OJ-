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

char ts[6] = {'N', 'K', 'P', 'C', '2', '0'};


void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 6;
    rep(i, 0, n - 6) {
        int t = 0;
        rep(j, 0, 5) {
            if(s[i + j] != ts[j])
                t++;
        }
        ans = min(ans, t);
    }
    cout << ans;
}

int main() {
    IOS;
    test;
}