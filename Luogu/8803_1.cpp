#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,ans,k1,sum;
struct ren{
	int m,d,v,t;
}d[1005];
int f[1005][1005],s[1005];
bool cmp(ren a,ren b){
	return a.t<b.t;
}
void dfs(int k,int la,int s){
	if(s>m) return;
	if(k>n){
		ans=max(ans,s);
		return;
	}
	if(f[k][la]>=s) return;
	f[k][la]=s;//最优性剪枝
	dfs(k+1,la,s);
	if(!la || d[k].t-d[la].t>=k1) dfs(k+1,k,s+d[k].v);
}
int dx[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	memset(f,-1,sizeof(f));
	scanf("%d%d%d",&n,&m,&k1);
	for(i=2;i<=12;i++) s[i]=s[i-1]+dx[i-1];//预处理时间
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&d[i].m,&d[i].d,&d[i].v);
		d[i].t=s[d[i].m]+d[i].d;
	}
	sort(d+1,d+1+n,cmp);
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
