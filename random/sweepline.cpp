/*
   given A[] - arm size
        P[] - position of an arm at the center
        B - start point
        E - end point
    Find out if pkg can be sent from B to E using Arms A[]
*/

bool solve() {
    int n = p.size();
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        v[i] = make_pair(max(0, p[i]-a[i]), a[i] + p[i]);
    }
    sort(begin(v), end(v));
    vector<pair<int, int>> s;
    for(int i = 0; i < n; i++) {
        int j = i;
        int now = v[i].second;
        while(j < n && now >= v[j].second)
            now = max(now, v[j++].second);
        s.emplace_back(v[i].first, now);
        i = j;
    }
    auto fn = [&] (int x) {
        int l = 0, r = s.size() - 1;
        while(l <= r) {
            int mid = l + (r-l) / 2;
            if(s[mid].first <= x && x <= s[mid].second) {
                return mid;
            }
            else if(s[mid].first > x)
                r = mid - 1;
            else if(s[mid].second < x)
                l = mid + 1;
        }
        return -1;
    };
    int left = fn(B), right = fn(E);
    if(left == right && left != -1)
        return true;
    return false
}
