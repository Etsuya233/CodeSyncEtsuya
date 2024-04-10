#include <iostream>
#include <vector>
#include <set>
#include <ctime>
using namespace std;

int n;
int arr[100005] = {0};
set<int> weight;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    weight.insert(arr[1]);
    weight.insert(arr[2]);
    weight.insert(arr[1] + arr[2]);
    weight.insert(abs(arr[1] - arr[2]));
    vector<int> now;
    for(int i = 3; i <= n; i++){
        auto ts = clock();
        // cout << weight.size() << "\n";
        for(int num: weight){
            now.push_back(arr[i]);
            now.push_back(arr[i] + num);
            now.push_back(abs(arr[i] - num));
        }
        auto te = clock();
        cout << (te - ts) << "\n";
        ts = clock();
        for(int num: now){
            weight.insert(num);
        }
        now.clear();
        te = clock();
        cout << "\n" << (te - ts) << "\n";
    }
    cout << weight.size() << "\n";
}