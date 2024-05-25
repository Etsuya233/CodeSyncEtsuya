#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int n;
int hashtb[20000] = {0}; //realword -> reali
int wor[20000]; //reali -> realword
vector<int> arr[100005];
vector<int> gra[20000];
int vis[20000] = {0};
int in[20000] = {0};
int cnt = 0;
vector<int> ans;

bool cmpHashed(int a, int b);

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
                    num = num * 27 + str[j] - 'a' + 1;
                }
                //哈希压缩
                if(hashtb[num] == 0){
                    wor[++cnt] = num;
                    hashtb[num] = cnt;
                    arr[i].push_back(cnt);
                } else {
                    arr[i].push_back(hashtb[num]);
                }
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(arr[i - 1].size() != arr[i].size()){
            continue;
        }
        int j = arr[i - 1].size();
        while(arr[i - 1][j] == arr[i][j]) j--;
        gra[arr[i - 1][j]].push_back(arr[i][j]);
        in[arr[i][j]]++;
    }
    vector<int> veh; //now
    vector<int> ve;
    while(true){
        //find in = 0
        for(int i = 1; i <= cnt; i++){
            if(in[i] == 0){
                if(vis[i] == 0){
                    veh.push_back(i);
                    ve.push_back(wor[i]);
                    vis[i] = 1;
                }
            }
        }
        if(veh.empty()) break;
        //sort ve
        sort(ve.begin(), ve.end(), cmpHashed);
        //ans
        for(int nodeans: ve){
            ans.push_back(nodeans);
        }
        //next
        for(int node: veh){
            for(int mynode: gra[node]){
                in[mynode]--;
            }
        }
        ve.clear();
        veh.clear();
    }
    for(int i = 0; i < cnt; i++){
        int len = 0;
        char str[5];
        int now = ans[i];
        while(now > 0){
            str[len++] = now % 27 + 'a' - 1;
            now /= 27;
        }
        if(i != 0) cout << ".";
        for(int j = len - 1; j >= 0; j--) cout << str[j];
        if(len == 0) cout << 'a';
    }
    cout << "\n";
    return 0;
}

bool cmpHashed(int a, int b){
    int aa = a, bb  = b;
    int lena = 0, lenb = 0;
    int aaa[4] = {0}, bbb[4] = {0};
    while(aa > 0){
        aaa[lena++] = aa % 27;
        aa /= 27;
    }
    while(bb > 0){
        bbb[lenb++] = bb % 27;
        bb /= 27;
    }
    for(int i = 1; i <= 3; i++){
        int nowa = lena - i;
        int nowb = lenb - i;
        if(nowa < 0 || nowb < 0){
            return nowa < nowb;
        }
        if(aaa[nowa] != bbb[nowb]) return aaa[nowa] < bbb[nowb];
    }
    return true;
}