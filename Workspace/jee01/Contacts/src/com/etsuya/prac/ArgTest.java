package com.etsuya.prac;

import java.util.Arrays;

public class ArgTest {
	public static void main(String[] args) {
		int[] arr = new int[] {1,2,4,3,5,66};
		System.out.println(Arrays.toString(arr));
		
	}
	public void prt(int ... args) {
		for(int i = 0; i < args.length; i++) {
			System.out.println(args[i]);
		}
	}
}
