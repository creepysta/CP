/*
    author: Creepysta
    19-11-2021 17:38:14
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1e12) + 7;
const int MOD = int(1e9) + 7;
#ifdef LOCAL
#define FIO ;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << boolalpha << "[ "; err(_it, args); }
#else
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(args...) ;
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
    string num;
    cin >> num;
    int n = num.length();
    string fh = num.substr(0, n/2);
    bool a9s = 1;
    for(char c : num)
        a9s &= c == '9';
    if(a9s) {
        string ans = '1' + string(n-1, '0') + '1';
        cout << ans << '\n';
        return;
    }
    auto incr = [&] (string x) {
        int n = x.length();
        int carry = 1;
        for(int i = n-1; i >= 0; i--) {
            if(x[i] == '9') {
                x[i] = '0';
            } else {
                x[i] = x[i] + carry;
                carry = 0;
            }
        }
        if(carry == 1)
            return '1' + string(n, '0');
        else
            return x;
    };
    auto decr = [&] (string x) {
        int n = x.length();
        int carry = 1;
        for(int i = n-1; i >= 0; i--) {
            if(x[i] == '0') {
                x[i] = '9';
            } else {
                x[i] = x[i] - carry;
                carry = 0;
            }
        }
        if(carry == 1)
            return (string) "-1";
        else
            return x;

    };
    if(n % 2) {
        char mid = num[n/2];
        string rev = fh; reverse(begin(rev), end(rev));
        string c1 = fh + mid + rev;
        string c2 = fh + mid;
        string c22 = c2;
        string up = incr(c2);
        string ffh = up.substr(0, up.length()-1);
        reverse(begin(ffh), end(ffh));
        c2 = up + ffh;
        string down = decr(c22);
        ffh = down.substr(0, down.length()-1);
        reverse(begin(ffh), end(ffh));
        string c3 = down + ffh;
        int m1 = stoll(c1),
            m2 = stoll(c2),
            m3 = stoll(c3);
        int was = stoll(num);
        int s1 = abs(was - m1),
            s2 = abs(was - m2),
            s3 = abs(was - m3);
        if(s1 < s2) {
            if(s1 < s3) {
                //s1
                if(m1 != was) {
                    cout << m1 << endl;
                } else {
                    if(s2 < s3)
                        cout << m2 << endl;
                    else
                        cout << m3 << endl;
                }
            } else {
                //s3
                cout << m3 << endl;
            }
        } else {
            if(s2 < s3) {
                //s2
                cout << m2 << endl;
            } else {
                //s3
                cout << m3 << endl;
            }
        }
    } else {
        char mid = num[n/2];
        string rev = fh; reverse(begin(rev), end(rev));
        string c1 = fh + rev;
        string c2 = fh;
        string c22 = c2;
        string up = incr(c2);
        string ffh = up;
        reverse(begin(ffh), end(ffh));
        c2 = up + ffh;
        string down = decr(c22);
        ffh = down;
        reverse(begin(ffh), end(ffh));
        string c3 = down + ffh;
        int m1 = stoll(c1),
            m2 = stoll(c2),
            m3 = stoll(c3);
        int was = stoll(num);
        int s1 = abs(was - m1),
            s2 = abs(was - m2),
            s3 = abs(was - m3);
        if(s1 < s2) {
            if(s1 < s3) {
                //s1
                if(m1 != was) {
                    cout << m1 << endl;
                } else {
                    if(s2 < s3)
                        cout << m2 << endl;
                    else
                        cout << m3 << endl;
                }
            } else {
                //s3
                cout << m3 << endl;
            }
        } else {
            if(s2 < s3) {
                //s2
                cout << m2 << endl;
            } else {
                //s3
                cout << m3 << endl;
            }
        }
    }
}

int32_t main() {
    FIO;
    int t = 1;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}

