#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

ll F[100] = {0}; //So luong tu cua xau thu n

void Init(){
	F[1] = 1;
	F[2] = 1;
	F[3] = 2;
	for (int i = 4; i <= 60; i++)
		F[4] = F[i - 1] + F[i - 2] + F[i - 3];
}

string find(int n, ll k){
	if (n == 1)
		return "28tech";
	if (n == 2)
		return "C++";
	if (n == 3){
		if (k == 1)
			return "DSA";
		else
			return "JAVA";
	}

	if (k <= F[n - 3])
		return find(n - 3, k);
	if (k <= F[n - 2] + F[n - 3])
		return find(n - 2, k - F[n - 3]);
	return find(n - 1, k - F[n - 2] - F[n - 3]);
		
}

void solve(){
	int n; ll k;
	cin >> n >> k;
	cout << find(n, k) << EL;
}

int main(){
	Init();
	faster();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
Bài toán lớn đó là Find(n, k)
Bài toán con nhỏ nhất là - Find(1, 1) = 28tech
						 - Find(2, 1) = C++
						 - Find(3, k) = Find(3, 1) = DSA
						 		      = Find(3, 2) = JAVA
=> Lời giải bài toán tổng quát là 
 Find(n, k) = Find(n - 3, k); 	        		     nếu k <= F[n - 3] (Số từ của xâu thứ n - 3)
 Find(n, k) = Find(n - 2, k - F[n - 3]); 		     nếu F[n - 3] < k <= F[n - 3] + F[n - 2];
 Find(n, k) = Find(n - 1, k - F[n - 2] + F[n - 3]);  nếu F[n - 3] + F[n - 2] < k <= F[n -3] + F[n - 2] + F[n - 1]


PROB:
Xâu F được định nghĩa như sau:
 F(1) = 28tech
 F(2) = C++
 F(3) = DSA JAVA
 
 F(n) = F(n - 3) + " " + F(n - 2) + " " + F(n - 1);
=> F(4) = "28tech C++ DSA JAVA"
=> F(5) = "C++ DSA JAVA 28tech C++ DSA JAVA"

Nhiệm vụ của bạn là tìm từ thứ k trong xâu F(n), dữ liệu đảm bảo tồn tại từ thứ k

Input format
	dòng 1: T bộ test
	dòng 2: 2 số n và k
Output format	
	In ra đáp án của đề bài mỗi test 1 dòng
Constraints
	1 <= T <= 100
	1 <= N <= 60
	1 <= K <= 10^16

Sample

Input
3
3 2
4 2
5 4

Out
JAVA
C++
28tech

*/