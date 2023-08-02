package com.etsuya.test;

import java.util.Arrays;

public class PersonTest {
	public static void main(String[] args) {
		Student stu = new Student();
		stu.eat();
		
		
	}
	
	
	public void beautifulPrint() {
		System.out.println("Hey!");
	}
}

class Student{
	int height;
	int weight;
	String name;
	
	public void eat(){
		System.out.println("eat");
		drink();
	}
	
	public void drink() {
		System.out.println("Drink");
	}
}