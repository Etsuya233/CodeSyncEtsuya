package com.etsuya.leetcode;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * ClassName: P139
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/5/26 16:53
 * @Version: 1.0
 */
public class P139 {
	@Test
	public void test(){
		ArrayList<String> al = new ArrayList<>();
		al.add("leet");
		al.add("code");
		wordBreak("leetcode", al);
	}

	public boolean wordBreak(String s, List<String> wordDict) {
		int len = s.length();
		boolean[] dp = new boolean[len + 1];
		//initializse
		dp[0] = true;
		for(int i = 1; i <= len; i++){//长度
			for(int j = 0; j < i; j++){//字串分割
				if(dp[j] && wordDict.contains(s.substring(j, i))){
					dp[i] = true;
				}
			}
		}
		for(boolean num: dp){
			System.out.print(num + " ");
		}
		return dp[len];
	}
}
