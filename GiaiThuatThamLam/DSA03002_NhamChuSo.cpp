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
	string a1, b1, a2, b2;
	cin >> a1 >> b1;
	a2 = a1; b2 = b1;
	for (int i = 0; i < a1.sz; i++){
		if (a1[i] == '6')
			a1[i] = '5';
		else if (a2[i] == '5')
			a2[i] = '6'; 
	}
	for (int i = 0; i < b1.sz; i++){
		if (b1[i] == '6')
			b1[i] = '5';
		else if (b2[i] == '5')
			b2[i] = '6'; 
	}
	int sum_min = stoi(a1) + stoi(b1);
	int sum_max = stoi(a2) + stoi(b2);
	cout << sum_min << ' ' << sum_max;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Trong một buổi học toán, giáo viên viết 2 số nguyên, A và B, và yêu cầu Tèo thực hiện phép cộng. Tèo không bao giờ tính toán sai, nhưng thỉnh thoảng cậu ta chép các con số một cách không chính xác. Lỗi duy nhất của là ghi nhầm '5' thành '6' hoặc ngược lại.  Cho hai số, A và B, tính tổng nhỏ nhất và lớn nhất mà Tèo có thể nhận được.

Input: Có một dòng chứa hai số nguyên dương A và B ( 1 ≤ A, B ≤ 1 000 000).

Output: In ra 2 số nguyên cách nhau một dấu cách, tổng nhỏ nhất và lớn nhất có thể nhận được.

Ví dụ:

Test 1
Input:
11 25

Ouput:
36 37

Test 2
Input:
1430 4862

Ouput:
6282 6292

Test 3
Input:
16796 58786

Ouput:
74580 85582
*/