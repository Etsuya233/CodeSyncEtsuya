package com.etsuya.java11;

/**
 * ClassName: Test
 * Package: com.etsuya.java11
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/6/13 15:08
 * @Version: 1.0
 */
public class Test {
	public static void main(String[] args) {
		Father father = new Son();
		father.say();
		Son.fuck();
		new Son().birth();
		try {
			father.usePlaneCup();
		} catch (MyException e) {
			e.printStackTrace();
		}
	}

}
