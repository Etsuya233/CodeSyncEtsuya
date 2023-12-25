#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 100005;
bool dp[MAX_N]; // dp[i] 表示是否可以找到积分差为 i 的组合

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end()); // 对积分进行排序

    memset(dp, false, sizeof(dp));
    dp[0] = true;

    int max_score = 0;

    for (int i = 0; i < N; i++) {
        bool newDp[MAX_N];
        memcpy(newDp, dp, sizeof(dp));

        for (int j = 0; j <= K; j++) {
            if (dp[j]) {
                newDp[abs(j - A[i])] = true;
            }
        }

        memcpy(dp, newDp, sizeof(dp));
        max_score = max(max_score, A[i]);
    }

    cout << max_score + 1 << endl;

    return 0;
}

