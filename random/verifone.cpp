/*
1. given n, k and s
where |s| = n
TODO -
flip the bits of s for any given range to have k 1s

make prefix array from left to right and right to left

run linear search to find w

// INP
2
5 4
10010
8 7
11001011


// OP
1
1

// INP
5
13 10
0100001011110
15 1
001111011010000
8 2
01100101
4 1
0111
2 0
10

// OP
1
-1
1
1
1


// INP
5
12 2
111110101010
14 1
11011101011010
13 4
0111101101101
11 10
01101100010
9 7
011000101

// OP
-1
-1
1
-1
1

2.  Choose <= k out of n so that Prod of sum is maximum


priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) > q(cmp);
q.push(make_pair(idx, a.first * a.second))

struct {
    bool operator() (const pair<int, int> l, const pair<int, int> r) {
        return r.first < r.second;
    }
} pcomp;
// considering a is the vector
a[i] = make_pair(a.first * a.second, i);
priority_queue pq(a.begin(), a.end(), pcomp)

take top k (i guess)


// INP
10 4
7 3
2 5
7 4
5 1
10 10
1 5
8 2
1 4
10 9
9 10

// OP
261


// inp
4 3
21 25
7 7
5 10
9 12

// op
525

// INP
15 7
55 43
22 40
86 48
9 36
44 61
32 92
29 1
93 26
47 36
51 40
74 40
21 7
84 51
60 56
51 27


// OP
15555
*/
