#include <cstdio>

int data[20][20] = {0};
int n;

int fun(int a, int b);

int main(){
	for(int i = 1; i < 20; i++) data[i][0] = 1;
	scanf("%d", &n);
	printf("%d", fun(0, n));
	return 0;
}

int fun(int a, int b){
	if(a == -1) return 0;
	if(b == -1) return 1;
	if(data[a][b]) return data[a][b];
	else return data[a][b] = fun(a - 1, b) + fun(a + 1, b - 1);
}



//Solution: Simulation

//#include <cstdio>
//#include <queue>
//#include <stack>
//#include <set>
//#include <algorithm>
//using namespace std;
//
//int n;
//set<queue<int> > res;
//queue<int> aa;
//stack<int> bb;
//queue<int> cc;
//int data[20][20] = {0};
//
//void func(queue<int> a, stack<int> b, queue<int> c);
//int pushToRes(queue<int> a, stack<int> b, queue<int> c);
//int fun(int a, int b);
//
//int main(){
//	//	scanf("%d", &n);
//	//	for(int i = 1; i <= n; i++){
//	//		cc.push(i);
//	//	}
//	//	func(aa, bb, cc);
//	//	printf("%d", res.size());
//	
//	//The whole coordinate should be moved!
//	data[1][1] = 0;	//It represents 0, 0
//	for(int i = 1; i < 20; i++) data[i][1] = 1;
//	int n;
//	scanf("%d", &n);
//	printf("%d", fun(1, n + 1));
//	
//	return 0;
//}
//
//void func(queue<int> a, stack<int> b, queue<int> c){
//	if(pushToRes(a, b, c)) return;
//	if(b.empty()){
//		b.push(c.front());
//		c.pop();
//	}
//	//Situation 1 : b -> a
//	int temp = b.top();
//	queue<int> temp_a = a;
//	temp_a.push(temp);
//	b.pop();
//	func(temp_a, b, c);
//	b.push(temp);	//Restore the stack
//	//Situation 2 : c -> b
//	if(pushToRes(a, b, c)) return;
//	b.push(c.front());
//	c.pop();
//	func(a, b, c);
//}
//
//int pushToRes(queue<int> a, stack<int> b, queue<int> c){
//	int ret = 0;
//	if(c.empty()){
//		if(c.empty()){
//			while(!b.empty()){
//				a.push(b.top());
//				b.pop();
//			}
//			res.insert(a);
//			ret = 1;
//		}
//	}
//	return ret;
//}
//
//int fun(int a, int b){
//	
//	if(b == 1) return 1;
//	if(data[a][b]) return data[a][b];
//	else return data[a][b] = fun(a + 1, b - 1) + fun(a - 1, b);
//}
