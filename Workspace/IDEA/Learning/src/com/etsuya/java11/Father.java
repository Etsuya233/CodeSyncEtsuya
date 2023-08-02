package com.etsuya.java11;

/**
 * ClassName: Father
 * Package: com.etsuya.java11
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/6/13 15:07
 * @Version: 1.0
 */
public class Father implements Person {
	String name = "Father";
	final int height = 17;

	public void say(){
		System.out.println(name);
	}

	public static void fuck(){
		System.out.println("fuck");
	}

	@Override
	public void birth() {

	}

	@Override
	public void death() {

	}

	public void usePlaneCup() throws MyException {
		throw new MyException("Dont use that let me help u");
	}
}
