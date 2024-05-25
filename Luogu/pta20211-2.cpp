#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, k, m;
    cin >> n >> k >> m;
    int ans = n - k * m;
    cout << max(0, ans);
    return 0;
}