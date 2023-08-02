package com.etsuya.experiment4;

import java.util.Random;

public class NumberSort {
	public static void main(String[] args) {
		Random random = new Random();
		int[] a = new int[10];
		int[] sorted = new int[10];
		for(int i = 0; i < 10; i++) {
			a[i] = random.nextInt(200) - 100;
			sorted[i] = Math.abs(a[i]);
		}
		for(int i = 0; i < 9; i++){
			int j, min = sorted[i], minLoc = i;
			for(j = i + 1; j < 10; j++){
				if(sorted[j] < min){
					min = sorted[j];
					minLoc = j;
				}
			}
			int temp = sorted[i];
			sorted[i] = sorted[minLoc];
			sorted[minLoc] = temp;
		}
		for(int i = 0; i < 9; i++){
			System.out.print(a[i] + ",");
		}
		System.out.println(a[9] + ".");
		for(int i = 0; i < 9; i++){
			System.out.print(sorted[i] + ",");
		}
		System.out.println(sorted[9] + ".");
	}
}
