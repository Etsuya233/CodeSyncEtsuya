package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P6
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/12 15:00
 * @Version: 1.0
 */
public class P6 {
	@Test
	public void test(){
		System.out.println(convert("A", 2));
	}
	public String convert(String s, int numRows) {
		if(numRows == 1) return s;
		StringBuilder stringBuilder = new StringBuilder();
		int interval = (numRows - 1) * 2, a, b, loc, len = s.length();
		for(int i = 0; i < numRows && i < len; i++){
			loc = i;
			a = interval - i * 2;
			b = interval - a;
			stringBuilder.append(s.charAt(loc));
			while(true){
				if(a > 0){
					if((loc += a) < len) stringBuilder.append(s.charAt(loc));
					else break;
				}
				if(b > 0){
					if((loc += b) < len) stringBuilder.append(s.charAt(loc));
					else break;
				}
			}
		}
		return stringBuilder.toString();
	}
}
