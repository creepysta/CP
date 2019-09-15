
//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int binarySearch(vector<int> arr, int l, int r, int x) { 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] < x) 
            return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x); 
    } 
    else
        return (r+l)/2; 
}
    

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

    vector<int> rank_table;
    vector<int> alice_rank;

    int rank = 1;
    rank_table.push_back(rank);

    for(int i = 1; i < scores.size(); i++) {
        if(scores[i] < scores[i-1]) {
            rank ++;
            rank_table.push_back(rank);
        } else {
            rank_table.push_back(rank);
        }
    }

    int max_score = *max_element(scores.begin(), scores.end());

    for(int i = 0; i < alice.size(); i++) {
        int pos = binarySearch(scores, 0, scores.size()-1, alice[i]);

        // if(alice[i] > scores[pos]) {
        //     if(alice_rank[pos] == 1)
        //         alice_rank.push_back(rank_table[pos]);
        //     else
        //         alice_rank.push_back(rank_table[pos]-1);
        // } 

        if(alice[i] > scores[pos]) {
            if(alice[i] >= scores[0]) {
                alice_rank.push_back(1);
            } else {
                alice_rank.push_back(rank_table[pos]-1);
            }
        }

        else if(alice[i] < scores[pos]) {
            alice_rank.push_back(rank_table[pos] + 1);
        }
        else if(alice[i] == scores[pos]) {
            alice_rank.push_back(rank_table[pos]);
        }

    }

    for(int i = 0; i < rank_table.size(); i++) {
        cout << alice_rank[i] << endl;
    }


    return alice_rank;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
            return x == y and x == ' ';
            });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
