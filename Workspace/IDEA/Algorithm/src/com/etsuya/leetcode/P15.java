package com.etsuya.leetcode;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/**
 * ClassName: P15
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/24 21:42
 * @Version: 1.0
 */
public class P15 {
	@Test
	public void test(){
		List<List<Integer>> lists = threeSumOptimized(new int[]{-1,2,1,-4});
		int target = 1;

		for(List list : lists){
			System.out.println(list);
		}
	}
	public List<List<Integer>> threeSum(int[] nums) {
		int len = nums.length, cnt = 0;
		Arrays.sort(nums);
		List<List<Integer>> ret = new ArrayList<>();
		if(len < 3) return ret;
		HashMap<Integer, Integer> my = new HashMap<>();
		int i = 0, j;
		while(i < len){
			if(nums[i] >= 0) break;
			if(my.containsKey(nums[i])){
				my.replace(nums[i], my.get(nums[i]) + 1);
			} else {
				my.put(nums[i], 1);
			}
			i++;
		}
		while(i <= len){
			if(i != len && my.containsKey(nums[i])){
				my.replace(nums[i], my.get(nums[i]) + 1);
			} else {
				int lastj = 100000000;
				i--;
				for(j = i - 1; j >= 0; j--){
					if(nums[j] == lastj) continue;
					if(- nums[i] - nums[j] < nums[j]){
						if(my.containsKey(- nums[i] - nums[j])){
							ret.add(new ArrayList<>());
							ret.get(cnt).add(- nums[i] - nums[j]);
							ret.get(cnt).add(nums[j]);
							ret.get(cnt).add(nums[i]);
							cnt++;
						}
					} else if(- nums[i] - nums[j] == nums[j] && nums[j] != nums[i]){
						if(my.get(nums[j]) >= 2){
							ret.add(new ArrayList<>());
							ret.get(cnt).add(- nums[i] - nums[j]);
							ret.get(cnt).add(nums[j]);
							ret.get(cnt).add(nums[i]);
							cnt++;
						}
					} else if(- nums[i] - nums[j] == nums[j] && nums[j] == nums[i]){
						if(my.get(nums[j]) >= 3 && nums[i] == 0){
							ret.add(new ArrayList<>());
							ret.get(cnt).add(0);
							ret.get(cnt).add(0);
							ret.get(cnt).add(0);
							cnt++;
						}
					} else {
						break;
					}
					lastj = nums[j];
				}
				i++;
				if(i != len) my.put(nums[i], 1);
			}
			i++;
		}
		return ret;
	}

	public List<List<Integer>> threeSumOptimized(int[] nums){
		int len = nums.length, cnt = 0;
		List<List<Integer>> ret = new ArrayList<>();
		if(len < 3) return ret;
		Arrays.sort(nums);
		for(int i = 0; i < len - 2; i++){
			if(i > 0 && nums[i] == nums[i - 1]){
				continue;
			}
			int l = i + 1, r = len - 1;
			while(l < r){
				if(nums[l] + nums[r] + nums[i] > 0){
					r--;
				} else if (nums[l] + nums[r] + nums[i] < 0) {
					l++;
				} else {
					ret.add(new ArrayList<>());
					ret.get(cnt).add(nums[l]);
					ret.get(cnt).add(nums[r]);
					ret.get(cnt).add(-nums[l]-nums[r]);
					cnt++;
					//关于为什么while放在l++，r--前
					//因为怕你l++，r--后的对应元素一样
					while(l < r && nums[l] == nums[l + 1]) l++;
					while(l < r && nums[r] == nums[r - 1]) r--;
					l++;
					r--;
				}
			}
		}
		return ret;
	}
	public int threeSumClosest(int[] nums, int target) {
		int len = nums.length;
		Arrays.sort(nums);
		boolean found = false;
		int nowTarget = target;
		for(int minus = 0; !found; minus ++){
			for(int p = 0; p < 2; p++){
				if(p == 0){
					nowTarget = target + minus;
				} else {
					nowTarget = target - minus;
				}
				for(int i = 0; i < len - 2; i++){
					if(i > 0 && nums[i] == nums[i - 1]){
						continue;
					}
					int l = i + 1, r = len - 1;
					while(l < r){
						if(nums[l] + nums[r] + nums[i] > nowTarget){
							r--;
						} else if (nums[l] + nums[r] + nums[i] < nowTarget) {
							l++;
						} else {
							found = true;
							break;
//					//关于为什么while放在l++，r--前
//					//因为怕你l++，r--后的对应元素一样
//					while(l < r && nums[l] == nums[l + 1]) l++;
//					while(l < r && nums[r] == nums[r - 1]) r--;
//					l++;
//					r--;
						}
					}
				}
			}
		}
		return nowTarget;
	}
}
