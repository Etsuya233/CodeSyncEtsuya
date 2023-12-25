#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int Mt(300005); //时间上限
const int Mm(1005); //蓝量上限
int d[2][Mm]; //使用滚动数组节省空间
int main()
{
    int m,s,T;
    cin >> m >> s >> T;
    int t(1); //时间
    memset(d,0xc0,sizeof d); //初始化d为极小值
    d[0][m] = 0; //当时间为0，蓝为初始值时距离为0
    int Max(0); //最大距离
    while(t<=T && m>10) //当蓝大于10时一直闪现, 有可能即使一直闪现也跑不出岛屿
    {
        m-=10;
        d[t%2][m] = 60*t;
        Max = max(Max,d[t%2][m]); //当前时间最大距离
        if(Max>=s)    break; //如果已经跑出岛屿
        ++t;
    }
    if(Max<s) //如果蓝小于10时未跑出岛屿
    {
        for(;t<=T;++t)
        {
            for(int p(0);p<20;++p)
            {
                d[t%2][p] = d[(t-1)%2][p]+17; //走路
                if(p<10)    d[t%2][p] = max(d[t%2][p],d[(t-1)%2][p+10]+60); //闪现
                if(p>=4)    d[t%2][p] = max(d[t%2][p],d[(t-1)%2][p-4]); //原地回蓝
                Max = max(Max,d[t%2][p]);
            }
            if(Max>=s)    break; //如果跑出岛屿
        }
    }
    if(Max>=s)    cout << "Yes" << endl << t;
    else        cout << "No" << endl << Max;
    return 0;
}
