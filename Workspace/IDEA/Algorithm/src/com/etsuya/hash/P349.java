package com.etsuya.hash;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * ClassName: P349
 * Package: com.etsuya.hash
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/9 12:45
 * @Version: 1.0
 */
public class P349 {
	public int[] intersection(int[] nums1, int[] nums2) {
		HashMap<Integer, Integer> map = new HashMap<>();
		ArrayList<Integer> list = new ArrayList<>();
		int cnt = 0;
		for(int i = 0; i < nums1.length; i++){
			map.put(nums1[i], 1);
		}
		for(int i = 0; i < nums2.length; i++){
			if(map.containsKey(nums2[i])){
				list.add(nums2[i]);
				cnt++;
			}
		}
		int[] ret = new int[cnt];
		cnt = 0;
		for(Integer i: list){
			ret[cnt++] = i;
		}
		return ret;
	}
}
