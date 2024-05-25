#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

int n;
vector<int> arr[100005];
// vector<pair<int, int>> ll[18000];
// vector<pair<int, int>> rr[18000];
vector<pair<int, int>> kankei;
deque<int> res;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        char str[100];
        cin >> str;
        int len = strlen(str);
        int pos = len;
        pos--;
        for(; pos >= -1; pos--){
            if(pos == -1 || str[pos] == '.'){
                int num = 0;
                for(int j = pos + 1; j < len && str[j] != '.'; j++){
                    num = num * 26 + str[j] - 'a';
                }
                arr[i].push_back(num);
                cout << num << "\n";
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(arr[i - 1].size() != arr[i].size()){
            continue;
        }
        int j = arr[i - 1].size();
        while(arr[i - 1][j] == arr[i][j]) j--;
        auto p = make_pair(arr[i - 1][j], arr[i][j]);
        cout << "\n";
        kankei.push_back(p);
    }
    //现在做比较关系！

}


// for(auto p: kankei){
//     int a = p.first;
//     int b = p.second;
//     while(a > 0){
//         cout << (char)(a % 26 + 'a');
//         a /= 26;
//     }
//     cout << " ";
//     while(b > 0){
//         cout << (char)(b % 26 + 'a');
//         b /= 26;
//     }
//     cout << "\n";
// }