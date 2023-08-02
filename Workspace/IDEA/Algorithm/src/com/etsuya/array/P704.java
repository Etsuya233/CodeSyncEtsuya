package com.etsuya.array;

import org.junit.Test;

/**
 * ClassName: P704
 * Package: com.etsuya.array
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/1 12:59
 * @Version: 1.0
 */
public class P704 {
	@Test
	public void test(){
		System.out.println(search(new int[]{-1,0,3,5,9,12}, 9));
	}

	public int search(int[] nums, int target) {
		int l = 0, len = nums.length, r = len - 1;
		int half;
		while(l < r){
			half = (l + r) / 2;
//			if(nums[half] == target) return half;
			if(target > nums[half]){
				l = half + 1;
			} else {
				r = half;
			}
		}
		if(nums[l] == target) return l;
		return -1;
	}
}
