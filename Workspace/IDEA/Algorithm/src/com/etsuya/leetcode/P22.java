package com.etsuya.leetcode;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * ClassName: P22
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/30 17:31
 * @Version: 1.0
 */
public class P22 {

	char[] arr = new char[18];
	List<String> ret = new ArrayList<String>();

	@Test
	public void test(){
		List<String> strings = generateParenthesis(3);
		strings.forEach(System.out::println);
	}

	public List<String> generateParenthesis(int n) {
		dfs(0, 0, 0, n);
		return ret;
	}

	public void dfs(int loc, int l, int r, int n){
		if(loc >= n - 1 && l >= n){
			while(loc <= 2 * n - 1){
				arr[loc] = ')';
				loc++;
			}
			arr[loc] = '\0';
			ret.add(String.copyValueOf(arr, 0, 2 * n));
			return;
		}
		if(l > r){
			arr[loc] = ')';
			dfs(loc + 1, l, r + 1, n);
		}
		arr[loc] = '(';
		dfs(loc + 1, l + 1, r, n);
	}
}
