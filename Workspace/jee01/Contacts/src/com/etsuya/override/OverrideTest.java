package com.etsuya.override;

import com.etsuya.myUtil.*;

public class OverrideTest {
	public static void main(String[] args) {
//		Person yLP = new Person();
//		Dog lWX = new Dog();
//		yLP.test();
//		System.out.println("*******");
//		lWX.test();
		OverLA overLaTest = new OverLA();
		overLaTest.speed = 12;
		quickSortTest.main(args);
		
	}
}

class Person{
	int age;
	
	public Person(){
		
	}
	
	private void say() {
		System.out.println("nmslma?");
	}
	
	public void test() {
		say();
		state();
	}
	
	public void state() {
		System.out.println("我是人啊你妈的的");
	}
}


class Dog extends Person{
	public Dog() {
		
	}
	
	public void say() {
		System.out.println("nimeiyoumama");
	}
	
	public void state() {
		System.out.println("你妈的你是狗吧");
	}
	
	public void test() {
		say();
		state();
	}

}
