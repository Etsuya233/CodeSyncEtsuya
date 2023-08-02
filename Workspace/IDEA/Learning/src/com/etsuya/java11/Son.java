package com.etsuya.java11;

/**
 * ClassName: Son
 * Package: com.etsuya.java11
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/6/13 15:07
 * @Version: 1.0
 */
public class Son extends Father{
	String name = "Son";

	public Son() {
	}

	public void say(){
		System.out.println(name);
	}

	public static void fuck(){
		System.out.println("be fucked");
	}
}
