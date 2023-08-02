package com.etsuya.leetcode;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * ClassName: P17
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/26 16:46
 * @Version: 1.0
 */
public class P17 {
	@Test
	public void test(){
		List<String> list = letterCombinations("");
		list.forEach(str -> System.out.println(str));
	}


	int walked[] = new int[4];
	char[][] alphabet = {
			{},{},
			{'a', 'b', 'c'},
			{'d', 'e', 'f'},
			{'g', 'h', 'i'},
			{'j', 'k', 'l'},
			{'m', 'n', 'o'},
			{'p', 'q', 'r', 's'},
			{'t', 'u', 'v'},
			{'w', 'x', 'y', 'z'}
	};
	public List<String> letterCombinations(String digits) {
		ArrayList<String> list = new ArrayList<>();
		if(digits.equals("")) return list;
		int maxDigit = digits.length();
		getStr(digits, 0, maxDigit - 1, list);
		return list;
	}
	public void getStr(String digits, int depth, int maxDepth, ArrayList<String> list){
		if(depth == maxDepth){
			for(int i = 0; i < alphabet[digits.charAt(depth) - '0'].length; i++){
				walked[depth] = alphabet[digits.charAt(depth) - '0'][i];
				list.add(new String(walked, 0, maxDepth + 1));
			}
		} else {
			for(int i = 0; i < alphabet[digits.charAt(depth) - '0'].length; i++){
				walked[depth] = alphabet[digits.charAt(depth) - '0'][i];
				getStr(digits, depth + 1, maxDepth, list);
			}
		}
	}
}
