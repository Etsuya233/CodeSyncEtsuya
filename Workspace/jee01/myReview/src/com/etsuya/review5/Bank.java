package com.etsuya.review5;

public class Bank {
	public static int factorial(int n) {
		int ans = 1;
		for(int i = 1; i <= n; i++) ans *= i;
		return ans;
	}
}