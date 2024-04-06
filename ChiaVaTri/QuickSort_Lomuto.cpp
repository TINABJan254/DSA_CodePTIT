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

int lomuto(int *a, int L, int R){
	int pivot = a[R];
	int j = L - 1;
	for (int i = L; i < R; i++){
		if (a[i] <= pivot){
			++j;
			swap(a[j], a[i]);
		}
	}
	swap(a[j + 1], a[R]);
	return (j + 1);
}

void QuickSort(int *a, int L, int R){
	if (L < R){
		int p = lomuto(a, L, R);
		QuickSort(a, L, p - 1);
		QuickSort(a, p + 1, R);
	}
}

void solve(){
	int a[100] = {0, 5, 1, 2, 6, 3, 8, 12, 6, 4};
	QuickSort(a, 0, 9);	

	for (int i = 0; i < 10; i++)
		cout << a[i] <<  ' ';

}

int main(){
	faster();
	solve();
	return 0;
}

/*
Quick sort with lomuto
*/