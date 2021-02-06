#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int, int>> classRange;
vector<int> whatiswhat;
vector<int> myTicket;
vector<vector<int>> tickets;
vector<bool> valid;
vector<vector<int>> workout;


ostream& operator << (ostream& out, const vector<int> &v) {
	for(int i : v) {
		out << i << ' ';
	}
	return out;
}


void parse(const string &filename) {
	//class rules
	string classline;
	ifstream ifs(filename);
	while(getline(ifs, classline) && classline.length()) {
		int t1, f1, t2, f2;
		int pos = classline.find(':');
		string need = classline.substr(pos+1);
		string mid = " or ";
		pos = need.find(mid);
		string beg = need.substr(0, pos), end = need.substr(pos + mid.length()-1);
		//cout << beg << ' ' << end << endl;
		pos = beg.find('-');
		t1 = stoi(beg.substr(0, pos));
		f1 = stoi(beg.substr(pos+1));
		pos = end.find('-');
		t2 = stoi(end.substr(0, pos));
		f2 = stoi(end.substr(pos+1));
		classRange.emplace_back(make_tuple(t1, f1, t2, f2));
	}

	auto parseTicket = [&] (string ticket) {
		vector<int> tokens;
		int pos = -1, init = -1;
		//cout << ticket << endl;
		while((pos = ticket.find(',', init + 1)) != (int) string::npos) {
			string tok = ticket.substr(init+1, pos - init - 1);
			//cout << init << ' ' << pos << ' ' << tok;
			int num = stoi(tok);
			//cout << ' ' << num << endl;
			tokens.emplace_back(num);
			init = pos;
		}
		tokens.emplace_back(stoi(ticket.substr(init+1)));
		return tokens;
	};

	//my ticket
	string ticket;
	//Flush
	getline(ifs, ticket);
	getline(ifs, ticket);
	//cout << ticket << endl;
	myTicket = parseTicket(ticket);

	//other tickets
	string otherTicket;
	for(int i = 0; i < 2; i++)
		getline(ifs, otherTicket);
	while(getline(ifs, otherTicket)) {
		tickets.push_back(parseTicket(otherTicket));
	}


	// init
	whatiswhat.assign(classRange.size(), -1);
	workout.resize(tickets[0].size());
	valid.assign(tickets.size(), true);
}

bool interval(int a, int b, int x) {
	if(x >= a && x <= b)
		return true;
	return false;
}

struct forWhat {
	vector<int> classes;
	bool isValid;
};

forWhat checkInRange(int num) {
	forWhat fw = {vector<int>(), false};
	for(int i = 0; i < (int) classRange.size(); i++) {
		auto limit = classRange[i];
		int l1 = get<0>(limit),
			h1 = get<1>(limit),
			l2 = get<2>(limit),
			h2 = get<3>(limit);
		bool check = (interval(l1, h1, num) || interval(l2, h2, num));
		if(check) {
			fw.classes.push_back(i);
			fw.isValid = true;
		}
	}
	return fw; 
}


void one() {
	int64_t bad = 0;
	for(int i = 0; i < (int) tickets.size(); i++) {
		bool isok = true;
		for(int num : tickets[i]) {
			bool check = checkInRange(num).isValid;
			isok = check;
			if(!check)
				bad += num;
		}
		valid[i] = isok;
	}
	cout << bad << '\n';
}

void two() {
	// consider my ticket
	tickets.push_back(myTicket);
	valid.push_back(true);

	for(size_t tIdx = 0; tIdx < tickets.size(); tIdx++) {
		if(valid[tIdx]) {
			for(size_t pos = 0; pos < tickets[tIdx].size(); pos++) {
				int num = tickets[tIdx][pos];
				forWhat fw = checkInRange(num);
				//cout << "[" << tIdx << ' ' << pos << "]: " << fw.classes << endl;
				// vector of classes satisfying
				if(workout[pos].empty())
					workout[pos].assign(fw.classes.begin(), fw.classes.end());
				else {
					vector<int> res(classRange.size());
					sort(fw.classes.begin(), fw.classes.end());
					sort(workout[pos].begin(), workout[pos].end());
					auto it = set_intersection(
							fw.classes.begin(), fw.classes.end(),
							workout[pos].begin(), workout[pos].end(),
							res.begin()
							);
					res.resize(it - res.begin());
					//cout << "RES: " << res << endl;
					workout[pos].assign(res.begin(), res.end());
				}
			}
		}
	}
	for(size_t pIdx = 0; pIdx < workout.size(); pIdx++) {
		cout << pIdx << ": ";
		for(size_t cIdx = 0; cIdx < workout[pIdx].size(); cIdx++)
			cout << workout[pIdx][cIdx] << ' ';
		cout << endl;
	}
	//int64_t sum = 0;
	//for(int i = 0; i < 6; i++) {
	//	sum += myTicket[whatiswhat[i]];
	//}
	//cout << sum << endl;
}

int main() {
#ifdef LOCAL
	parse("day16.in1");
#else
	parse("day16.in");
#endif
	one();
	two();
	return 0;
}
