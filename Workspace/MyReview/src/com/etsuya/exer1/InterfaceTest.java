package com.etsuya.exer1;

public class InterfaceTest {
}

class Bird implements Flyable, Walkable{
	String name;

	@Override
	public void fly() {

	}

	@Override
	public void walk() {

	}

	@Override
	public void stop() {

	}
}

interface Flyable{
	int MIN_SPEED = 0, MAX_SPEED = 7900;

	void fly();
	void stop();
}

interface Walkable{
	int MIN_SPEED = 0, MAX_SPEED = 10000;

	void walk();
	void stop();
}