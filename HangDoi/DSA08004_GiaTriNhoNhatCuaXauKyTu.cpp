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

void solve(){
	int k;
	string s; 
	cin >> k >> s;
	int fre[256] = {0};
	for (char c : s)
		fre[c]++;
	priority_queue<int> Q;
	for (int i = 0; i < 256; i++)
		if (fre[i])
			Q.push(fre[i]);
	while (k-- && !Q.empty()){
		int u = Q.top(); Q.pop();
		--u;
		if (u > 0)
			Q.push(u);
	}
	
	ll res = 0;
	while (!Q.empty()){
		res += 1ll * Q.top() * Q.top();
		Q.pop();
	}
	cout << res << EL;
}

int main(){
	faster();
	int TC; cin >> TC;
		while (TC--){
		    solve();
	}	
	return 0;
}

/*
Chú ý trường hợp đề bài cho k lớn hơn độ dài xâu ký tự, vậy thì trường hợp
này ta phải vừa giảm k vừa check Q.empty();

PROB:
Cho xâu ký tự S[] bao gồm các ký tự in hoa [A, B, …,Z]. 
Ta định nghĩa giá trị của xâu S[] là tổng bình phương số lần xuất hiện mỗi 
ký tự trong xâu. 
Ví dụ với xâu S[] = “AAABBCD” ta có F(S) = 32 + 22 + 12 + 12 = 15. 
Hãy tìm giá trị nhỏ nhất của xâu S[] sau khi loại bỏ K ký tự trong xâu.

Input:

Dòng đầu tiên đưa vào số lượng test T (T≤100).
Mỗi test được tổ chức thành 2 dòng. Dòng thứ nhất ghi lại số K. Dòng thứ 2 ghi lại xâu ký tự S[] có độ dài không vượt quá 10^6.
Output:

Đưa ra giá trị nhỏ nhất của mỗi test theo từng dòng.
Input
2
0
ABCC
1
ABCC

Output
6
3
*/
