package com.etsuya.study;

public class ConstructorTest {
	public static void main(String[] args) {
		TriAngle tri1 = new TriAngle(5,2);
		tri1.setBase(10);
		System.out.println(tri1.getBase());


	}
}

class ConstructorT{
	String name;

	public ConstructorT(String nameSet){
		name = nameSet;
	}

	public void nameShow(){
		System.out.println(name);
	}

}

class Boy{
	private String name;
	private int age;

	public void setAge(int age){
		this.age = age;
	}

	public int getAge(){
		return age;
	}

	public void setName(String name){
		this.name = name;
	}

	public String getName(){
		return name;
	}

	public void marry(Girl girl){
		System.out.println("I've married with " + girl.getName());
	}

	public void shout(){
		System.out.println("Fuck u little bitch");
	}
}

class Girl{
	private String name;
	private int age;

	public void setAge(int age){
		this.age = age;
	}

	public int getAge(){
		return age;
	}

	public void setName(String name){
		this.name = name;
	}

	public String getName(){
		return name;
	}

}

class Bank{
}


