package com.etsuya.stackandqueue;

import org.junit.Test;

import java.util.Stack;

/**
 * ClassName: P232
 * Package: com.etsuya.stackandqueue
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/16 12:55
 * @Version: 1.0
 */
public class P232 {
	@Test
	public void test(){
		MyQueue obj = new MyQueue();
		obj.push(2);
		int param_2 = obj.pop();
		int param_3 = obj.peek();
		boolean param_4 = obj.empty();
	}

	class MyQueue {
		Stack<Integer> a = new Stack<>();
		Stack<Integer> b = new Stack<>();

		public MyQueue() {

		}

		public void push(int x) {
			a.push(x);
		}

		public int pop() {
			if(b.empty()){
				while(!a.empty()){
					b.push(a.peek());
					a.pop();
				}
			}
			return b.pop();
		}

		public int peek() {
			if(b.empty()){
				while(!a.empty()){
					b.push(a.peek());
					a.pop();
				}
			}
			return b.peek();
		}

		public boolean empty() {
			return a.empty() && b.empty();
		}
	}
}
