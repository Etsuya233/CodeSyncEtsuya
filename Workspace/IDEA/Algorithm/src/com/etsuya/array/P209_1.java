package com.etsuya.array;

import org.junit.Test;

/**
 * ClassName: P209_1
 * Package: com.etsuya.array
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/5 14:01
 * @Version: 1.0
 */
public class P209_1 {
	@Test
	public void test(){
		System.out.println(minSubArrayLen(5, new int[]{2, 3, 1, 2, 4, 3}));
	}

	public int minSubArrayLen(int target, int[] nums) {
		int ret = 0x7fffffff, l = 0, r = 0, len = nums.length, sum = 0;
		while(r < len){
			sum += nums[r];
			while(sum >= target){
				if(r - l + 1 < ret) ret = r - l + 1;
				sum -= nums[l];
				l++;
			}
			r++;
		}
		return ret == 0x7fffffff? 0: ret;
	}
}
