#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    int n = s.length();
    vector<int> f(26);
    for(char c : s)
        f[c-'a']++;
    int odd = 0, even = 0;
    for(int i = 0; i < 26; i++) {
        if(f[i] % 2)
            odd++;
        else
            even ++;
    }
    if(odd <= 1)
        return "YES";
    else
        return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

