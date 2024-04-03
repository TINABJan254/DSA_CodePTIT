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
	int n, s, tmp_s;
	cin >> n >> s;
	if (n * 9 < s || (n > 0 && s == 0)){
		cout << "-1 -1";
		return;
	}

	tmp_s = s;
	int min_num[n + 5] = {0};
	int max_num[n + 5] = {0};
	//generate min number
	--s; //danh cho vtri dau tien
	for (int i = n - 1; i >= 0; i--){
		if (s >= 9){
			min_num[i] = 9;
			s -= 9;
		}
		else {
			min_num[i] = s;
			s = 0;
		}
	}
	++min_num[0];

	//generate max number;
	s = tmp_s;
	for (int i = 0; i < n; i++){
		if (s >= 9){
			max_num[i] = 9;
			s -= 9;
		}
		else{
			max_num[i] = s;
			s = 0;
		}
	}
	
	//display result
	for (int i = 0; i < n; i++)
		cout << min_num[i];
	cout << ' ';
	for (int i = 0; i < n; i++)
		cout << max_num[i];
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho hai số nguyên dương N và S. 
Hãy lựa chọn các chữ số phù hợp để tạo ra số nhỏ nhất và số lớn nhất 
có N chữ số sao cho tổng chữ số đúng bằng S.

Input

Chỉ có một dòng ghi hai số N và S. (0 < N <= 100; 0 <= S <= 900)

Output

Ghi ra hai số nhỏ nhất và lớn nhất tìm được, cách nhau một khoảng trống.

Nếu không thể tìm được thì ghi ra “-1 -1”

Ví dụ
Input
3 20
299 992
2 900

Output
-1 -1
3 0
-1 -1
*/