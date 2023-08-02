package com.etsuya.study;

import java.util.Arrays;

public class QuickSortTest {
	public static void main(String[] args) {
		int[] arr = new int[]{5,4,77,55,43,22,22,11,44,55,97,54,2};
		quickSort(arr, 0, arr.length - 1);
		System.out.println(Arrays.toString(arr));
		System.out.println(binarySearchLazer(arr, 44, 0, arr.length - 1));
	}

	public static void quickSortAbandoned(int[] arr, int head, int end){
		int left = head, right = end;

		if(right < 0) return;
		if(left > arr.length - 1) return;
		if(left > right) return;

		int pivot = arr[head];
		if(left != right){
			int times = 2;
			while(left != right){

				if(times % 2 == 0){
					if(arr[right] < pivot){
						arr[left] = arr[right];
						times++;
					}else{
						right--;
					}
				}else{
					if(arr[left] > pivot){
						arr[right] = arr[left];
						times++;
					}else{
						left++;
					}
				}

			}
			arr[left] = pivot;

			quickSortAbandoned(arr, head, left-1);
			quickSortAbandoned(arr, left+1, end);
		}
	}

	public static void quickSort(int[] arr, int head, int end){
		if(head < end) {
			int left = head, right = end;
			int pivot = arr[left];

			while (left < right) {
				while (left < right && arr[right] >= pivot) { //I changed the > into >=
					right--;
				}
				if (left < right) {
					arr[left++] = arr[right];
				}
				while (left < right && arr[left] <= pivot) {
					left++;
				}
				if (left < right) {
					arr[right--] = arr[left];
				}
			}
			arr[left] = pivot;

			quickSort(arr, head, left - 1);
			quickSort(arr, left + 1, end);
		}
	}

	public static int binarySearch(int[] arr, int number){
		int location = -1;
		int head = 0, end = arr.length - 1;
		if(head < end){
			int half = arr.length / 2;
			if(arr[half] == number) {
				return half;
			}else{
				if(number < arr[half]){
					return binarySearchPart(arr, number, head, half - 1);
				}else{
					return binarySearchPart(arr, number, half + 1, end);
				}
			}
		}
		return location;
	}

	private static int binarySearchPart(int[] arr, int number, int head, int end){
		if(head < end){
			int half = (end + head) / 2;
			if(arr[half] == number){
				return half;
			}

			if(number < arr[half]){
				return binarySearchPart(arr, number, head, half - 1);
			}else{
				return binarySearchPart(arr, number, half + 1, end);
			}
		}
		return -1;
	}

	public static int binarySearchLazer(int[] arr, int number, int head, int end){
		if(head > end) return -1;
		int half = (head + end) / 2;
		if(arr[half] < number) return binarySearchLazer(arr, number, half + 1, end);
		if(arr[half] > number) return binarySearchLazer(arr, number, head, half - 1);
		return half;
	}
}

