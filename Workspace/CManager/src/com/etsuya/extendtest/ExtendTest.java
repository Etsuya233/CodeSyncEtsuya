package com.etsuya.extendtest;

public class ExtendTest {
	public static void main(String[] args) {
		Kids someKids = new Kids();

		someKids.manOrWoman();
		someKids.employed();
	}
}

class Person{
	String name;
	char sex;
	int age;

	public Person(){

	}

	public Person(String name, char sex, int age){
		this.name = name;
		this.sex = sex;
		this.age = age;
	}

	public String toString(){
		String ret = "Name: " + name + ", Sex: " + sex + ", Age: " + age;
		return ret;
	}
}

class Student extends Person{
	long number;
	int math;
	int english;
	int computer;

	public Student(String n, char s, int a, long k, int m, int e, int c){
		name = n;
		sex = s;
		age = a;
		number = k;
		math = m;
		english = e;
		computer = c;
	}

	public double aver(){
		return (math + english + computer) * 1.0 / 3;
	}


}

class ManKind{
	int sex;
	int salary;

	public ManKind(){

	}
	public ManKind(int sex, int salary){
		this.salary = salary;
		this.sex = sex;
	}

	void manOrWoman(){
		if(sex == 1) System.out.println("He has a dick.");
		else System.out.println("She has a vagina.");
	}

	void employed(){
		if(salary == 0) System.out.println("I fucked my boss.");
		else System.out.println("I have a job");
	}
}

class Kids extends ManKind{
	int yearsOld;

	void printAge(){
		System.out.println("My age is " + yearsOld);
	}
}

class Circle{
	private double radius;

	public Circle(){
		radius = 1;
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}

	public double findArea(){
		return 3.14 * radius * radius;
	}
}

class Cylinder extends Circle{
	private double length;

	public Cylinder(){
		length = 1;
	}

	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		this.length = length;
	}

	public double findVolume(){
		return findArea() * length;
	}
}
