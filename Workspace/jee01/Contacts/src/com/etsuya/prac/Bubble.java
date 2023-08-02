package com.etsuya.prac;

public class Bubble {
	public static void main(String[] args) {

		int[] arr = new int[] { 231, 13413, 34131, 12341, 12315545, 12311, 1234123, 123, 234, 2211213, 123134, 12112,
				1111, 33 };

		// 方法一：
		for (int i = 0; i < arr.length - 1; i++) {
			for (int j = 0; j < arr.length - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}

		// 方法二：
		while (true) {
			boolean noWarpedFlag = true;
			for (int cnt = 0; cnt < arr.length - 1; cnt++) {
				if (arr[cnt] > arr[cnt + 1]) {
					int temp = arr[cnt];
					arr[cnt] = arr[cnt + 1];
					arr[cnt + 1] = temp;
					noWarpedFlag = false;
				}
			}
			if (noWarpedFlag)
				break;
		}

		// traverse
		for (int cnt = 0; cnt < arr.length; cnt++) {
			System.out.println(arr[cnt]);
		}

	}
}
