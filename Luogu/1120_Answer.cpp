#include<bits/stdc++.h>
using namespace std;

int totall = 0;

inline int read(){
    int x=0; bool f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=0;
    for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    if(f) return x;
    return 0-x;
}
int n,m,a[66],nexta[66],cnt,sum,len;
bool used[66],ok; //used���鼴�Ż�5��vis���飬��¼ÿ��ľ���Ƿ��ù���ok��¼�Ƿ����ҵ��𰸡�
bool cmp(int a,int b){return a>b;}
void dfs(int k,int last,int rest){ //kΪ����ƴ��ľ���ı�ţ�lastΪ����ƴ��ľ����ǰһ�ڱ�ţ�restΪ��ľ����δƴ�ĳ���
    int i;
    totall++;
    if(!rest){ //δƴ�ĳ���Ϊ0��˵�����ԭʼ����ƴ���ˣ�׼��ƴ��һ��
        if(k==m){ok=1; return;} //�Ż�6��ȫ��ƴ�겢����Ҫ���ҵ��𰸣�ֱ�ӷ���

        for(i=1;i<=cnt;i++) //��һ����û�õ����ľ����ͷ���ɡ�����Ҫ��ȫ��ƴ�ӳɹ���ÿ��ľ����������
            if(!used[i]) break;
        used[i]=1;
        dfs(k+1,i,len-a[i]);
        used[i]=0;
        if(ok) return; //�Ż�6���ҵ��𰸾��˳�
    }
    //�Ż�4�������ҵ�һ�� ľ�����Ȳ�����δƴ����rest ��λ��
    int l=last+1, r=cnt, mid;
    while(l<r){
        mid=(l+r)>>1;
        if(a[mid]<=rest) r=mid;
        else l=mid+1;
    }
    for(i=l;i<=cnt;i++){
        if(!used[i]){ //�Ż�5���ж�ľ���Ƿ��ù�
            used[i]=1;
            dfs(k,i,rest-a[i]);
            used[i]=0;
            if(ok) return; //�Ż�6���ҵ��𰸾��˳�

            if(rest==a[i] || rest==len) return; //�Ż�7
            i=nexta[i]; //�Ż�3
            if(i==cnt) return;
        }
    }
    //�������˵����ʱ��ƴ���ɵ�ǰ���ԭʼľ���ˣ�����ʧ����Ϣ���޸�֮ǰƴ��ľ��
}
int main(){
    n=read();
    int d;
    for(int i=1;i<=n;i++){
        d=read();
        if(d>50) continue;
        a[++cnt]=d;
        sum+=d;
    }
    sort(a+1,a+cnt+1,cmp); //�Ż�1��ľ�������ȴӴ�С����
    //�Ż�3��Ԥ����next����
    nexta[cnt]=cnt;
    for(int i=cnt-1;i>0;i--){
        if(a[i]==a[i+1]) nexta[i]=nexta[i+1];
        else nexta[i]=i;
    }
    for(len=a[1];len<=sum/2;len++){ //ö��ԭʼ����
        if(sum%len!=0) continue; //�������ƴ�������� ������
        m=sum/len; //�Ż�6�е��Ǹ�����
        ok=0;
        used[1]=1;
        dfs(1,1,len-a[1]);
        used[1]=0;
        if(ok){printf("%d\n %d",len,totall); return 0;} //�Ż�6������𰸣���
    }
    printf("%d\n %d",sum,totall); return 0;
}
