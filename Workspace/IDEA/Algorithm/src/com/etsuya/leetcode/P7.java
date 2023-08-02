package com.etsuya.leetcode;

import org.junit.jupiter.api.Test;

/**
 * ClassName: P7
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/16 16:08
 * @Version: 1.0
 */
public class P7 {
	@Test
	public void test(){
		int a = 1534236469;
		System.out.println(reverse(a));
	}
	public int reverse(int x) {
		int num = x, newNum = 0;
		boolean isMinus = false;
		if(num < 0) {
			isMinus = true;
			num = -num;
		}
		while(num > 0){
			int judge = num % 10;
			if(judge != 0) break;
			else num /= 10;
		}
		boolean can = true;
		while(num > 0){
			int temp = newNum;
			newNum = 10 * newNum + num % 10;
			if(newNum / 10 != temp) can = false;
			num /= 10;
		}
		if(can){
			return (isMinus)? -newNum : newNum;
		} else return 0;
	}
}
