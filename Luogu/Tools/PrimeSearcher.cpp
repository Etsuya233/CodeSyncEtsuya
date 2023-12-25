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
prime�����¼������ ���prime[0] �൱�� cnt������������
visit������¼������û�б����ʣ����û���ʾ���������
*/
void Prime(){
    for (int i = 2;i <= maxn; i++) {
        //cout<<" i = "<<i<<endl;
        if (!visit[i]) { //����û���ʹ����Ǿ���������
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= maxn; j++) { //������������������ִ��ɸ��
            //cout<<"  j = "<<j<<" prime["<<j<<"]"<<" = "<<prime[j]<<" i*prime[j] = "<<i*prime[j]<<endl;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) { //�����ظ�
                break;
            }
        }
    }
}
