#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    char arr[s.size()+1];
    vector<char> v;
    vector<char>::iterator it;
    strcpy(arr,s.c_str());
    int p1 = 0, p2 = 0;
    while(arr[p1]) {
        if(arr[p1] != ' ') {
            arr[p2++] = arr[p1];
        }
        p1 ++;
    }
    arr[p2] = '\0';
    int pointer=0;
    while(arr[pointer] != '\0') {
        v.push_back(arr[pointer++]);
    }

    sort(v.begin(), v.end());
    it = unique(v.begin(),v.end());
    v.resize(std::distance(v.begin(), it));
    for(int i = 0; i < 26; i++) {
        it = std::find (v.begin(), v.end(), (char)(i+97));
        if (it != v.end())
        {
            continue;
        }
        else {
            return "not pangram";
        }
    }
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
