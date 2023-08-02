package com.etsuya.prac;

import java.util.Scanner;

public class ArrayTest {
		public static void main(String[] args) {
			Scanner scan = new Scanner(System.in);
			int[] arr = new int[] {1,2,3,4,5,66,777,888,97765,12141413,22342242,33333333};
			System.out.print("Please enter the number you want to find:");
			int target = scan.nextInt();
			int head = 0;
			int end = arr.length - 1;
			while(head <= end) {
				int middle = (head + end)/2;
				if(target == arr[middle]) {
					System.out.println(middle);
					break;
				}else if(target > arr[middle]) {
					head = middle + 1;
				}else if(target < arr[middle]) {
					end = middle - 1;
				}
			}
			
		}
}
