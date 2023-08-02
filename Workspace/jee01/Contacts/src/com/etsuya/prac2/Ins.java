package com.etsuya.prac2;

public class Ins {
	public static void main(String[] args) {
		Ins test = new Ins();
		test.method(new Student());
	}

	public void method(Person e) {
		System.out.println(e.getInfo());
		
		if(e instanceof Graduate) System.out.println("Graduated");
		if(e instanceof Student) System.out.println("Student");
		if(e instanceof Person) System.out.println("Person");
	}
}

class Person {
	protected String name = "person";
	protected int age = 50;

	public String getInfo() {
		return "Name: " + name + "\n" + "age: " + age;
	}
}

class Student extends Person {
	protected String school = "pku";

	public String getInfo() {
		return "Name: " + name + "\nage: " + age + "\nschool: " + school;
	}
}

class Graduate extends Student {
	public String major = "IT";

	public String getInfo() {
		return "Name: " + name + "\nage: " + age + "\nschool: " + school + "\nmajor:" + major;
	}
}