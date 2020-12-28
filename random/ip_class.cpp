#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int i = 0;
    char c[s.size() - 1], *token;
    strcpy(c,s.c_str());
    cout << atoi(c);
    // token = strtok(c, ".");
    // while(token != NULL) {
    //     int n = stoi(token);
    //
    //     token = strtok(NULL, ".");
    // }

    return 0;
}
