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

int costs[4];
int values[4];
int draw;
string s1, s2;
int m;

int dp[100][10][10][2][4][4][4][4][3];

int dfs(int n, int m1, int m2, int curs, vector<int> k, int times) {
    int& ans = dp[n][m1][m2][curs][k[0]][k[1]][k[2]][k[3]][times];
    if(ans != -1)
        return ans;
    ans = 0;
    rep(i, 0, 3) {
        if(k[i] != 0 && n >= costs[k[i]]) {
            int cc = k[i];
            k[i] = 0;
            ans = max(ans, dfs(n - costs[cc], m1, m2, curs, k, 0) + values[cc]);
            k[i] = cc;
        }
    }

    if(times != 2) {
        ans = max(ans, dfs(n, m1, m2, curs ^ 1, k, times + 1));

        if(curs == 0) {
            if(m1 < m && n >= draw) {
                rep(i, 0, 3) {
                    if(k[i] == 0) {
                        int cc = s1[m1] - 'a' + 1;
                        k[i] = cc;
                        ans = max(ans, dfs(n - draw, m1 + 1, m2, curs, k, times + 1));
                        k[i] = 0;
                    }
                }
            }
        } else {
            if(m2 < m && n >= draw) {
                rep(i, 0, 3) {
                    if(k[i] == 0) {
                        int cc = s2[m2] - 'a' + 1;
                        k[i] = cc;
                        ans = max(ans, dfs(n - draw, m1, m2 + 1, curs, k, times + 1));
                        k[i] = 0;
                    }
                }
            }
        }

        rep(i, 0, 3) {
            if(k[i] != 0) {
                int cc = k[i];
                k[i] = 0;
                ans = max(ans, dfs(n, m1, m2, curs, k, times + 1));
                k[i] = cc;
            }
        }
    }
    return ans;

}

void solve() {
    int n;
    cin >> n >> m;
    cin >> s1 >> s2;
    cin >> draw >> costs[1] >> values[1] >> costs[2] >> values[2] >> costs[3] >> values[3];
    vector<int> k(4);
    rep(i, 0, 3)
        k[i] = s1[i] - 'a' + 1;
    ms(dp, -1);
    cout << dfs(n, 4, 0, 0, k, 0);
}

int main() {
    IOS;
    test;
}