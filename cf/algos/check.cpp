#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
class Solution {
    struct segtree {
        int size;
        vector<ll> v;
        void init(int n) {
            size = 1;
            while(size < n) size <<= 1;
            v.assign(2*size, 0);
        }
        void build(const vector<int> &a, int x, int lx, int rx) {
            if(rx - lx == 1) {
                if(lx < (int) a.size()) {
                    v[x] = (ll) a[lx];
                }
            }
            int mid = lx + (rx-lx) /2;
            build(a, 2*x+1, lx, mid);
            build(a, 2*x+2, mid, rx);
            v[x] = v[2*x+1] + v[2*x+2];
        }
        void build(const vector<int> a) {
            build(a, 0, 0, size);
        }
        ll sum(int l, int r, int x, int lx, int rx) {
            if(lx >= r || rx <= l) return 0LL;
            if(lx >= l && rx <= r) return v[x];
            int mid = lx + (rx - lx) / 2;
            ll s1 = sum (l, r, 2*x+1, lx, mid);
            ll s2 = sum(l,r, 2*x+2, mid, rx);
            return s1+s2;
        }
        ll sum(int l, int r) {
            return sum(l, r, 0, 0, size);
        }
    };
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        //int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        segtree s1, s2;
        s1.init(n1), s2.init(n2);
        s1.build(nums1);
        s2.build(nums2);
        vector<pair<int, int>> pp;
        for(int ii = 0, jj = 0; ii < n1 && jj < n2;) {
            if(nums1[ii] == nums2[jj]) {
                pp.push_back({ii, jj});
                ii++, jj++;
            }
            else if(nums1[ii] < nums2[jj]) ii++;
            else jj++;
        }
        ll ans = 0;
        for(int ppi = 0; ppi < (int) pp.size(); ppi ++) {
            ans += s1.sum(ppi ? pp[ppi-1].ff : 0, pp[ppi].ff)
                    > s2.sum(ppi ? pp[ppi-1].ss : 0, pp[ppi].ss)
                    ? s1.sum(ppi ? pp[ppi-1].ff : 0, pp[ppi].ff)
                        : s2.sum(ppi ? pp[ppi-1].ss : 0, pp[ppi].ss);
        }
        return ans;
    }
};
