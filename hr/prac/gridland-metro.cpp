/*
    author: Creepysta
    03-07-2021 19:57:24
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1e12) + 7;
const int MOD = int(1e9) + 7;
#ifdef LOCAL
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << boolalpha << "[ "; err(_it, args); }
#else
#define debug(args...) ;
#define FIO ;
#endif
#define tmpt template < class T
#define ostop ostream& operator<<(ostream& o
#define itfr { if(x.empty()) {cout<<"[ ]";return o;} o<<"[";for(auto e:x) o<<e<<", ";o<<"\b\b]";return o;}
void err(istream_iterator<string> it) {cerr<<"\b\b ]\n";}
tmpt , class... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<": "<<a<< ", ";err(++it,args...);}
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt > ostop , const multiset<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) {o<<"(";o<<p.first<<", "<<p.second<<")";return o;}

void solve() {
    int N, M, k;
    cin >> N >> M >> k;
    vector<array<int, 3>> a(k);
    vector<bool> taken(k, true);
    for(int i = 0; i < k; i++)
        for(int j = 0; j < 3; j++)
            cin >> a[i][j];
    map<int, vector<int>> m;
    int ans = N * M;
    for(int i = 0; i < k; i++) {
        auto row = a[i];
        int r = row[0], c1 = row[1], c2 = row[2];
        // row taken
        if(c1 == c2) {
            taken[i] = false;
            continue;
        }
        auto it = m.find(r);
        if(it == m.end()) {
            m[r].push_back(c1);
            m[r].push_back(c2);
        } else {
            vector<int> curr(m[r].begin(), m[r].end());
            auto p1 = lower_bound(curr.begin(), curr.end(), c1),
                 p2 = lower_bound(curr.begin(), curr.end(), c2);
            int low = p1 - curr.begin(),
                up  = p2 - curr.begin();
            int sz = curr.size();
            debug(c1, c2, low, up, curr);
            vector<int> tobe;
            //1 2
            //2 4
            //3 5

            int pt;
            if(low == 0) {
                debug(curr, low, up, c1, c2);
                tobe.push_back(c1);
                pt = low;
                while(pt < sz && c2 > curr[pt]) {
                    pt++;
                }
                // TODO : insert c2
                if(pt % 2) {
                    // can only be: c2 <= curr[pt]) : so skip
                    // skip c2;
                    while(pt < sz)
                        tobe.push_back(curr[pt++]);
                } else {
                    if(pt < sz && c2 == curr[pt])
                        pt++;
                    else if(pt < sz && c2 < curr[pt])
                        tobe.push_back(c2);
                    else
                        tobe.push_back(c2);
                    while(pt < sz)
                        tobe.push_back(curr[pt++]);
                }
            }
            else if(low == sz) {
                tobe.assign(curr.begin(), curr.end());
                tobe.push_back(c1);
                tobe.push_back(c2);
            } else {
                if(low % 2) {
                    tobe.assign(curr.begin(), curr.begin() + low);
                    pt = low;
                    while(pt < sz && curr[pt] <= c2) {
                        pt++;
                    }
                    // TODO : insert c2
                    if(pt % 2) {
                        // can only be: c2 <= curr[pt]) : so skip
                        // skip c2;
                        while(pt < sz)
                            tobe.push_back(curr[pt++]);
                    } else {
                        if(pt < sz && c2 == curr[pt])
                            pt++;
                        else if(pt < sz && c2 < curr[pt])
                            tobe.push_back(c2);
                        else
                            tobe.push_back(c2);
                        while(pt < sz)
                            tobe.push_back(curr[pt++]);
                    }
                }
                else {
                    if(c1 < curr[low]) {
                        tobe.assign(curr.begin(), curr.begin() + low);
                        tobe.push_back(c1);
                        pt = low;
                        while(pt < sz && curr[pt] <= c2) {
                            pt++;
                        }
                        // TODO : insert c2
                        if(pt % 2) {
                            // can only be: c2 <= curr[pt]) : so skip
                            // skip c2;
                            while(pt < sz)
                                tobe.push_back(curr[pt++]);
                        } else {
                            if(pt < sz && c2 == curr[pt])
                                pt++;
                            else if(pt < sz && c2 < curr[pt])
                                tobe.push_back(c2);
                            else
                                tobe.push_back(c2);
                            while(pt < sz)
                                tobe.push_back(curr[pt++]);
                        }
                    }
                }
            }
            debug(tobe);
            m[r].assign(tobe.begin(), tobe.end());
        }
    }
    for(auto &el : m) {
        vector<int> e = el.second;
        int sz = e.size();
        debug(e);
        assert(e.size() % 2 == 0);
        for(int i = 0; i < sz-1; i+= 2) {
            ans -= (e[i+1] - (e[i] - 1));
        }
    }
    for(int i = 0; i < k; i++) {
        if(!taken[i]) {
            int r = a[i][0], c = a[i][1];
            if(m.find(r) == m.end()) {
                ans--;
                continue;
            }
            int pos = lower_bound(m[r].begin(), m[r].end(), c) - m[r].begin();
            debug(taken[i], pos, c, m[r]);
            int sz = m[r].size();
            if(pos % 2 == 0) {
                if(pos < sz && c < m[r][pos])
                    ans--;
                else if(pos == sz)
                    ans--;
            }
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    FIO;
    int t = 1;
#ifdef LOCAL
    cin >> t;
#endif
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}

