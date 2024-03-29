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
	//code in DSA03009_SapXepCongViec2.cpp
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho n việc. Mỗi việc được biểu diễn bởi một bộ ba số nguyên dương. 
Trong đó: 
	id: mã cviec
	deadline: thời gian kết thúc
	Profit: Lợi nhuận đem lại nếu hoàn thành công việc đó đúng deadline
Thời gian hoàn thành mỗi công việc là 1 đơn vị thời gian. Hãy cho biết lợi
nhuận lớn nhất có thể để thực hiện các việc với giả thiết mỗi việc được
thực hiện đơn lẻ

Input format
 Dòng 1: số nguyên dương n
 N dòng tiếp theo mô tả id, Deadline, profit của n cviec

Constraints
1 <= n <= 10^5;
1 <= id <= n;
1 <= deadline <= n;
1 <= profit <= 1000;

Ouput format
 In ra lợi nhuận lớn nhất

Sample
Input:
4
1 4 20
2 1 10
3 1 40
3 1 40
4 1 30

Ouput
60
*/