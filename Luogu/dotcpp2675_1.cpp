#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int n, m, lim, ans = 0;
vector<vector<vector<int>>> maxx;
vector<vector<vector<int>>> minx;
vector<vector<int>> arr;

int main(){
    cin >> n >> m;
    maxx = vector<vector<vector<int>>>(m + 2, vector<vector<int>>(n + 2, vector<int>(n + 2, 0)));
    minx = vector<vector<vector<int>>>(m + 2, vector<vector<int>>(n + 2, vector<int>(n + 2, 0)));
    arr = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    cin >> lim;
    //init
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            maxx[i][j][j] = minx[i][j][j] = arr[j][i];
            for(int k = j + 1; k <= n; k++){
                maxx[i][j][k] = max(maxx[i][j][k - 1], arr[k][i]);
                minx[i][j][k] = min(minx[i][j][k - 1], arr[k][i]);
            }
        }
    }
    //dp
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            deque<int> minqu, maxqu;
            int border = 1;
            minqu.push_back(minx[1][i][j]);
            maxqu.push_back(maxx[1][i][j]);
            if(maxqu.front() - minqu.front() > lim) border++;
            ans = max(ans, (j - i + 1) * (1 - border + 1));
            for(int k = 2; k <= m; k++){
                //maintain queue
                int minn = minx[k][i][j];
                int maxn = maxx[k][i][j];
                if(!minqu.empty() && minn >= minqu.front()){
                    while(minqu.back() > minn) minqu.pop_back();
                    minqu.push_back(minn);
                }
                if(minqu.empty()){
                    minqu.push_back(minn);
                } else if(!minqu.empty() && minn < minqu.front()){
                    minqu.clear();
                    minqu.push_back(minn);
                }
                if(!maxqu.empty() && maxn <= maxqu.front()){
                    while(maxqu.back() < maxn) maxqu.pop_back();
                    maxqu.push_back(maxn);
                }
                if(maxqu.empty()){
                    maxqu.push_back(maxn);
                } else if(!maxqu.empty() && maxn > maxqu.front()){
                    maxqu.clear();
                    maxqu.push_back(maxn);
                }
                //calc border
                for(int q = border; q <= k; q++){
                    if(!minqu.empty() && !maxqu.empty() && maxqu.front() - minqu.front() > lim){
                        if(!maxqu.empty() && maxx[q][i][j] == maxqu.front()){
                            border = q + 1;
                            maxqu.pop_front();
                        }
                        if(!minqu.empty() && minx[q][i][j] == minqu.front()){
                            border = q + 1;
                            minqu.pop_front();
                        }
                    } else break;
                }
                // cout << i << " " << j << " " << border << " " << k << " " << (j - i + 1) * (k - border + 1) << "\n";
                //ans
                ans = max(ans, (j - i + 1) * (k - border + 1));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}