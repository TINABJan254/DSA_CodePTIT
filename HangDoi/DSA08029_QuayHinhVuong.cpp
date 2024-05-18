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

string s, t;
set<string> used;

string delete_space(string x){
	string res = "";
	for (char c : x)
		if (c != ' ')
			res += c;
	return res;
}

string rotateLeftSquare(string x){
	string res = x;
	res[0] = x[3];
	res[1] = x[0];
	res[4] = x[1];
	res[3] = x[4];
	return res;
}

string rotateRightSquare(string x){
	string res = x;
	res[1] = x[4];
	res[2] = x[1];
	res[5] = x[2];
	res[4] = x[5];
	return res;
}

int BFS(){
	queue<pair<string, int>> q;
	q.push({s, 0});
	used.insert(s);
	while (!q.empty()){
		string u = q.front().fi;
		int len  = q.front().se;
		q.pop();
		if (u == t)
			return len;
		string s1 = rotateLeftSquare(u);
		string s2 = rotateRightSquare(u);
		if (used.find(s1) == used.end()){
			q.push({s1, len + 1});
			used.insert(s1);
		}
		if (used.find(s2) == used.end()){
			q.push({s2, len + 1});
			used.insert(s2);
		}
	}
	return -1;
}

void solve(){
	getline(cin, s);
	getline(cin, t);
	s = delete_space(s);
	t = delete_space(t);
	used.clear();
	cout << BFS() << EL;
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
Có một chiếc bảng hình chữ nhật với 6 miếng ghép, trên mỗi miếng ghép được điền một số nguyên trong khoảng từ 1 đến 6. 
Tại mỗi bước, chọn một hình vuông (bên trái hoặc bên phải), rồi quay theo chiều kim đồng hồ.

	4 1 3	<-	1 2 3 	->	1 5 2
	5 2 6 		4 5 6 		4 6 3


Yêu cầu: Cho một trạng thái của bảng, hãy tính số phép biến đổi ít nhất để đưa bảng đến trạng thái đích.

Input:

Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm hai dòng:
Dòng đầu tiên chứa 6 số là trạng thái bảng ban đầu (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
Dòng thứ hai chứa 6 số là trạng thái bảng đích (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
Output: 

Với mỗi test, in ra một số nguyên là đáp số của bài toán.
Ví dụ:

Input
1
1 2 3 4 5 6
4 1 2 6 5 3

Output
2
*/
