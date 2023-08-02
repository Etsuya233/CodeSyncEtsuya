package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P123
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/5/28 15:47
 * @Version: 1.0
 */
public class P123 {
	@Test
	public void test(){
		System.out.println(maxProfit(new int[]{1,2,3,4,5}));
	}

	public int maxProfit(int[] prices) {
		int len = prices.length;
		int[][] dp = new int[2][5];
		dp[0][1] = -prices[0];
		dp[0][3] = -prices[0];
		for(int i = 1; i < len; i++){
			dp[i % 2][1] = Math.max(dp[(i - 1) % 2][1], -prices[i]); //第一次持有股票
			dp[i % 2][2] = Math.max(dp[(i - 1) % 2][2], dp[(i - 1) % 2][1] + prices[i]); //第一次不持有
			dp[i % 2][3] = Math.max(dp[(i - 1) % 2][3], dp[(i - 1) % 2][2] - prices[i]); //第二次持有
			dp[i % 2][4] = Math.max(dp[(i - 1) % 2][4], dp[(i - 1) % 2][3] + prices[i]); //第二次不持有
		}
		System.out.println("complete");
		return Math.max(dp[(len - 1) % 2][4], dp[(len - 1) % 2][2]);
	}

	public int maxProfit2(int[] prices) {
		int len = prices.length;
		int[][] dp = new int[len][6];
		dp[0][1] = -prices[0];
		for(int i = 1; i < len; i++){
			dp[i][0] = Math.max(dp[i - 1][0], -prices[i]);
			dp[i][5] = Math.max(dp[i - 1][5], dp[i - 1][0] + prices[i]);
			dp[i][1] = dp[i - 1][1]; //没卖保留之前的
			dp[i][2] = prices[i] + dp[i - 1][0]; //卖了可以进行第二次
			if(dp[i][2] > 0){
				dp[i ][3] = Math.max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
				dp[i ][4] = Math.max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
			}
		}
		System.out.println("Complete");
		return Math.max(dp[len - 1][5], dp[len - 1][4]);
	}
}
