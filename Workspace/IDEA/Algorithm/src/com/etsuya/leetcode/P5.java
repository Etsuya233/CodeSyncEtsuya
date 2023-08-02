package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P5
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/11 17:16
 * @Version: 1.0
 */
public class P5 {
	@Test
	public void test(){
		System.out.println(longestPalindrome("cbbd"));
	}

	@Test
	public void test1(){
		int[][] dp = new int[5][5];
		System.out.println(dp[1][1]);
	}

	public String longestPalindrome(String s) {
		int length = s.length(), max = 0, loc = 0;
		int[][] dp = new int[length][length];
		for(int i = 0; i < length; i++){
			dp[i][i] = 1;
			if(i < length - 1){
				if(s.charAt(i) == s.charAt(i + 1)) {
					dp[i][i + 1] = 1;
					if (max != 1) {
						loc = i;
						max = 1;
					}
				}
				else dp[i][i + 1] = 0;
			}
		}
		for(int i = 2; i < length; i++){
			for(int j = 0; j < length - i; j++){
				if(dp[j + 1][j + i - 1] == 1 && s.charAt(j) == s.charAt(j + i)){
					dp[j][j + i] = 1;
					if(i > max){
						max = i;
						loc = j;
					}
				} else {
					dp[j][j + i] = 0;
				}
			}
		}
		return s.substring(loc, loc + max + 1);
	}
}
