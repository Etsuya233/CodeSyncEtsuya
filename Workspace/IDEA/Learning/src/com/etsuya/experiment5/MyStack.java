package com.etsuya.experiment5;

import java.util.ArrayList;

/**
 * ClassName: MyStack
 * Package: com.etsuya.experiment5
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/5/12 14:05
 * @Version: 1.0
 */

public class MyStack<E> {
	private ArrayList<E> list = new ArrayList<>();

	public boolean isEmpty(){
		return list.size() == 0;
	}

	public void push(E e){
		list.add(e);
	}

	public E pop(){
		if(list.size() == 0) return null;
		E ret = list.get(list.size() - 1);
		list.remove(list.size() - 1);
		return ret;
	}

	public E peek(){
		if(list.size() == 0) return null;
		return list.get(list.size() - 1);
	}

	public void show(){
		for(E e: list){
			System.out.println(e + " ");
		}
		System.out.println();
	}

	public static String reverse(String string){
		MyStack<Character> temp = new MyStack<Character>();
		char[] charArray = string.toCharArray();
		for(int i = 0; i < charArray.length; i++){
			temp.push(charArray[i]);
		}
		for(int i = 0; i < charArray.length; i++){
			charArray[i] = temp.pop();
		}
		return String.copyValueOf(charArray);
	}
}
