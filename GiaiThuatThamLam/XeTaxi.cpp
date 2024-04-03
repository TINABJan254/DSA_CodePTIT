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
	int n;
	cin >> n;
	int a[n + 5];
	int d[5] = {0};
	for (int i = 0; i < n; i++){
		cin >> a[i];
		d[a[i]]++;
	}

	int res = 0;
	int res4 = d[4];
	res += res4;
	
	int res31 = min(d[3], d[1]);
	d[1] -= res31;
	d[3] -= res31;
	res += res31;

	int res22 = d[2] / 2;
	d[2] = d[2] % 2;
	res += res22;

	int res211 = min(d[2], d[1]);
	d[1] -= res211;
	res += res211;

	int res3 = d[3];
	res += res3;

	int res1111 = d[1] / 4;
	res += res1111;
	if (d[1] % 4)
		++res;

	cout << res;

}

int main(){
	faster();
	solve();
	return 0;
}

/*
Chia ra cac truong hop xe taxi co the cho
taxi = 4
taxi = 3 1
taxi = 2 2
taxi = 2 1 1
taxi = 3
taxi = 1 1 1 1

PROB
N nhóm học sinh, mỗi nhóm từ 1-4 người. Các nhóm học
sinh này dự định sẽ đi tham quan vườn bách thú bằng những chiếc xe taxi, 
mỗi xe taxi trở được tôi đa 4 người. Hãy tìm số lượng taxi tối thiểu để có thể chở hết N 
nhóm học sinh này, biết rằng những học sinh ở cùng 1 nhóm sẽ đi cùng taxi

Input format
 Dòng đầu tiên chứa N là số nhóm học sinh
 Dòng thứ 2 gồm N số là số lượng học sinh của N nhóm
Constraints
 1 <= N <= 10000;
 số lượng học sinh mỗi nhóm là dương và <= 4
Output format
 In ra số lượng taxi tối thiểu
Sample
 Input
 	6
 	2 1 3 1 2 2 
 Output
    3
*/