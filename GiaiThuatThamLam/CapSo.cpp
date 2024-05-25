#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	int n; cin >> n;
	vector<int> C, L;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		if (x % 2 == 0)
			C.pb(x);
		else
			L.pb(x);
	}
	if (C.sz % 2 == 0)
		cout << "YES\n";
	else{
		for (int i = 0; i < C.sz; i++)
			for (int j = 0; j < L.sz; j++)
				if (abs(C[i] - L[j]) == 1){
					cout << "YES\n";
					return;
				}
		cout << "NO\n";
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Ta gọi L là số lượng ptử lẻ, C số lượng ptử chẵn
Ta có số lượng phần tử là chẵn nên sẽ có 2 TH xảy ra:
	TH1: C là số chẵn và L là số chẵn 
		-> TH này luôn có thể chia
	TH2: C là số lẻ và L là số lẻ
		-> TH này cần check thêm xem có cặp (x,y) nào có abs(x-y) = 1 không
		  brute force (2 for)

PROB:
Ta gọi một cặp số (x, y) là tương tự nhau nếu chúng có cùng tính chất chẵn lẻ hoặc có abs(x - y) = 1. Bạn được cung cấp một mảng A[] có N phần tử, hãy kiểm tra xem có thể chia N phần tử này thành các cặp, sao cho mỗi cặp số đều tương tự nhau.
Input Format
Dòng đầu tiên chứa số nguyên dương N là số chẵn. Dòng 2 chứa N số nguyên của mảng A[]
Constraints
1<=N<=100; 1<=A[i]<=1000;
Output Format
In ra YES nếu có thể chia thành các cặp tương tự, ngược lại in ra NO
Sample Input 0
6
78 17 17 42 11 43 
Sample Output 0
YES

*/
