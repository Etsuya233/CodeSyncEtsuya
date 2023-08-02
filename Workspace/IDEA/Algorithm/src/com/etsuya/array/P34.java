package com.etsuya.array;

import org.junit.Test;

/**
 * ClassName: P34
 * Package: com.etsuya.array
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/1 13:38
 * @Version: 1.0
 */
public class P34 {
	@Test
	public void test(){


	}

	public int[] searchRange(int[] nums, int target) {
		int l = 0, len = nums.length, r = len, mid;
		int[] ret = new int[]{-1, -1};
		if(len == 0) return ret;
		//Lower bound
		while(l < r){
			mid = l + ((r - l) >> 1);
			if(nums[mid] >= target){
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		if(l >= len || nums[l] != target) return ret;
		//Upper bound
		ret[0] = l;
		l = 0;
		r = len;
		while(l < r){
			mid = l + ((r - l) >> 1);
			if(nums[mid] > target){
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		ret[1] = l - 1;
		return ret;
	}
}
