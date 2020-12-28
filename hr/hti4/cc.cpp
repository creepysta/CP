#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define endl '\n'

struct block {
	ll x, y, d;
	block(ll _x, ll _y, ll _d) : x(_x), y(_y), d(_d){};
};

bool operator<(const block &a, const block &b) {
	if(a.d == b.d) {
		if(a.x != b.x) return a.x < b.x;
		else return a.y < b.y;
	}
	return a.d < b.d;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	ll a[n][m];
	ll dist[n][m];
	for(ll i =0; i< n ;i++) {
		for(ll j = 0; j < m; j++) {
			cin >> a[i][j];
			dist[i][j] = MAX;
		}
	}
	//cout << "input\n";
	//for(ll i=0; i < n; i++, cout << endl) for(ll j=0; j < m;j++) cout << a[i][j] << ' ';
	int dx[] = {-1, 0, 1, 0},
		dy[] = {0, 1, 0, -1};
	dist[0][0] = a[0][0];
	set<block> s;
	s.insert(block(0, 0, a[0][0]));
	while(!s.empty()) {
		block k = *s.begin();
		s.erase(s.begin());
		for(int i = 0; i < 4; i++) {
			ll x = k.x + dx[i];
			ll y = k.y + dy[i];
			if((x >=0 && x < n) && (y >=0 && y < m)) {
				if(dist[x][y] > dist[k.x][k.y] + a[x][y]) {
					if(dist[x][y] != MAX) {
						s.erase(s.find(block(x,y,dist[x][y])));
					}
					dist[x][y] = dist[k.x][k.y] + abs(a[k.x][k.y]-a[x][y]);
					s.insert(block(x,y, dist[x][y]));
				}
			}
		}
	}
	//cout << "dist\n";
	//for(int i = 0; i < n; i++, cout << endl) for(int j = 0; j < m; j++) cout << dist[i][j] << ' ';
	//cout << "Path\n";
	ll ans = MIN;
	ll mind = dist[n-1][m-1], x=n-1, y=m-1;
	pair<ll, ll> remPair = make_pair(n-1,m-1);
	bool visited[n][m];
	memset(visited, 0, sizeof(visited));
	ll mindf = MAX, df = dist[n-1][m-1];
	for(ll i = n-1, j = m-1; ; ) {
		mind = dist[i][j];
		df = dist[i][j];
		mindf = MAX;
		//cout << mind << ' ' << a[i][j] << " for " << remPair.first << ' '<< remPair.second<< endl;
		for(int mov = 0; mov < 4; mov++) {
			x = i + dx[mov];
			y = j + dy[mov];
			if((x >=0 && x < n) && (y >=0 && y < m) && !visited[x][y]) {
				df = dist[i][j] - dist[x][y];
				if(df >= 0 && mindf > df) {
					mindf = df;
					remPair = make_pair(x,y);
				}
				visited[x][y] = 1;
			}
		}
		ans = max(ans, abs(a[i][j] - a[remPair.first][remPair.second]));
		i = remPair.first;
		j = remPair.second;
		if(!i && !j) {
			break;
		}
	}
	cout << ans << endl;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1,tt=1;
	cin >> t;
	while(tt <= t) {
		//cout << "case #" << tt << ":\n";
		solve();
		tt++;
	}

	return 0;
}
