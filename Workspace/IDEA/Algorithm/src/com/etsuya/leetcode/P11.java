package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P11
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/23 18:25
 * @Version: 1.0
 */
public class P11 {
	@Test
	public void test(){
		int[] arr = new int[]{1,8,6,2,5,4,8,3,7};
		int[] arr1 = new int[]{120,120,1,1,1,1,1,1,1,1,1,1};
		System.out.println(maxArea(arr1));
	}
	public int maxArea(int[] height) {
		int len = height.length;
		int l = 0, r = len - 1;
		int max = 0, temp;
		while(l < r){
			if(height[l] < height[r]){
				temp = (r - l) * height[l];
				l++;
			}
			else {
				temp = (r - l) * height[r];
				r--;
			}
			if(max < temp) max = temp;
		}
		return max;
	}
}