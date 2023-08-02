package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P718
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/6/2 18:07
 * @Version: 1.0
 */
public class P718 {
	@Test
	public void test(){
		System.out.println(findLength2(new int[]{1, 0, 0, 0, 1}, new int[]{1, 0, 0, 1, 1}));
	}

	public int findLength(int[] nums1, int[] nums2) {
		int lena = nums1.length, lenb = nums2.length;
		int[][] dp = new int[lena][lenb];
		int ret = 0;
		if(nums1[0] == nums2[0]) ret = 1;
		for(int i = 0; i < lena; i++){
			if(nums1[i] == nums2[0]) dp[i][0] = 1;
		}
		for(int i = 0; i < lenb; i++){
			if(nums1[0] == nums2[i]) dp[0][i] = 1;
		}
		for(int i = 1; i < lena; i++){
			for(int j = 1; j < lenb; j++){
				if(nums1[i] == nums2[j]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
					ret = Math.max(dp[i][j], ret);
				} else dp[i][j] = 0;
			}
		}
		return ret;
	}

	public int findLength2(int[] nums1, int[] nums2) {
		int lena = nums1.length, lenb = nums2.length;
		int[] dp2 = new int[lenb];
		int ret = 0;
		for(int i = 0; i < lena; i++){
			for(int j = lenb - 1; j >= 1; j--){
				if(nums1[i] == nums2[j]){
					dp2[j] = dp2[j - 1] + 1;
					ret = Math.max(dp2[j], ret);
				} else dp2[j] = 0;
			}
			if(nums1[i] == nums2[0]) dp2[0] = 1;
			else dp2[0] = 0;
			ret = Math.max(dp2[0], ret);
			for(int a: dp2){
				System.out.print(a + " ");
			}
			System.out.println();
		}
		return ret;
	}
}
