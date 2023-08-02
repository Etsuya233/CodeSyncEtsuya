package com.etsuya.experiment5;

/**
 * ClassName: MyStackTest
 * Package: com.etsuya.experiment5
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/5/12 14:13
 * @Version: 1.0
 */
public class MyStackTest {
	public static void main(String[] args) {
		MyStack<Character> myStack = new MyStack<>();
		System.out.println(4 == 3);
		//测试push(E e)，pop()，isEmpty()方法
		myStack.push('a');
		myStack.push('b');
		myStack.push('c');
		System.out.println(myStack.peek());
		while(!myStack.isEmpty()){
			System.out.println(myStack.pop());
		}
		//测试reverse(String string)方法
		System.out.println(MyStack.reverse("what are you talking about?"));

	}
}
