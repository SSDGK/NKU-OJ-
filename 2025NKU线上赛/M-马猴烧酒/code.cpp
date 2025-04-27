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

ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1)
            ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    cout << n * qpow(2, n - 1) % MOD << endl;

}

int main() {
    IOS;
    test;
}