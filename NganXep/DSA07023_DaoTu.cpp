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
	string s; 
	getline(cin, s);
	stringstream ss(s);
	stack<string> st;
	while (ss >> s) st.push(s);
	while (!st.empty()){
		cout << st.top() << ' ';
		st.pop();
	}
	cout << EL;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	int TC; cin >> TC;
	cin.ignore();
	while (TC--){
	    solve();
	}
	return 0;
}

/*
Cho xâu ký tự S. Nhiệm vụ của bạn là đảo ngược các từ trong S. 
Ví dụ S =  “I like this program very much”, ta nhận được kết quả là “much very program this like I”.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S.
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ Length(S)≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input:
2
I like this program very much
much very program this like I

Output
much very program this like I
I like this program very much
*/
