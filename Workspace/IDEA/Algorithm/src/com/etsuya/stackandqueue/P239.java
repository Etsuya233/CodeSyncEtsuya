package com.etsuya.stackandqueue;

import org.junit.Test;

import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;

/**
 * ClassName: P239
 * Package: com.etsuya.stackandqueue
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/16 13:17
 * @Version: 1.0
 */
public class P239 {
	@Test
	public void test1(){
		int[] ints = maxSlidingWindow(new int[]{1, 3, -1, -3, 5, 3, 6, 7}, 3);
		for(int a: ints){
			System.out.print(a + " ");
		}
	}
	class MyQueue {
		LinkedList<Integer> deque = new LinkedList<>();
		void poll(int val) {
			if (!deque.isEmpty() && val == deque.peek()) {
				deque.poll();
			}
		}
		int peek() {
			return deque.peek();
		}
		void add(int val) {
			while (!deque.isEmpty() && val > deque.getLast()) {
				deque.removeLast();
			}
			deque.add(val);
		}
	}
	public int[] maxSlidingWindow(int[] nums, int k) {
		int len = nums.length, last;
		int[] ret = new int[len - k + 1];
		MyQueue my = new MyQueue();

		for(int i = 0; i < k; i++){
			my.add(nums[i]);
		}
		ret[0] = my.peek();
		last = nums[0];
		for(int i = 1; i < len - k + 1; i++){
			my.poll(last);
			my.add(nums[i + k - 1]);
			ret[i] = my.peek();
		}
		return ret;
	}

}
