#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int num,ans;
vector<vector<int>> edge;
int fa[1000000];
int vis[1000000];
int n;
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void dfs(int op,int ed,vector<int> path)
{
	vis[op]=1;
	if(op==ed)
	{
		sort(path.begin(),path.end());//ע����ĿҪ������С�����˳�����
		for (int i:path)
		{
			cout<<i<<" ";
		}
		return;
	}
	for (auto i:edge[op])
	{
		if(vis[i]==0)
		{
			vector<int> s=path;
			s.push_back(i);
			dfs(i,ed,s);
		}
	}
}
int main()
{

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	edge.resize(n+1);
	int x,y;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y;
		edge[x].push_back(y);//vector��ͼ
		edge[y].push_back(x);
		int t1=find(x);//��ѯ
		int t2=find(y);
		if(t1==t2)
		{
			vector<int> path;//path���ڼ�¼·��
			path.push_back(x);
			dfs(x,y,path);
		}
		fa[t2]=t1;//�ϲ�
	}
	return 0;
}
