#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int Mt(300005); //ʱ������
const int Mm(1005); //��������
int d[2][Mm]; //ʹ�ù��������ʡ�ռ�
int main()
{
    int m,s,T;
    cin >> m >> s >> T;
    int t(1); //ʱ��
    memset(d,0xc0,sizeof d); //��ʼ��dΪ��Сֵ
    d[0][m] = 0; //��ʱ��Ϊ0����Ϊ��ʼֵʱ����Ϊ0
    int Max(0); //������
    while(t<=T && m>10) //��������10ʱһֱ����, �п��ܼ�ʹһֱ����Ҳ�ܲ�������
    {
        m-=10;
        d[t%2][m] = 60*t;
        Max = max(Max,d[t%2][m]); //��ǰʱ��������
        if(Max>=s)    break; //����Ѿ��ܳ�����
        ++t;
    }
    if(Max<s) //�����С��10ʱδ�ܳ�����
    {
        for(;t<=T;++t)
        {
            for(int p(0);p<20;++p)
            {
                d[t%2][p] = d[(t-1)%2][p]+17; //��·
                if(p<10)    d[t%2][p] = max(d[t%2][p],d[(t-1)%2][p+10]+60); //����
                if(p>=4)    d[t%2][p] = max(d[t%2][p],d[(t-1)%2][p-4]); //ԭ�ػ���
                Max = max(Max,d[t%2][p]);
            }
            if(Max>=s)    break; //����ܳ�����
        }
    }
    if(Max>=s)    cout << "Yes" << endl << t;
    else        cout << "No" << endl << Max;
    return 0;
}
