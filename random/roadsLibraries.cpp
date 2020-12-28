#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool gr(vector<int> &v1, vector<int> &v2) {
    return v1[0] > v2[0] ? false : true;
}

bool comp(int &a , int &b) {
    return a < b ? 0 : 1;
}

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    long cost = 0;
    bool present = false;
    vector<int> cluster[n+1];
    
    for(int i = 0; i < cities.size(); i++) {
        if(comp(cities[i][0], cities[i][1])) {
            swap(cities[i][0], cities[i][1]);
        }
    }

    sort(cities.begin(), cities.end(), gr);
    for(int i = 0; i < cities.size(); i++) {
        for(int j = 0; j < cities[i].size(); j++) {
            cout << cities[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < cities.size(); i++) {
        
        if(i > 1) {
            for(int j = 1; j < i; j++) {
                    auto it = find(cluster[j].begin(), cluster[j].end(), cities[i][0]);
                    if(it != cluster[j].end()) {
                        if(find(cluster[j].begin(), cluster[j].end(), cities[i][1]) == cluster[j].end())
                        cluster[j].push_back(cities[i][1]);
                        break;
                    }
                    else {
                        cluster[cities[i][0]].push_back(cities[i][1]);
                        break;
                    }
            }
        } else {
            cluster[cities[i][0]].push_back(cities[i][1]);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < cluster[i].size(); j++) {
            cout << cluster[i][j] << "\t";
        }
        cout << "\n";
    }

    for(int i = 1; i <= n; i++) {

        if(cluster[i].size() >0) {
            if(c_lib * (cluster[i].size() + 1) < cluster[i].size() * c_road + c_lib) {
                cost += (cluster[i].size()+1) * c_lib;
            } else {
                cost += (cluster[i].size()) * c_road + c_lib;
            }
        } else {
            for(int j=1; j < i; j++) {
                //  && cluster[i].size() == 0
                if(find(cluster[j].begin(), cluster[j].end(), i) == cluster[j].end()) {
                    present = false;
                    continue;
                } else {
                    present = true;
                    break;
                }
            }
            if(!present) {
                cost += c_lib;
            }
        }
    }

    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
