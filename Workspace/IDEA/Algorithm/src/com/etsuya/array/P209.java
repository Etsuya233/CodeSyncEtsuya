package com.etsuya.array;

import org.junit.Test;

/**
 * ClassName: P209
 * Package: com.etsuya.array
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/2 15:44
 * @Version: 1.0
 */
public class P209 {
	@Test
	public void test(){
		System.out.println(minSubArrayLen(11, new int[]{1,2,3,4,5}));
	}

	public int minSubArrayLen(int target, int[] nums) {
		int[] sum = new int[nums.length + 1];
		sum[0] = 0;
		sum[1] = nums[0];
		for(int i = 1; i < nums.length; i++){
			sum[i + 1] = sum[i] + nums[i];
		}
		int l = 1, r = nums.length + 1, mid = 0, found = 0;
		while(l < r){
			mid = ((l + r) >> 1);
			found = 0;
			for(int i = mid; i < nums.length + 1; i++){
				if(sum[i] - sum[i - mid] >= target){
					found = 1;
					break;
				}
			}
			if(found > 0){
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		if(l != nums.length)
			return l;
		else if(sum[l - 1] >= target){
			return l;
		}
		return 0;
	}
}
