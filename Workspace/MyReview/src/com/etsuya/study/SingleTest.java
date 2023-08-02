package com.etsuya.study;

public class SingleTest {
	public static void main(String[] args) {
		Person a = new Person("NISM", 12);
		System.out.println(a.toString());

	}
}

class Person{
	String name;
	int age;
	static String desc = "I'm a human";

	public Person(){

	}

	{
		System.out.println("Wow! Thank you for new me.");
	}

	public Person(String name, int age){
		this.name = name;
		this.age = age;
	}

	@Override
	public String toString() {
		return "Person{" +
				"name='" + name + '\'' +
				", age=" + age +
				'}';
	}
}