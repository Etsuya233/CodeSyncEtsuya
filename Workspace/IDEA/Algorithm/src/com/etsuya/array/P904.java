package com.etsuya.array;

import org.junit.Test;

import java.awt.font.NumericShaper;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

/**
 * ClassName: P904
 * Package: com.etsuya.array
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/5 14:24
 * @Version: 1.0
 */
public class P904 {
	@Test
	public void test(){
		System.out.println(totalFruit(new int[]{0,1,2,2}));
	}
	public int totalFruit(int[] fruits) {
		HashMap<Integer, Integer> map = new HashMap<>();
		int i = 0, j = 0, ret = -1, len = fruits.length;
		while(j < len){
//			if(map.containsKey(fruits[j])){
//				map.put(fruits[j], map.get(fruits[j]) + 1);
//			} else {
//				map.put(fruits[j], 1);
//			}
			map.put(fruits[j], map.getOrDefault(fruits[j], 0) + 1);
			while(map.size() > 2){
				map.put(fruits[i], map.get(fruits[i]) - 1);
				if(map.get(fruits[i]) == 0) {
					map.remove(fruits[i]);
				}
				i++;
			}
			if(j - i + 1 > ret) ret = j - i + 1;
			j++;
		}
		return ret;
	}
}
