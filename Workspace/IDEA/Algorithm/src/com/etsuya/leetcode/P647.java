package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P647
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/6/9 19:54
 * @Version: 1.0
 */
public class P647 {
	@Test
	public void test(){
		System.out.println(countSubstrings("qweqweqweqweweweqweasdxasdqweqweqwe"));
	}

	public int countSubstrings(String s) {
        /*
        dp[i][j]: 从i - 1开始到j - 1结束的回文子串个数
        */
		char[] str = s.toCharArray();
		int len = s.length();
		int[][] dp = new int[len + 1][len + 1];
		int ret = len;
		//Init
		for(int i = 1; i <= len; i++){
			dp[i][i] = 1;
		}
		//DP
		for(int i = 1; i <= len; i++){
			for(int j = 1; j <= len - i; j++){
				if(str[j - 1] == str[j + i - 1] && (j + 1 > j + i - 1 || dp[j + 1][j + i - 1] == 1)){
					ret ++;
					dp[j][j + i] = 1;
				}
			}
		}
		//Output
		return ret;
	}
}
