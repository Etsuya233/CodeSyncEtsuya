#include<bits/stdc++.h>
using namespace std;
char a[20];
int M[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int l,i,j,k,x,y,z;
	scanf("%s",a);
	l=strlen(a);
	x=(a[0]-48)*10+a[1]-48;
	y=(a[3]-48)*10+a[4]-48;
	z=(a[6]-48)*10+a[7]-48;
	for(i=1960;i<=2059;i++)
	{
		if(i%400==0||(i%4==0&&i%100!=0))
			M[2]=29;
		for(j=1;j<=12;j++)
		{
			for(k=1;k<=M[j];k++)
				if((x==i%100&&y==j&&z==k)||(z==i%100&&x==j&&y==k)||(z==i%100&&y==j&&x==k))
				{
					cout<<i<<"-";
					if(j<10)
						cout<<0;
					cout<<j<<"-";
					if(k<10)
						cout<<0;
					cout<<k<<endl;
				}
		}
		M[2]=28;
	}
}
