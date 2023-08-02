package com.etsuya.supertest;

public class Student extends Person{
	String major;
	
//	public Student() {
//		
//	}
	public Student(String name, int age, String major) {
		this.major = major;
	}
	
	public Student(String name) {
		
	}
	
	
	public void eat() {
		System.out.print("student are eating and ");
		super.eat();
	}
}
