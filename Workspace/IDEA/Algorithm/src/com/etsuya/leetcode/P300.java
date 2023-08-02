package com.etsuya.leetcode;

import org.junit.Test;

import java.util.ArrayList;

public class P300 {
	@Test
	public void test(){
	    lengthOfLIS(new int[]{10,9,2,5,3,7,101,18});
	}

	public int lengthOfLIS(int[] nums) {
		ArrayList<Integer> list = new ArrayList<>();
		int size = 1;
		list.add(nums[0]);
		for(int i = 1; i < nums.length; i++){
			int loc = lower_bound(list, nums[i]);
			if(loc == size){
				size++;
				list.add(nums[i]);
			} else {
				list.set(loc, nums[i]);
			}
		}
		return size;
	}

	public int lower_bound(ArrayList<Integer> list, int key){
		int l = 0, r = list.size();
		int mid;
		while(l < r){
			mid = (l + r) / 2;
			if(list.get(mid) < key){
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		return l;
	}
}
