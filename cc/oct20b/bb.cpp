#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int oo = 1e9 + 5;
const LL ooll = (LL)1e18 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<int>(l, r)(rng)

clock_t start = clock();

const int N = 1e5 + 5;
int v[N], sumn = 0;

void subtask() {
    int n, k;
    cin >> n >> k;
    sumn += n;
    assert(1 <= n && n <= 100000);
    assert(1 <= k && k <= 100000000);
    LL sumv = 0;
    for (int i=0;i<n;++i) {
        cin >> v[i];
        assert(0 <= v[i] && v[i] <= 100000);
        sumv += v[i];
    }
    assert(1 <= sumv && sumv <= 100000);
    int days = 1, answer_me = v[0];
    while(answer_me > 0) {
        int answer = min(answer_me, k);
        if (answer < k) break;
        ++days;
        answer_me -= k;
        if (days <= n) answer_me += v[days-1];
    }
    cout << days << '\n';
}

void solve() {
    int n, k;
    cin >> n >> k;
    sumn += n;
    for (int i=0;i<n;++i) {
        cin >> v[i];
        assert(0 <= v[i] && v[i] <= 100000000);
    }
    LL sum = 0;
    for (int i=0;i<n;++i) {
        sum += v[i];
        if (sum < (i+1) * 1LL * k) {
            cout << i+1 << '\n';
            return;
        }
    }
    cout << sum / k + 1 << '\n';
}

int main() {
    FASTIO;
    int T = 1;
    cin >> T;
    assert(1 <= T && T <= 100000);
    for (int t=1;t<=T;++t) {
        solve();
        // subtask();
    }
    assert(sumn >= T && sumn <= 100000);
    cerr << fixed << setprecision(10);
    cerr << "Time: " << (clock() - start) / (CLOCKS_PER_SEC) << " secs\n"; 
    return 0;
} 
