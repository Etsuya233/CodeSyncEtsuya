package com.etsuya.array;

import org.junit.Test;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

/**
 * ClassName: P76
 * Package: com.etsuya.array
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/5 15:04
 * @Version: 1.0
 */
public class P76 {
	@Test
	public void test(){
		String s = "ADOBECODEBANC", t = "ABC";
		System.out.println(minWindow(s, t));
	}

	public String minWindow(String s, String t) {
		int i = 0, j = 0, lens = s.length(), lent = t.length(), minLen = 0x7fffffff;
		String ret = "";
		HashMap<Integer, Integer> map = new HashMap<>();
		int[][] con = dealWithT(t);
		while(j < lens){
			map.put((int)s.charAt(j), map.getOrDefault((int)s.charAt(j), 0) + 1);
			while(isMatch(con, map)){
				if(j - i + 1 < minLen){
					minLen = j - i + 1;
					ret = s.substring(i, j + 1);
				}
				map.put((int)s.charAt(i), map.get((int)s.charAt(i)) - 1);
				i++;
			}
			j++;
		}
		return ret;
	}

	public int[][] dealWithT(String t){
		int len = t.length();
		HashMap<Integer, Integer> map = new HashMap<>();
		for(int i = 0; i < len; i++){
			map.put((int)t.charAt(i), map.getOrDefault((int)t.charAt(i), 0) + 1);
		}
		Set<Map.Entry<Integer, Integer>> entries = map.entrySet();
		Iterator<Map.Entry<Integer, Integer>> iterator = entries.iterator();
		int[][] ret = new int[map.size()][2];
		int cnt = 0;
		Map.Entry<Integer, Integer> entry;
		while(iterator.hasNext()){
			entry = iterator.next();
			ret[cnt][0] = entry.getKey();
			ret[cnt][1] = entry.getValue();
			cnt++;
		}
		return ret;
	}

	public boolean isMatch(int[][] con, HashMap<Integer, Integer> map){
		boolean ret = false;
		for(int k = 0; k < con.length; k++){
			if(map.getOrDefault(con[k][0], 0) < con[k][1]){
				break;
			}
			if(k == con.length - 1){
				ret = true;
			}
		}
		return ret;
	}
}
