package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P188
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/5/29 10:53
 * @Version: 1.0
 */
public class P188 {
	@Test
	public void test(){
		maxProfit(2, new int[]{3,2,6,5,0,3});
	}

	public int maxProfit(int k, int[] prices) {
		int len = prices.length; //天数
		int maxTimes = k * 2 + 1;
		int[][] dp = new int[2][maxTimes];
		//无操作
		//dp[i][0] = 0;
		//第一次持有
		//dp[i][1] = dp[i - 1][1], dp[i - 1][0] - prices[i]
		//第一次不持有
		//dp[i][2] = dp[i - 1][2], dp[i - 1][1] + prices[i]
		//第二次持有
		//dp[i][3] = dp[i - 1][3], dp[i - 1][2] - prices[i]
		//第二次不持有
		//dp[i][4] = dp[i - 1][4], dp[i - 1][3] + prices[i]

		//Initialize
		for(int i = 1; i < maxTimes; i += 2){
			dp[0][i] = -prices[0];
		}
		//DP
		for(int i = 1; i < len; i++){
			for(int j = 1; j <= k; j++){
				dp[i % 2][2 * j - 1] = Math.max(dp[(i - 1) % 2][2 * j - 1], dp[(i - 1) % 2][2 * j - 2] - prices[i]);
				dp[i % 2][2 * j] = Math.max(dp[(i - 1) % 2][2 * j], dp[(i - 1) % 2][2 * j - 1] + prices[i]);
			}
		}
		//Output
		int ret = 0;
		for(int i = 0; i < maxTimes; i++){
			ret = Math.max(dp[(len - 1) % 2][i], ret);
		}
		return ret;
	}
}
