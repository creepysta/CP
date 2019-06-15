
//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> scores;
    vector<int> alice;
    vector<int> rank_table;
    vector<int> alice_rank;
    int s_all,s_alice;
    int rank=1,c=0,prev;
    cout<<"Number of scores\n";
    cin>>s_all;
    cout<<"all scores input"<<endl;
    for(int i=0;i<s_all;i++) {
        int num;
        cin>>num;
        scores.push_back(num);
    }
    // cout<<"All scores\n";
    // for(int i=0;i<scores.size();i++) {
    //     cout<<scores[i]<<endl;
    // }

    cout<<"Number of alice scores\n";
    cin>>s_alice;
    cout<<"all scores input"<<endl;
    for(int i=0;i<s_alice;i++) {
        int num;
        cin>>num;
        alice.insert(alice.end(),num);
    }
    // cout<<"Alice scores\n";
    // for(int i=0;i<alice.size();i++) {
    //     cout<<alice[i]<<endl;
    // }

    cout<<"Rank table before printing\n";
    // marking the ranks;
    //int rank=1,prev,c=0;
    int n = int(scores.size());
    cout<<n<<endl;
    for(int i=0;i<n;i++) {
        prev = scores[c];
        if(prev!=scores[i]) {
            rank++;
            c=i;
        }
        rank_table.push_back(rank);
    }
    cout<<"Rank table\n";
    for(int i=0;i<rank_table.size();i++) {
        cout<<rank_table[i]<<endl;
    }

    cout<<"counting alice scores\n";
    c=scores.size()-1;

    if(alice[0]>scores[c]) {
        alice_rank.push_back(rank_table[c]-1);
    }
    else if(alice[0]==scores[c]) {
        alice_rank.push_back(rank_table[c]);
    }
    else if(alice[0]<scores[c]) {
        alice_rank.push_back(rank_table[c]+1);
    }
    for(int i=scores.size()-2, j= 0;i>=0;i--) {
        prev = scores[c];
        if(prev!=scores[i]) {
            if(alice[j]>scores[i]) {
                if(rank_table[i] == 1)
                    alice_rank.push_back(1);
                else
                    alice_rank.push_back(rank_table[i]-1);
            }
            else if(alice[j]==scores[i]) {
                alice_rank.push_back(rank_table[i]);
            }
            else if(alice[j]<scores[i]) {
                alice_rank.push_back(rank_table[i]+1);
            }
            j++;
            c=i;
        }
    }

    cout<<"final alice scores\n";
    for(int i=0;i<alice_rank.size();i++) {
        cout<<alice_rank[i]<<endl;
    }
}

/*
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector<int> rank_table;
    vector<int> alice_rank;
    int rank=1,prev,c=0;
    for(int i=0;i<scores.size();i++) {
        prev = scores[c];
        rank_table.push_back(rank);
        if(prev!=scores[i]) {
            rank++;
            c=i;
        }
    }
    c=0;
    for(int i=0;i<alice.size();i++) {
        prev = scores[c];
        if(prev!=scores[i]) {
            if(alice[i]>scores[i]) {
                alice_rank.push_back(rank_table[i]-1);
            }
            else if(alice[i]==scores[i]) {
                alice_rank.push_back(rank_table[i]);
            }

            else if(alice[i]<scores[i]) {
                alice_rank.push_back(rank_table[i]+1);
            }
            c=i;
        }
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
*/
