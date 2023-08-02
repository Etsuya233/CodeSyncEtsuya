package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P115
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/6/6 19:09
 * @Version: 1.0
 */
public class P115 {
	@Test
	public void test(){
	    numDistinct("babgbag", "bag");
	}

	public int numDistinct(String s, String t) {
		int lens = s.length(), lent = t.length();
		char[] strs = s.toCharArray();
		char[] strt = t.toCharArray();
		int[] dp = new int[lent + 1];
		dp[0] = 1;
		int mae = 1, temp = 1;
		for(int i = 0; i < lens; i++){
			mae = 1;
			for(int j = 1; j <= lent && j <= i + 1; j++){
				temp = dp[j];
				if(strs[i] == strt[j - 1]){
					dp[j] = dp[j] + mae;
				}
				mae = temp;
			}
		}
		return dp[lent];
	}
}
