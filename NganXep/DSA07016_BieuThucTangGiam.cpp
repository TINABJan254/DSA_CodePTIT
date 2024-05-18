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
	string s; cin >> s;
	stack<int> st;
	for (int i = 0; i <= s.sz; i++){
		st.push(i + 1);
		if (i == s.sz || s[i] == 'I'){
			while (!st.empty()){
				cout << st.top();
				st.pop();
			}
		}	
	}
	cout << EL;
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
Cho dãy ký tự S chỉ bao gồm các ký tự I hoặc D. Ký tự I được hiểu là tăng (Increasing) ký tự D được hiểu là giảm (Decreasing). Sử dụng các số từ 1 đến 9, hãy đưa ra số nhỏ nhất được đoán nhận từ S. Chú ý, các số không được phép lặp lại. Dưới đây là một số ví dụ mẫu:

A[] = “I”              : số tăng nhỏ nhất là 12.
A[] = “D”            : số giảm nhỏ nhất là 21
A[] =”DD”           : số giảm nhỏ nhất là 321
A[] = “DDIDDIID”: số thỏa mãn 321654798
Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu S
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ length(S) ≤8; .
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input:

4
I
D
DD
DDIDDIID

Output:
12
21
321
321654798
*/
