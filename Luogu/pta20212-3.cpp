#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef struct Node {
    int cnt;
    vector<int> ve;
} node;

int n, m;
vector<node> ans;
map<vector<int>, int> ma;

bool cmpNode(node a, node b);

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        vector<int> temp;
        for(int i = 1; i <= m; i++){
            int a;
            cin >> a;
            temp.push_back(a);
        }
        ma[temp] = ma[temp] + 1;
    }
    for(auto en: ma){
        node temp;
        temp.cnt = en.second;
        temp.ve = en.first;
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end(), cmpNode);
    int size = ans.size();
    cout << size << "\n";
    for(int i = 0; i < size; i++){
        if(i != 0) cout << "\n";
        cout << ans[i].cnt << " ";
        cout << ans[i].ve[0];
        for(int j = 1; j < m; j++){
            cout << " " << ans[i].ve[j];
        }
    }
    return 0;
}

bool cmpNode(node a, node b){
    if(a.cnt != b.cnt) return a.cnt > b.cnt;
    for(int i = 0; i < m; i++){
        if(a.ve[i] != b.ve[i]) return a.ve[i] < b.ve[i];
    }
    return true;
}