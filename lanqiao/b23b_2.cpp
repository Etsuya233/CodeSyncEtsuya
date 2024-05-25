#include <bits/stdc++.h>
using namespace std;
const int N=5e6+100;
bool is_prime[N+10];
int vec[N+10];
int indvec=0;
int ans=0;
vector<long long> arr;
void Erato_long_name()
{
    for(int i=2;i<=sqrt(N);i++){
        if(!is_prime[i]){
            for(int j=i*i;j<=N;j+=i){
                is_prime[j]=1;
            }
        }
    }
}
int main()
{
    Erato_long_name();
    for(int i=2;i<=N;i++){
        if(!is_prime[i]){
            vec[indvec++]=i;
        }
    }
    for(int i=0;i<indvec;i++){//枚举p
        if(1ll*vec[i]*vec[i]*vec[i]*vec[i]>23333333333333){//当p^4都爆时，p^2*q^2肯定要爆
            break;
        }
        for(int j=i+1;j<indvec;j++){//枚举q
            if(1ll*vec[i]*vec[i]*vec[j]*vec[j]<2333){//太小了
                continue;//往后枚举
            }
            else if(1ll*vec[i]*vec[i]*vec[j]*vec[j]>23333333333333){//爆炸
                break;//剪枝
            }
            ans++;
            arr.push_back(1ll*vec[i]*vec[i]*vec[j]*vec[j]);
        }
    }
    sort(arr.begin(), arr.end());
    for(long long  a: arr){
        cout << a << "\n";
    }
    cout<<ans<<endl;
    return 0;
}