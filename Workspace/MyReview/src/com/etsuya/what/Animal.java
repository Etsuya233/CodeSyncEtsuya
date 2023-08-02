package com.etsuya.what;

public class Animal {
	public static void main(String[] args) {
		Earth a = new Earth();
		Planet p = a;
	}
}

class Planet{
	String name;

}

class Earth extends Planet{
	int speed = 2;

	public void say(){
		System.out.println("heyhey");
	}
}