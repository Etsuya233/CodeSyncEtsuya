#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <random>
#include <functional>
#include <time.h>
#include <cstring>
#include <bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
vector<int> linear_sieve(int n){
    vector<int> primes, v(n + 1);
    for (int i = 2; i <= n; i++){
        if (v[i] == 0)
            primes.push_back(i);
        for (auto e : primes){
            if (i * e > n)
                break;
            v[i * e] = 1;
            if (i % e == 0)
                break;
        }
    }
    return primes;
}
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    int M = 1e7, n;
    cin >> n;
    vector<int> v(n), se(M + 1);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        se[v[i]] = 1;
    }
    map<int, vector<int>> table;
    auto primes = linear_sieve(M);
    for (auto e : primes){
        for (int i = e; i <= M; i += e){
            if (se[i])
                table[i].push_back(e); //table[i]装的是i的质因子
        }
    }
    vector<int> cnt(M + 1);
    for (auto e : v){
        for (auto f : table[e]){
            cnt[f]++; //某个质因子被使用的个数
        }
    }
    int ans = 0;
    for (auto e : v){
        bool yes = true;
        for (auto f : table[e]){
            yes &= cnt[f] == 1;
        }
        if(yes) cout << e << "\n";
        ans += yes;
    }
    cout << ans;
    return 0;
}