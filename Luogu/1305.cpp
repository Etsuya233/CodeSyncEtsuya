#include <iostream>
#include <string>
using namespace std;

typedef struct BTree{
	int l = -1, r = -1;
} bt;

bt arr[27];

void opera(int root);

int main(){
	int n, root = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		string a;
		cin >> a;
		if(!i) root = a[0] - 'a';
		if(a[1] != '*') arr[a[0] - 'a'].l = a[1] - 'a';
		if(a[2] != '*') arr[a[0] - 'a'].r = a[2] - 'a';
	}
	opera(root);
}

void opera(int root){
	if(root == -1) return;
	cout << (char)(root + 'a');
	opera(arr[root].l);
	opera(arr[root].r);
}