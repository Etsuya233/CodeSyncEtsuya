package com.etsuya.java12;

import org.junit.Test;

import javax.swing.*;

/**
 * ClassName: Fucking
 * Package: com.etsuya.java12
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/6/28 16:20
 * @Version: 1.0
 */
public class Fucking {
	public static void main(String[] args) {
		new Cat("Tom");


	}

	public final void eat(){

	}

	@Test
	public void test(){
	    String a = "012345678";
		System.out.println(a.substring(1, 4));

		StringBuilder sb = new StringBuilder("01234567");
		System.out.println(sb.substring(1, 4));


	}
}

class Animal{
	String name;

	public Animal(String name) {
		this.name = name;
		System.out.println("Animal:" + name);

	}
}

class Head{
	public Head() {
		System.out.println("Head");
	}
}

class Cat{
	Head head = new Head();

	public Cat(String name) {
//		super(name);
		System.out.println("Cat");
	}
}

interface a{

}

interface b{

}

interface c{

}

interface d extends a, b, c{

}