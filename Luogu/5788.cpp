#include <iostream>
#include <stack>
using namespace std;

int n;
int arr[3000005] = {0};
int ret[3000005] = {0};

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    stack<int> my;
    my.push(1);
    for(int i = 2; i <= n; i++){
        while(!my.empty() && arr[my.top()] < arr[i]){
            ret[my.top()] = i;
            my.pop();
        }
        my.push(i);
    }
    for(int i = 1; i <= n; i++){
        cout << ret[i] << " ";
    }
}