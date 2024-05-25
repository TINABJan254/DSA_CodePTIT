#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	string s; cin >> s;
	int d[256] = {0};
	for (int i = 0; i < s.sz; i++)
		d[s[i]]++;
	int num_fre_odd = 0;
	for (int i = 0; i < 256; i++)
		if (d[i] % 2 != 0)
			++num_fre_odd;
	
	if (num_fre_odd == 0 || (num_fre_odd % 2 != 0))
		cout << "1\n";
	else
		cout << "2\n";
}

int main(){
	faster();
	solve();
	return 0;
}

/*
s ="........."
fre1,...,frek : tuần suất xuất hiện các kí tự khác nhau trong xâu s
trong số fre1 đến frek sẽ có các số chẵn và số lẻ, 
vậy thì số lượng frei mà frei lẻ tạm gọi là L

Một xâu L <= 1 thì có thể sắp xếp thành xâu đối xứng
-> người thắng : nhận được xâu L = 1

mô tả như sau:
đề cho xâu có L = 5;
A : (chẵn) nhận được L lẻ và xóa 1 kí tự -> L thành chẵn
B : (lẻ)   nhận được L chẵn và xóa 1 kí tự -> L thành lẻ
A : (chẵn)
B : (lẻ)
....
chẵn lẻ cứ lặp đi lặp lại, ai nhận được xâu có L lẻ thì lẻ từ đầu đến cuối,
 nhận được xâu có L chẵn thì chẵn từ đầu đến cuối
Và người nhận được xâu L lẻ lúc đầu luôn là người win
	vì mỗi bước ta có thể xóa 1 kí tự => L sẽ tăng hoặc giảm 1 đvị => Lẻ thành chẵn mà chẵn sẽ thành lẻ

PROB:
Tí vào Tèo chơi một trò chơi với xâu kí tự. Luật chơi như sau, ở mỗi lượt chơi 2 người có thể lựa chọn 1 trong 2 thao tác : 1. Hai người đi theo lượt, Tí là người đi trước, ở mỗi lượt đi 2 bạn nhỏ có thể lựa chọn 1 kí tự bất kỳ và xóa kí tự này khỏi xâu S. 2.Lấy xâu S sau đó sắp đặt lại các kí tự trong xâu sao cho nó là một xâu đối xứng thì người đó sẽ thắng. Biết rằng 2 bạn đều chơi tối ưu, bạn hãy xác định xem ai là người chiến thắng ?
Input Format
Dòng duy nhất chứa xâu S
Constraints
S chỉ bao gồm các kí tự in thường và có độ dài không quá 10000
Output Format
Nếu Tí thắng in ra 1, ngược lại nếu Tèo thắng in ra 2
Sample Input 0
kpjdpgb
Sample Output 0
1
Sample Input 1
safjaqih
Sample Output 1
2

*/
