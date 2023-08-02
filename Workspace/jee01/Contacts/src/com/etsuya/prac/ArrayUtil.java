package com.etsuya.prac;

public class ArrayUtil {
	/**
	 * @Description 获取整形数组的总和。
	 * @author Etsuya
	 * @date 2022年9月9日下午3:30:09
	 * @param arr 数组变量
	 * @return int 型的总和
	 */
	public int getSum(int[] arr) {
		int sum = 0;
		for(int i = 0; i < arr.length; i++) {
			sum += arr[i];
		}
		return sum;
	}
	
	public int getAverage(int[] arr) {
		int ave;
		ave = getSum(arr) / arr.length;
		return ave;
	}
	
	public int getMax(int[] arr) {
		int max = arr[0];
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] > max) max = arr[i];
		}
		return max;
	}
	
	
}


