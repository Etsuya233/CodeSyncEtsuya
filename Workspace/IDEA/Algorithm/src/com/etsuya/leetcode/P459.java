package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P459
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/13 17:08
 * @Version: 1.0
 */
public class P459 {
	int len;
	int[] next;

	@Test
	public void test(){
	    String s = "abac";
		repeatedSubstringPattern(s);
		System.out.println("qw");
	}

	public boolean repeatedSubstringPattern(String s) {
		len = s.length();
		getNext(s);
		if(next[len - 1] != -1 && (len % (len - next[len - 1] + 1) == 0)){
			return true;
		}
		System.out.println((len % (len - next[len - 1] - 1)));
		return false;
	}

	void getNext(String s){
		next = new int[len + 1];
		int j = 0, k = -1;
		next[0] = -1;
		while(j < len - 1){
			if(k == -1 || s.charAt(j) == s.charAt(k)){
				++j;
				++k;
				next[j] = k;
			} else {
				k = next[k];
			}
		}
	}
}
