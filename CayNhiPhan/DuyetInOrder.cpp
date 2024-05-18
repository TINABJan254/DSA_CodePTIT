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

struct node{
	int data;
	node *left;
	node *right;
};

node *create_node(int x){
	node *tmp = new node;
	tmp->data = x;
	tmp->left = tmp->right = NULL;
	return tmp;
}

void makeRoot(node *root, int u, int v, char c){
	if (c == 'L')
		root->left  = create_node(v);
	else
		root->right = create_node(v);
}

void insertNode(node *root, int u, int v, char c){
	if (root == NULL)
		return;
	if (root->data == u){
		makeRoot(root, u, v, c);
	}
	else{
		insertNode(root->left, u, v, c);
		insertNode(root->right, u, v, c);
	}
}

void inOrder(node *root){
	if (root == NULL)
		return;
	inOrder(root->left); 
	cout << root->data << " ";
	inOrder(root->right);
}

void solve(){
	node *root = NULL;
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		int u, v; char c;
		cin >> u >> v >> c;
		if (root == NULL){
			root = create_node(u);
			makeRoot(root, u, v, c);
		}
		else{
			insertNode(root, u, v, c);
		}
	}
	
	inOrder(root);
}

int main(){
	faster();
	solve();
	return 0;
}

/*
preOrder 	: root -> left  -> right
InOder 		: left -> root  -> right
postOrder 	: left -> right -> root 

Note:
	Mỗi node của cây nhị phân là 1 con trỏ

*/
