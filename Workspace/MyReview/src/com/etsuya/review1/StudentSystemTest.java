package com.etsuya.review1;

import java.util.Arrays;
import java.util.StringJoiner;

public class StudentSystemTest {
	public static void main(String[] args) {
		int[] arr = {1, 44, 22, 55, 33};
		StringJoiner sj = new StringJoiner(", ", " [ ", "]");
		for(int i = 0; i < 5; i++) sj.add(arr[i] + "");
		System.out.println(sj.toString());

	}
}
