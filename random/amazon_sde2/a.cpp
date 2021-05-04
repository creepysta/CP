#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'combineParts' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY parts as parameter.
 */

#define ll int64_t

int combineParts(vector<int> parts) {
    int n = parts.size();
    if(n==1)
    return 0;
    // sort(parts.begin(), parts.end());
    // vector<ll> ans(1, parts[0]+parts[1]);
    // for(int i = 2; i < n; i++) {
    //     ans.push_back(ans.back() + parts[i]);
    // }
    // ll tot = 0;
    // for(ll i : ans)
    // tot += i;
    // return tot;
    multiset<ll> s(parts.begin(), parts.end());
    vector<ll> tots;
    while(s.size() > 1) {
        auto a = s.begin();
        s.erase(a);
        auto b = s.begin();
        s.erase(b);
        int now = *a+*b;
        s.insert(now);
        tots.push_back(now);
    }
    ll ans = 0;
    for(ll i : tots)
        ans += i;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string parts_count_temp;
    getline(cin, parts_count_temp);

    int parts_count = stoi(ltrim(rtrim(parts_count_temp)));

    vector<int> parts(parts_count);

    for (int i = 0; i < parts_count; i++) {
        string parts_item_temp;
        getline(cin, parts_item_temp);

        int parts_item = stoi(ltrim(rtrim(parts_item_temp)));

        parts[i] = parts_item;
    }

    int result = combineParts(parts);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
