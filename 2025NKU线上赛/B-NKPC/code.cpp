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
int dp[100001][6];

int dfs(int i, int j, string& s) {
    if(j == 6) {
        return 0;
    }
    if(i == (int)s.size()) {
        return INT_MAX / 2;
    }
    int& ans = dp[i][j];
    if(ans != -1)
        return ans;
    ans = min(dfs(i + 1, j, s), dfs(i + 1, j + 1, s) + (s[i] == ts[j] ? 0 : 1));
    return ans;
}

void solve() {
    string s;
    cin >> s;
    ms(dp, -1);
    cout << dfs(0, 0, s);
}

int main() {
    IOS;
    test;
}