package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/31 20:09
 * @Version: 1.0
 */
public class P31 {
	@Test
	public void test(){
		nextPermutation(new int[]{4,3,2,1});

	}

	public void nextPermutation(int[] nums) {
		int len = nums.length;
		int l = len - 2, r = len - 1, k = len - 1;

		while(l >= 0 && nums[l] >= nums[r]){
			l--;
			r--;
		}

		int temp;
		if(l >= 0){
			while(k > r){
				if(nums[k] > nums[l]) break;
				k--;
			}

			temp = nums[k];
			nums[k] = nums[l];
			nums[l] = temp;
		}


		int i = r, j = len - 1;
		while(i < j){
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++;
			j--;
		}

		for(i = 0; i < len; i++){
			System.out.print(nums[i]);
		}
	}
}
