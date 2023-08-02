package com.etsuya.array;

import org.junit.Test;

/**
 * ClassName: P35
 * Package: com.etsuya.array
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/1 13:23
 * @Version: 1.0
 */
public class P35 {
	@Test
	public void test(){

	}

	public int searchInsert(int[] nums, int target) {
		//Lower bound
		int l = 0, len = nums.length, r = len - 1, mid;
		while(l < r){
			mid = l + ((r - l) >> 1);
			if(nums[mid] >= target){
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return l;
	}
}
