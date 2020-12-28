/*
	author: Creepysta
 */
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

double babylonRoot(long long num) {
	double x = num;
	double y = 1;
	double e = 0.0000001;
	while(x - y > e) {
		x = (x+y)/2;
		y = num / x;
	}
	return x;
}

long long binarySearchRoot(long long num) {
	long long low = 0, high = num, ans;
	while(low <= high) {
		long long mid = low + (high - low) / 2;
		if(mid * mid == num)
			return mid;
		else if(mid * mid < num) {
			ans = mid;
			low = mid+1;
		} else
			high = mid-1;
	}
	return ans;
}

long long power(long long a, long long b, long long mod) {
	long long res = 1ll;
	while(b) {
		if(b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

long long gcd(long long a, long long b) {
	while(b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

long long fgcd(long long a, long long b) {
	if(!a || !b)
		return a | b;
	unsigned shift = __builtin_ctzll(a | b);
	a >>= __builtin_ctzll(a);
	do {
		b >>= __builtin_ctzll(b);
		if(a > b)
			swap(a, b);
		b -= a;
	} while (b);
	return  a << shift;
}

int extgcd(int a, int b, int &x, int &y) {
	x = 0, y = 1;
	int x1 = 1, y1 = 0, a1 = a, b1 = b;
	while(b1) {
		int q = a1 / b1;
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, y - q * y1);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}
	return a1;
}

