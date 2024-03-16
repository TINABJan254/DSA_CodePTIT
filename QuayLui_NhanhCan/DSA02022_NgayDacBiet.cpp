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

string x;

void check(){
	//invalid day
	if (x[0] == '0' && x[1] == '0')
		return;
	//invalid  month
	if (x[3] == '0' || x[2] == '2')
		return;
	//invalid year
	if (x[4] == '0')
		return;
	//display with '/'
	cout << x[0] << x[1] << "/";
	cout << x[2] << x[3] << "/";
	for (int i = 4; i < x.sz; i++)
		cout << x[i];
	cout << EL;
}

void Try(){
	for (int i = 0; i <= 2; i += 2){
		x += to_string(i);
		if (x.sz == 8){
			check();
		}
		else
			Try();
		x.pop_back();
	}
}

void solve(){
	Try();
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Hôm nay là ngày 22/02/2022. Một ngày đặc biệt. Chỉ có hai chữ số là 0 và 2. Đồng thời viết xuôi viết ngược tám chữ số ta đều được cùng một kết quả.

Nhiệm vụ của bạn trong ngày đặc biệt này là hãy liệt kê hết tất cả các ngày hợp lệ chỉ có 2 chữ số 0 và 2.

Một số chú ý:

Luôn có đủ 8 chữ số của ngảy tháng năm và hai dấu gạch chéo.
Ngày và tháng có thể có chữ số 0 ở đầu nhưng với năm thì không được phép. Tức là ta chỉ tính các ngày bắt đầu từ năm 2000 trở về sau.
Bài toán không có dữ liệu vào. Bạn chỉ cần liệt kê kết quả gồm tất cả các ngày tháng hợp lệ. Coi dãy ký tự ngày tháng là một xâu ký tự. Hãy liệt kê theo đúng thứ tự từ điển tăng dần.
*/