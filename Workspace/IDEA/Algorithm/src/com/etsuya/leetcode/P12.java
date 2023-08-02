package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P12
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/23 18:56
 * @Version: 1.0
 */
public class P12 {
	@Test
	public void test(){
		System.out.println(intToRoman(1994));
	}
	public String intToRoman(int num) {
		StringBuilder stringBuilder = new StringBuilder();
		while(num - 1000 >= 0){
			stringBuilder.append('M');
			num -= 1000;
		}
		while(num - 900 >= 0){
			stringBuilder.append("CM");
			num -= 900;
		}
		while(num - 500 >= 0){
			stringBuilder.append('D');
			num -= 500;
		}
		while(num - 400 >= 0){
			stringBuilder.append("CD");
			num -= 400;
		}
		while(num - 100 >= 0){
			stringBuilder.append('C');
			num -= 100;
		}
		while(num - 90 >= 0){
			stringBuilder.append("XC");
			num -= 90;
		}
		while(num - 50 >= 0){
			stringBuilder.append('L');
			num -= 50;
		}
		while(num - 40 >= 0){
			stringBuilder.append("XL");
			num -= 40;
		}
		while(num - 10 >= 0){
			stringBuilder.append('X');
			num -= 10;
		}
		while(num - 9 >= 0){
			stringBuilder.append("IX");
			num -= 9;
		}
		while(num - 5 >= 0){
			stringBuilder.append('V');
			num -= 5;
		}
		while(num - 4 >= 0){
			stringBuilder.append("IV");
			num -= 4;
		}
		while(num - 1 >= 0){
			stringBuilder.append('I');
			num -= 1;
		}
		return stringBuilder.toString();
	}
}
