package com.etsuya.leetcode;

import org.junit.Test;

/**
 * ClassName: P4
 * Package: com.etsuya.leetcode
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/9 14:40
 * @Version: 1.0
 */
public class P4{
	@Test
	public void test(){
		int[] nums1 = new int[]{1, 1};
		int[] nums2 = new int[]{1, 1, 2};
		System.out.println(findMedianSortedArrays(nums1, nums2));
	}

	public double findMedianSortedArrays(int[] nums1, int[] nums2) {
		int[] arr = newArrays(nums1, nums2);
		int middle = arr.length / 2;
		if(arr.length % 2 == 1){
			return arr[middle];
		} else {
			return (double)(arr[middle] + arr[middle - 1]) / 2;
		}
	}

	public int[] newArrays(int[] a, int[] b){
		int p1 = 0, p2 = 0, p = 0;
		int[] ret = new int[a.length + b.length];
		while(p1 < a.length && p2 < b.length){
			if(a[p1] < b[p2]){
				ret[p++] = a[p1++];
			} else {
				ret[p++] = b[p2++];
			}
		}
		while(p1 < a.length){
			ret[p++] = a[p1++];
		}
		while (p2 < b.length){
			ret[p++] = b[p2++];
		}
		return ret;
	}
}