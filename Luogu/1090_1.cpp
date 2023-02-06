#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> > my;
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >>  temp;
        my.push(temp);
    }
    for(int i = 1; i <= n - 1; i++){
        int sum = my.top();
        my.pop();
        sum += my.top();
        my.pop();
        my.push(sum);
        ans += sum;
    }
    cout << ans;
}