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

string s;

void Try(int i, string cur_str){
	if (i == s.sz){
		cout << cur_str << EL;
		return;
	}
	if (isalpha(s[i])){
		Try(i + 1, cur_str + (char)toupper(s[i]));
		Try(i + 1, cur_str + (char)tolower(s[i]));
	}
	else {
		Try(i + 1, cur_str + s[i]);
	}
}

void solve(){
	cin >> s;
	Try(0, "");
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho xâu ký tự s gồm chữ cái và số, bạn có thể thay đổi chữ cái trong xâu
thành in hoa hoặc in thường tương ứng của nó nhưng không được thay đổi ví trí ban đầu
Bạn hãy liệt kê mọi xâu khác nhau  có thể tạo bằng cách đó, theo thứ tự từ điển tăng dần

Input format
Dòng duy nhất chứa xâu s

constraints

1 <= leng(s) <= 12

Output format
In ra đáp án của bài toán

-----------------------------------------
Sample:

Input
28TeCH

Output
28TECH
28TECh
28TEcH
28TEch
28TeCH
28TeCh
28TecH
28Tech
28tECH
28tECh
28tEcH
28tEch
28teCH
28teCh
28tecH
28tech

*/