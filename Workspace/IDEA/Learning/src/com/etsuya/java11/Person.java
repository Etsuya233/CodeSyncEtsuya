package com.etsuya.java11;

/**
 * ClassName: Person
 * Package: com.etsuya.java11
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/6/13 15:37
 * @Version: 1.0
 */
public interface Person extends Animal{


	public default void life(){
		System.out.println("life is hard");
	}

	public static void fuckLife(){
		System.out.println("its normal fu");
	}

	private void what(){
		System.out.println("its private");
	}
}
