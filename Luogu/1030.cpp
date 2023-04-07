#include <iostream>
#include <string>
using namespace std;

string in, post;
int lengthIn, lengthPost;

void dfs(int inH, int inE, int postH, int postE);

int main(){
	cin >> in >> post;
	lengthIn = in.length();
	lengthPost = post.length();
	dfs(0, lengthIn - 1, 0, lengthPost - 1);
}

void dfs(int inH, int inE, int postH, int postE){
	if (inH > inE || postH > postE || (inH < 0) || (inE < 0) || (postH < 0) || (postE < 0)) return;
	cout << post[postE];
	int loc = 0;
	for (int i = inH; i <= inE; i++){
		if (in[i] == post[postE]){
			loc = i;
			break;
		}
	}
	int numberOfLeft = loc - inH;
	dfs(inH, loc - 1, postH, postH + numberOfLeft - 1);
	dfs(loc + 1, inE, postH + numberOfLeft, postE - 1);
}
