#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<algorithm>//ͷ�ļ�
using namespace std;
const int maxn=100+10;
int n,m,t;
int a[maxn][maxn],b[maxn][maxn];
char ch;
int x,y,mbx,mby;
void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
void print(int x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}
int main()
{
    read(n),read(m),read(t);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
        	cin>>ch;
        	if(ch=='*')a[i][j]=b[i][j]=-1;//�����������
        }
    cin>>x>>y>>mbx>>mby;
    a[x][y]=b[x][y]=1;//��ʼ��
    for(int k=1;k<=t;k++)
    {
    	for(int i=1;i<=n;i++)
    	    for(int j=1;j<=m;j++)
    	       if(a[i][j]!=-1)
    	       {
    	       	b[i][j]=0;
    	       	if(a[i-1][j]!=-1)b[i][j]+=a[i-1][j];
    	       	if(a[i+1][j]!=-1)b[i][j]+=a[i+1][j];
    	        if(a[i][j-1]!=-1)b[i][j]+=a[i][j-1];
    	        if(a[i][j+1]!=-1)b[i][j]+=a[i][j+1];
			   }//�ж�������������������ܼ�
		for(int i=1;i<=n;i++)
    	    for(int j=1;j<=m;j++)
    	        a[i][j]=b[i][j];//���ĸ�ֵ
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cout << a[i][j] << " ";
			}
			cout << " \n";
		}
		cout << "\n";
    }
    cout<<a[mbx][mby];
    return 0;
}
