#include<bits/stdc++.h>
#define ll long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void input(ll &x,ll &y,ll &l,ll &r) {
	cin>>x>>y>>l>>r;
}

void decToBinary(ll n) 
{ 
	for (ll i = 44; i >= 0; i--) { 
		ll k = n >> i; 
		if (k & 1) 
			cout << "1"; 
		else
			cout << "0"; 
	} 
} 

void output(ll &x,ll &y,ll &result,ll &l) {
	//cout<<endl<<"before ";
	//decToBinary(result);
	for(ll i=44;i>=0;i--) {
		ll setBit=(1ll<<i);
		if(!(y&setBit) && !(x&setBit)) {
			if(result&setBit) {
				ll possibility=result-setBit;
				if(possibility>=l) {
					result=possibility;
				}
			}
		}
	}
	//cout<<endl<<"final ";
	//decToBinary(result);
	//cout<<endl;
	if(result>=l)
		cout<<result<<endl;
	else
		cout<<l<<endl;
}

int main(int argc, char *argv[]) {
	cout << argv[0] << endl;
	fastio
		ll t,x,y,l,r;
	cin>>t;
	while(t--) {
		ll maximum=0,data=0,result=0,flag=0;
		input(x,y,l,r);
		if(y==0)
			cout<<l<<endl;
		else if(x==0)
			cout<<l<<endl;
		else {
			for(ll i=44;i>-1;--i) {
				ll setBit=(1ll<<i);
				ll isrset=(r&(setBit));
				if(isrset) {
					//cout<<"flag and i "<<flag<<" "<<i<<endl;
					if(flag) {
						//cout<<"lnotset - temp =";
						ll possibility=setBit-1+data;
						//decToBinary(possibility);
						//cout<<"  val="; 
						ll fvalue=(x&possibility)*(y&possibility);
						if(fvalue>maximum) {
							result=possibility;
							maximum=fvalue;
						}
						data+=setBit;
						//decToBinary(data);
						//cout<<endl;
						fvalue=(x&data)*(y&data);
						if(fvalue>maximum) {
							result=data;
							maximum=fvalue;
						}
					}
					else {
						ll islset=(l&(setBit));
						if(islset==0) {
							//cout<<"lnotset - temp =";
							ll possibility=setBit-1+data;
							//decToBinary(possibility);
							//cout<<"  val="; 
							ll fvalue=(x&possibility)*(y&possibility);
							if(fvalue>maximum) {
								result=possibility;
								maximum=fvalue;
							}
							data+=setBit;
							//decToBinary(data);
							//cout<<endl;
							fvalue=(x&data)*(y&data);
							if(fvalue>maximum) {
								result=data;
								maximum=fvalue;
							}
							flag=1;
						}
						else {
							//cout<<"lset - val =";
							data+=setBit;
							//decToBinary(data);
							//cout<<endl;
							ll fvalue=(x&data)*(y&data);
							if(fvalue>maximum) {
								result=data;
								maximum=fvalue;
							}
						}
					}
				}
			}
			if(x && y)
				output(x,y,result,l);
		}
	}
	return 0;
}
