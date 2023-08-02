package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P8
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/19 10:26
 * @Version: 1.0
 */
public class P8 {
	@Test
	public void test(){
		String s = "   -000123";
		System.out.println(myAtoi(s));
	}
	public int myAtoi(String s) {
		int p = 0, len = s.length();
		boolean isPositive = true;
		while(p < len){
			if(s.charAt(p) == '-'){
				p++;
				isPositive = false;
				break;
			} else if(s.charAt(p) == '+'){
				p++;
				break;
			} else if(s.charAt(p) == ' '){
			} else if(s.charAt(p) >= '0' && s.charAt(p) <= '9'){
				break;
			} else return 0;
			p++;
		}

		while(p < len){
			if(s.charAt(p) == '0'){
				p++;
			} else if(s.charAt(p) >= '0' && s.charAt(p) <= '9') break;
			else return 0;
		}

		int ret = 0, ans;
		boolean valid = true;
		while(p < len){
			if(s.charAt(p) >= '0' && s.charAt(p) <= '9') {
				ret = (ans = ret) * 10 + (s.charAt(p) - '0');
				if(ret / 10 != ans) valid = false;
			} else break;
			p++;
		}

		if(valid){
			return (isPositive)? ret: -ret;
		} else {
			if(isPositive) return 0x7fffffff;
			else return - 0x7fffffff - 1;
		}
	}
}
