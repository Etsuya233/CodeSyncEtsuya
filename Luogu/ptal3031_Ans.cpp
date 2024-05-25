#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1E5 + 10;
typedef pair<int, int> PII;
typedef long long LL;
unordered_map<string, int> d; //记录每一个点的入度数
unordered_map<string, vector<string>> g; //邻接表建图

vector<string> get(string s) //把每个字符串的每一位（就是高进制数位）拆解出来
{
    vector<string> res;
    string word;
    for (auto c : s)
    {
        if (c == '.')
        {
            res.push_back(word);
            if (!d.count(word))
            {
                d[word] = 0; // 因为有的入度为0，后面也不会++，所以这边先标记存在
            }
            word.clear();
        }
        else
        {
            word += c;
        }
    }
    res.push_back(word);
    if (!d.count(word))
    {
        d[word] = 0; // 因为有的入度为0，后面也不会++，所以这边先标记存在
    }
    return res;
}

vector<string> topsort()  // 拓扑排序
{
    vector<string> res;
    priority_queue<string, vector<string>, greater<string>> heap;
    for (auto k : d)
    {
        if (!k.se)
        {
            heap.push(k.fi); // 如果入度为0，加进去。
        }
    }

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        res.push_back(t);
        for (auto k : g[t])
        {
            if (--d[k] == 0)
            {
                heap.push(k);
            }
        }
    }

    return res;
}

void solve()
{
    int n;
    scanf("%d", &n);
    string str;
    cin >> str;
    // cout << str << endl;
    auto last = get(str);
    for (int i = 1; i < n; i++)
    {
        cin >> str;
        auto cur = get(str);
        // cout << str << endl;
        if (cur.size() == last.size())
        {
            for (int j = 0; j < cur.size(); j++)
            {
                if (cur[j] != last[j])
                {
                    g[last[j]].push_back(cur[j]);
                    d[cur[j]]++;
                    break;
                }
            }
        }
        last = cur;
    }
    auto ans = topsort();
    printf("%s", ans[0].c_str());
    for (int i = 1; i < ans.size(); i++)
    {
        printf(".%s", ans[i].c_str());
    }
}

int main()
{
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}