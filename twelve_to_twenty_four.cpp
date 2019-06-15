#include<bits/stdc++.h>
using namespace std;

int main ()
{
    string s = "05:45:54PM", ans = "", time, dn = "";
    char arr[s.size()+1];

    for(int i=0;i<s.size()-2; i++)
        ans = ans + s[i];
    // checking day or night
    dn = dn + s[s.size()-2];

    if (dn.compare("A") > 0) {
        if(stoi(ans) != 12) {
            strcpy(arr,ans.c_str());
            int hr = 12 + stoi(strtok(arr,":"));
            time = to_string(hr);
            for(int i = 2; i<ans.size();i++)
                time = time + ans[i];
            ans = time;
        }
    } else {
        if (stoi(ans) == 12) {
            string h = "00";
            for(int i=2;i<ans.size(); i++) {
                h = h + ans[i];
            }
            ans = h;
        }
    }

    cout << ans << endl;

    return 0;
}
