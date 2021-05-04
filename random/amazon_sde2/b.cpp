#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'routePairs' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER maxTravelDist
 *  2. 2D_INTEGER_ARRAY forwardRouteList
 *  3. 2D_INTEGER_ARRAY returnRouteList
 */

vector<vector<int>> routePairs(int maxTravelDist, vector<vector<int>> forwardRouteList, vector<vector<int>> returnRouteList) {
    sort(returnRouteList.begin(), returnRouteList.end(), 
        [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        }
    );
    set<int> taken;
    int n = forwardRouteList.size();
    auto fn = [&](int k) {
        int l = 0, h = returnRouteList.size() - 1;
        int ans = -1, id = 0;
        while(l <= h) {
            int mid = (l+h)>>1;
            if(returnRouteList[mid][1] <= k) {
                ans = mid;
                l = mid + 1;
            }
            else 
                h = mid - 1;
        }
        return ans;
    };
    vector<vector<int>> got;
    for(int i = 0; i < n; i++) {
        int check = maxTravelDist - forwardRouteList[i][1];
        int idx, iidx;
        if(check >= 0) {
            idx = fn(check);
            if(idx != -1) {
				// edit take all the matching indices
				iidx = fn(check+1);
				for(int it = idx; it < iidx; it++)
					got.push_back({check-returnRouteList[it][1], forwardRouteList[i][0],returnRouteList[it][0]});
				// or just loop as long as same
				//for(int it = idx; returnRouteList[it][1] == returnRouteList[idx][1] && it < (int) returnRouteList.size(); it++)
					//got.push_back({check-returnRouteList[it][1], forwardRouteList[i][0],returnRouteList[it][0]});
            }
        }
    }
    vector<vector<int>> ans;
    if(got.empty())
        return ans;
    sort(got.begin(), got.end(), [&](const vector<int> &a, const vector<int> &b) {
        return a[0] <= b[0];
    });
    ans.push_back({got[0][1], got[0][2]});
    taken.insert(got[0][2]);
    // while(i+1 < (int)got.size()-1 && got[i][0] == got[i+1][0]) {
    //     ans.push_back({got[i+1][1], got[i+1][2]});
    //     i++;
    // }
    for(int i = 1; i < (int) got.size(); i++) {
        if(got[i][0] == got[0][0]) {
            if(taken.find(got[i][2]) == taken.end())
                ans.push_back({got[i][1], got[i][2]});
            taken.insert(got[i][2]);
        }
    }
    return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string maxTravelDist_temp;
    getline(cin, maxTravelDist_temp);

    int maxTravelDist = stoi(ltrim(rtrim(maxTravelDist_temp)));

    string forwardRouteList_rows_temp;
    getline(cin, forwardRouteList_rows_temp);

    int forwardRouteList_rows = stoi(ltrim(rtrim(forwardRouteList_rows_temp)));

    string forwardRouteList_columns_temp;
    getline(cin, forwardRouteList_columns_temp);

    int forwardRouteList_columns = stoi(ltrim(rtrim(forwardRouteList_columns_temp)));

    vector<vector<int>> forwardRouteList(forwardRouteList_rows);

    for (int i = 0; i < forwardRouteList_rows; i++) {
        forwardRouteList[i].resize(forwardRouteList_columns);

        string forwardRouteList_row_temp_temp;
        getline(cin, forwardRouteList_row_temp_temp);

        vector<string> forwardRouteList_row_temp = split(rtrim(forwardRouteList_row_temp_temp));

        for (int j = 0; j < forwardRouteList_columns; j++) {
            int forwardRouteList_row_item = stoi(forwardRouteList_row_temp[j]);

            forwardRouteList[i][j] = forwardRouteList_row_item;
        }
    }

    string returnRouteList_rows_temp;
    getline(cin, returnRouteList_rows_temp);

    int returnRouteList_rows = stoi(ltrim(rtrim(returnRouteList_rows_temp)));

    string returnRouteList_columns_temp;
    getline(cin, returnRouteList_columns_temp);

    int returnRouteList_columns = stoi(ltrim(rtrim(returnRouteList_columns_temp)));

    vector<vector<int>> returnRouteList(returnRouteList_rows);

    for (int i = 0; i < returnRouteList_rows; i++) {
        returnRouteList[i].resize(returnRouteList_columns);

        string returnRouteList_row_temp_temp;
        getline(cin, returnRouteList_row_temp_temp);

        vector<string> returnRouteList_row_temp = split(rtrim(returnRouteList_row_temp_temp));

        for (int j = 0; j < returnRouteList_columns; j++) {
            int returnRouteList_row_item = stoi(returnRouteList_row_temp[j]);

            returnRouteList[i][j] = returnRouteList_row_item;
        }
    }

    vector<vector<int>> result = routePairs(maxTravelDist, forwardRouteList, returnRouteList);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
