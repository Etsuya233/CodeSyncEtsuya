#include <iostream>
using namespace std;

int maxn = 100;
int prime[100000] = {0};
int visit[100000] = {0};

void Prime();

int main(){
	Prime();
	for(int i = 0; i < 100; i++){
		cout << prime[i] << " ";
	}
}


/*
prime数组记录素数， 这个prime[0] 相当于 cnt，用来计数。
visit用来记录数字有没有被访问！如果没访问就是素数！
*/
void Prime(){
    for (int i = 2;i <= maxn; i++) {
        //cout<<" i = "<<i<<endl;
        if (!visit[i]) { //假如没访问过，那就是素数咯
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= maxn; j++) { //遍历所有素数，里面执行筛法
            //cout<<"  j = "<<j<<" prime["<<j<<"]"<<" = "<<prime[j]<<" i*prime[j] = "<<i*prime[j]<<endl;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) { //避免重复
                break;
            }
        }
    }
}
