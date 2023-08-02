package com.etsuya.prac;

import java.util.Arrays;

public class NullPointerTest {
		public static void main(String[] args) {
			int[] arr = new int[] {1,2,44,33,22,12};
			System.out.println(Arrays.toString(arr));
			Arrays.sort(arr);
			System.out.println(Arrays.toString(arr));
		}
}