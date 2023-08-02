package com.etsuya.array;

import org.junit.Test;

/**
 * ClassName: P27
 * Package: com.etsuya.array
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/2 14:41
 * @Version: 1.0
 */
public class P27 {
	@Test
	public void test1(){

	}

	public int removeElement(int[] nums, int val) {
		int cnt = 0;
		for(int i = 0; i < nums.length; i++){
			if(nums[i] == val){
				nums[i] = nums[cnt];
				nums[cnt] = val;
				cnt++;
			}
		}
		for(int i = 0; i < nums.length - cnt; i++){
			nums[i] = nums[i + cnt];
		}
		return nums.length - cnt;
	}
}
