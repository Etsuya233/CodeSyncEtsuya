package com.etsuya.overridetest;

public class Test {
	public static void main(String[] args) {
		
	}
}

class Person{
	String name;
	int age;
	
	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
}

class Student extends Person{
	int score;
//	public Student(String name, int age) {
//		super(name, age);
//		
//	}
	
	public Student(String name, int age, int score) {
		super(name, age);
		this.score = score;
	
//	public Student(String name, int age, int score) {
//		super(name, age);
//		this.score = score;
	}
	
}
