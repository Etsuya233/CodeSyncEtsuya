package com.etsuya.supertest;

public class Person {
	public static void main(String[] args) {
		
	}
	
	String name;
	int age;
	
	public Person() {
		System.out.println("I am here!!");
	}
	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	public void eat() {
		System.out.println("people are eating");
	}
	public void sleep() {
		System.out.println("people are sleeping");
	}
}
