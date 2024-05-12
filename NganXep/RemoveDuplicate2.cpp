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
	string s; cin >> s >> k;
	stack<pair<char, int>> st;
	for (char c : s){
		if (!st.empty() && st.top().fi == c){
			if (st.top().se + 1 == k)
				st.pop();
			else
				++st.top().se;
		}
		else
			st.push({c, 1});
	}
	
	string res = "";
	while (!st.empty()){
		for (int i = 0; i < st.top().se; i++)
			res += st.top().fi;
		st.pop();
	}
	reverse(res.begin(), res.end());
	if (res == "")
		cout << "EMPTY";
	else
		cout << res;
}

int main(){
	#ifndef ONLINE_JUDGE	
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	solve();
	return 0;
}

/*
Ta sẽ dùng stack<pair<char, int>> để lưu tần suất xuất hiện của kí tự liên tiếp
Khi tần suất mà đủ k thì ta sẽ pop ra, còn nếu chưa đủ k ta lại + 1
 (đối với trường hợp các kí tự liên kề giống nhau)
Còn với stack rỗng hoặc kí tự liền kề ko giống nhau thì push(c, 1);

Cho một xâu kí tự S chỉ bao gồm kí tự in thường, nhiệm vụ của bạn là xóa k kí tự liền kề giống nhau khỏi xâu S. Ví dụ xâu aaabbbcccedddeeu sau khi xóa 3 kí tự liền kề giống nhau khỏi xâu S sẽ trở thành : u
Input Format
Dòng 1 chứa xâu kí tự S; Dòng 2 chứa số nguyên dương k
Constraints
1<=len(S)<=10000; 2<=K<=len(S);
Output Format
In ra xâu S sau khi xóa, in ra EMPTY nếu S trở thành xâu rỗng
Sample Input 0
aabbccedde
2
Sample Output 0
EMPTY
Sample Input 1
aaaccddda
3
Sample Output 1
cca

*/
